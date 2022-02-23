# 一些说明

【P66】 指的是《C++并发编程实战》中文版第 66 页。

# 你好，C++ 并发世界

## 基本概念

以前，大部分计算机都只有一个处理器，具有单个处理单元和核心，这种计算机在某一时刻只可以真正执行一个任务，但它可以每秒切换任务许多次。通过做一点这个任务再做一点另一个任务，看起来像是任务在并发进行。这就是任务切换，我们仍然称这样的系统为并发(concurrency)。但这只是并发的假象。

对于多核处理器，它能真正的同时运行超过一个任务，称之为**硬件并发**（hardware concurrency）

对于单核处理器，每次执行上下文切换时，都需要时间。【P2】

## 使用并发的原因

使用并发的主要两个原因：关注点分离和性能。

- 关注点分离：将相关的代码放在一起，并将无关的代码分离，使程序易于理解和测试。如带有用户界面的密集处理型应用程序，可以将UI处理与数据处理分离。

- 性能：有两种方式为了 性能使用并发，任务并行和 数据并行。
	- 任务并行：将单个任务分成几部分且各自并行运行，从而降低总运行时间。一个线程执行算法的一部分，另一个线程执行算法的另一部分。
	- 数据并行：每个线程在不同的数据部分执行同样的操作。一个线程执行数据的一部分，另一个线程执行数据的另一部分。

【P5~8】

## 什么时候不使用并发

除非潜在的性能增益足够大和关注点分离足够清晰。

启动线程时存有固定开销，因为操作系统需要分配相关的内核资源和堆栈空间，然后将新线程加入到调度器，这一切都需要时间。

此外，线程是有限的资源。如果让太多线程同时运行，则会消耗系统资源，并且使操作系统整体上运行得更慢。每个线程需要一个独立的堆栈空间，假设是1M，每个进程的可用内存和地址空间是有限的，对一个可用空间限制为4GB扁平架构的32位操作系统而言，4096个线程将会耗尽地址空间，导致不再为代码、静态数据或者堆数据留有空间。

**试图得到系统的最佳性能，考虑可用的硬件并发并调整运行线程的数量是必须的。**【p7~8】

对于IO密集型任务：

`线程数 = CPU核心数 × （1 + IO耗时 / CPU 耗时）`

对CPU密集型任务：

`线程数 = CPU 核心数 + 1`

## std::thread

```cpp
#include <iostream>
#include <thread>

void hello()
{
    std::cout<<"Hello Concurrent World\n";
}

int main()
{
    std::thread t(hello);
    t.join();
}
```

每个程序有一个执行 main() 函数的主线程，将函数添加为 std::thread 的参数即可启动另一个线程，两个线程会同时运行。

对于应用程序来说，初始线程起于main()，但对于新线程来说，它起于hello()。【P12】

# 管理线程

## 启动线程

std::thread 的参数也可以是函数对象或者 lambda 表达式【P14~15】

```cpp
// 1.1
struct A {
  void operator()() const { std::cout << 1; }
};

int main() {
  A a;
  std::thread t1(a);  // 会调用 A 的拷贝构造函数
  std::thread t2(A());  // most vexing parse，非常棘手的解析，声明函数名为 t2， 参数类型为 A 的函数，而不是启动一个线程。
  std::thread t3{A()};  // 改成花括号，使用初始化语法，解决上述的问题
  std::thread t4((A()));	// 或者多加一层括号避免将其解释为函数声明，从而让t4被声明为一个变量而不是一个函数。
  std::thread t5{[] { std::cout << 1; }};
  t1.join();
  t3.join();
  t4.join();
  t5.join();
}
```

## 等待线程完成

在std::thread对象销毁前要对其调用 [join](https://en.cppreference.com/w/cpp/thread/thread/join) 等待线程退出或 [detach](https://en.cppreference.com/w/cpp/thread/thread/detach) 将线程分离，否则 [std::thread](https://en.cppreference.com/w/cpp/thread/thread) 的析构函数会调用 [std::terminate](https://en.cppreference.com/w/cpp/error/terminate) 终止程序。如果分离线程，那么线程可能在std::thread对象被销毁后很久都在运行，这时需要保证该线程访问的数据都是有效的，直到该线程完成为止（注意分离线程可能出现空悬引用的隐患）【P15】

```cpp
// 2.1
void do_something(int &i)
{
    ++i;
}

struct func
{
    int &i;

    func(int &i_) : i(i_) {}

    void operator()()
    {
        for (unsigned j = 0; j < 1000000; ++j)
        {
            do_something(i);
        }
    }
};

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    // 不等待线程结束，oops 执行完，就释放了局部变量 some_local_state， my_func.i 为空悬引用
    my_thread.detach(); 
}

int main()
{
    oops(); // main 函数退出了，它所拥有的线程当然也会退出。
}
```

[join](https://en.cppreference.com/w/cpp/thread/thread/join) 会在线程结束后清理 [std::thread](https://en.cppreference.com/w/cpp/thread/thread)，使其与完成的线程不再关联，因此对一个线程只能进行一次 [join](https://en.cppreference.com/w/cpp/thread/thread/join)。在join之前，应该先调用joinable()来判断是否可以join()。

```cpp
int main() {
  std::thread t([] {});
  t.join();
  t.join();  // 错误
}
```

## 在异常环境下的等待

如果线程运行过程中发生异常，之后的 [join](https://en.cppreference.com/w/cpp/thread/thread/join) 会被忽略，为此需要捕获异常，并在抛出异常前 [join](https://en.cppreference.com/w/cpp/thread/thread/join)

```cpp
// 2.2
void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try
    {
        do_something_in_current_thread();
    }
    catch (...)
    {
        t.join(); // 处理异常前先 join()
        throw;    // 再将异常抛出
    }
    t.join(); // 之前抛了异常就不会执行到该处
}
```

如果想确保访问局部变量的线程在函数退出前结束，上述代码使用try/catch块，需要在每一个可能的异常下join()，所以并不是一个理想的替代方案，我们可以实现一个可以直接用 std::thread 构造的自动清理线程的类，在它的析构函数里join()。这也是标准的资源获取即初始化（RAII）惯用语法。

```C++
// 2.3
class thread_guard
{
    std::thread &t;

public:
    explicit thread_guard(std::thread &t_) : t(t_)
    {
    }
    ~thread_guard()
    {
        if (t.joinable())
        {
            t.join();
        }
    }
    thread_guard(thread_guard const &) = delete;
    thread_guard &operator=(thread_guard const &) = delete;
};

// 2.6 的做法，效果同 2.3
class scoped_thread
{
    std::thread t;

public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_))
    {
        if (!t.joinable())
            throw std::logic_error("No thread");
    }
    ~scoped_thread()
    {
        t.join();
    }
    scoped_thread(scoped_thread const &) = delete;
    scoped_thread &operator=(scoped_thread const &) = delete;
};

struct func
{// 重载 void operator()()
};

void f()
{
    int some_local_state;
    func my_func(some_local_state);
    std::thread t(my_func);
    thread_guard g(t);

    do_something_in_current_thread();
}

int main()
{
    f();
}
```

C++20 提供了 std::jthread，它会在析构函数中对线程 join

```cpp
#include <thread>

int main() {
  std::jthread t([] {});
}
```

[detach](https://en.cppreference.com/w/cpp/thread/thread/detach) 分离线程会让线程在后台运行，一般将这种在后台运行的线程称为守护线程，守护线程与主线程无法直接交互，也不能被 [join](https://en.cppreference.com/w/cpp/thread/thread/join)。一个好的习惯是先用`joinable()`判断返回是否为true，再选择是`join()`还是`detach()`。

```cpp
std::thread t([] {});
t.detach();
assert(!t.joinable());
```

创建守护线程一般是为了长时间运行，比如有一个文档处理应用，为了同时编辑多个文档，每次新开一个文档，就可以开一个对应的守护线程

```cpp
void edit_document(const std::string& filename) {
  open_document_and_display_gui(filename);
  while (!done_editing()) {
    user_command cmd = get_user_input();
    if (cmd.type == open_new_document) {
      const std::string new_name = get_filename_from_user();
      std::thread t(edit_document, new_name);
      t.detach();
    } else {
      process_user_input(cmd);
    }
  }
}
```

## 传递参数给线程函数

传递参数给可调用对象或函数，基本是简单地将额外的参数传递给std::thread的构造函数。参数会以默认的方式被复制到内存存储空间，在那里新创建的执行线程可以访问它们，即便函数中的相应参数期待者引用。

**1.参数的默认实参会被忽略**

```cpp
#include <thread>

void f(int i = 1) { std::cout << i << std::endl; }

int main() {
  std::thread t{f, 42};  // std::thread t{f} 则会出错，因为默认实参会被忽略
  t.join();
}
// 打印 42
```

2.参数的引用类型也会被忽略，为此要使用 [std::ref](https://en.cppreference.com/w/cpp/utility/functional/ref)

```cpp
#include <cassert>
#include <thread>

void f(int& i) { ++i; }

int main() {
  int i = 1;
  std::thread t{f, std::ref(i)};
  t.join();
  assert(i == 2);
}
```

**如果对一个实例的 non-static 成员函数创建线程，第一个参数类型为成员函数指针，第二个参数类型为实例指针，后续参数为函数的参数**

```cpp
#include <iostream>
#include <thread>

class A {
 public:
  void f(int i) { std::cout << i; }
};

int main() {
  A a;
  std::thread t1{&A::f, &a, 42};  // 调用 a->f(42)
  std::thread t2{&A::f, a, 42};   // 拷贝构造 tmp_a，再调用 tmp_a.f(42)
  t1.join();
  t2.join();
}
// 在类的内部启动一个线程，线程函数是类内 non-static 成员函数，第二个参数为 this。
// mProcessTs = std::thread(&Dvr::process_ts, this);
```

如果要为参数是 move-only 类型的函数创建线程，则需要使用 [std::move](https://en.cppreference.com/w/cpp/utility/move) 传入参数

```cpp
void f(std::unique_ptr<int> p) { std::cout << *p; }

int main()
{
    std::unique_ptr<int> p = std::make_unique<int>(42);
    std::thread t{f, std::move(p)};
    t.join();
}
```

## 转移线程所有权

std::thread 是 `move-only` 类型，**不能拷贝，只能通过移动转移所有权，但不能转移所有权到 joinable 的线程**

其实看std::thread的源码就非常清楚：

```C++
// 拷贝构造函数和拷贝赋值运算符都 delete
thread(const thread&) = delete;  
thread& operator=(const thread&) = delete;

// 对于移动赋值运算符，如果之前的对象是 joinable()，就会调用std::terminate()。所以不能转移所有权到 joinable 的线程
thread& operator=(thread&& __t)
{
    if (joinable())
        std::terminate();
    swap(__t);
    return *this;
}
```

```cpp
#include <thread>
#include <utility>
#include <cassert>

void f() {}
void g() {}

int main()
{
    std::thread a{f};
    std::thread b = std::move(a);
    assert(!a.joinable()); // thread a 不是 joinable
    assert(b.joinable());  // thread b 是 joinable
    a = std::thread{g};
    assert(a.joinable());
    assert(b.joinable());
    // 错误，不能转移所有权到 joinable 的线程,a已经有了一个相关联的线程（运行着g()）），所以会调用std::terminate()来终止程序。
    // a = std::move(b); //【1】 
    a.join();
    a = std::move(b);
    assert(a.joinable());
    assert(!b.joinable());
    a.join();
}
/**
如果打开了【1】处，则打印
terminate called without an active exception
已放弃 (核心已转储)
*/
```

移动操作同样适用于支持移动的容器

```cpp
#include <algorithm>
#include <thread>
#include <vector>
#include <functional>
#include <iostream>

int main()
{
    std::vector<std::thread> v;
    for (int i = 0; i < 10; ++i)
    {
        v.emplace_back([] (int id) {std::cout << " " << id << " ";}, i);
    }
    std::for_each(std::begin(v), std::end(v), std::mem_fn(&std::thread::join));

    return 0;
}
// 打印 0  2  1  3  4  5  6  7  8  9
```

[std::thread](https://en.cppreference.com/w/cpp/thread/thread) 可以作为函数返回值

```cpp
#include <thread>

std::thread f() {
  return std::thread{[] {}};
}

int main() {
  std::thread t{f()};
  t.join();
}
```

std::thread 也可以作为函数参数。

**如果形参是值传递，调用时必须通过std::move把线程对象传入（或者是一个临时的std::thread对象）**

**如果形参是引用传递，调用时不可用std::move把线程对象传入，直接传就行了**

```cpp
#include <thread>
#include <utility>
#include <iostream>

void th(int id) { std::cout << id << std::endl; }

void f(std::thread t) { t.join(); } // 值传递

int main()
{
    f(std::thread(th, 1)); // 临时的 std::thread 对象
    std::thread t(th, 2);
    f(std::move(t)); // 调用时必须通过std::move把线程对象传入
}
```

```C++
#include <thread>
#include <utility>
#include <iostream>

void th(int id) { std::cout << id << std::endl; }

void f(std::thread &t) { t.join(); } // 引用传递

int main()
{
    //f(std::thread(th, 1)); // 出错
    std::thread t(th, 2);
    // f(std::move(t));  // 出错
    f(t);
}

/* 对于基本类型，如
void g(const int &id) { std::cout << id << std::endl; } // 加了 const
int a = 3;
g(a);
g(std::move(a)); // 如果函数 g() 形参不加 const 就会报错
*/
```

## 查看硬件支持的线程数量

* [hardware_concurrency](https://en.cppreference.com/w/cpp/thread/thread/hardware_concurrency) 会返回硬件支持的并发线程数

```cpp
#include <iostream>
#include <thread>

int main() {
  unsigned int n = std::thread::hardware_concurrency();
  std::cout << n << " concurrent threads are supported.\n";
}
// 打印 12 concurrent threads are supported.
```

## 线程号

可以通过对线程实例调用成员函数 [get_id](https://en.cppreference.com/w/cpp/thread/thread/get_id) 或在当前线程中调用 [std::this_thread::get_id](https://en.cppreference.com/w/cpp/thread/get_id) 获取 [线程号](https://en.cppreference.com/w/cpp/thread/thread/id)，其本质是一个无符号整型的封装，允许拷贝和比较，因此可以将其作为容器的键值，如果两个线程的线程号相等，则两者是同一线程或都是空线程（一般空线程的线程号为 0）

```cpp
std::thread::id master_thread_id;

void f() {
  if (std::this_thread::get_id() == master_thread_id) {
    do_master_thread_work();
  }
  do_common_work();
}
```

# 