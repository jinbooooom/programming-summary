## 泛型编程风格

### 用实例理解泛型编程

**需求：**

一个存储整数的 vector，和一个整数，如果此整数存在于 vector 内，返回一个指向该向该整数的指针；反之返回 0。

```C++
int* find(const vector<int> &vec, int value) {
    for (int ix = 0; ix < vec.size(); ++ix)
        if (vec[ix] == value)
            return &vec[ix];
    return 0;
}
```

**需求：**

希望这个函数不仅可以处理整数，更可以处理任何类型——前提是该类型有 **equality(相等)** 运算符。

```C++
template <typename elemType>
elemType* find(const vector<elemType> &vec, 
               const elemType &value) {
    for (int ix = 0; ix < vec.size(); ++ix)
        if (vec[ix] == value)
            return &vec[ix];
    return 0;
}
```

**需求：**

希望这个函数可以同时处理 vector 和 array。

因为 vector 和 array 都是顺序性容器，且都是在一块连续内存存储其所有元素，那么指针的算术运算（自增操作）是有意义的。我们可以传入一个首指针 first 和一个判断结束的指针 last，将两指针间的元素与 value 比较。

```C++
template <typename elemType>
elemType* find(const elemType *first, 
               const elemType *last, 
               const elemType &value) {
    if (!first || !last)
        return 0;
    for (; first != last; ++first)
        if (*first == value)
            return first
    return 0;
}
```

上述代码的调用，略显麻烦，还有一些问题：

```C++
vector<string> svec; //定义一个空的 vector
find(&svec[0], &svec[svec.size()], search_value); 
/*
vector 为空，此处代码报错,
比较保险的方法是先判断 svec 是否为空，
非空再调用 find()
*/
```

使其更鲁棒：

```C++
template <typename elemType>
inline elemType* begin(const vector<elemType> &vec) {
	return vec.empty() ? 0 : &vec[0];
}
//end() 函数同理
```

此时就可以这样调用 find()

```C++
find(begin(svec), end(svec), search_value);
```

**需求：**

希望 find() 能支持 list 类型。

因为指针的算术运算首先假设所有元素都存储在连续空间里，然后才根据当前的指针，加上元素大小，指向下一个元素。这是先前 find() 实现里的最基本的假设。而 list 打破了这个假设。

解决办法是在底层指针的行为之上提供一层抽象，取代程序原本的“指针直接操作”方式。

```C++
// find() 支持指针和一对指向某容器的 iterator
template <typename IteratorType, typename elemType>
IteratorType find(IteratorType first, 
                  IteratorType last,
                  const elemType &value) {
	for (; first != last; ++first)
        if (*first == value)
            return first;
    return last;
}
// 调用该函数
list<int> ilist(iarr, iarr + size);//iarr 是数组，size：数组大小
list<int>::iterator iter;
iter = find(ilist.begin(), ilist.end(), 1024);
if (iter != ilist.end()) {
    do something;
}
```

有必要注意对于 const 容器，要用 const_iterator：

```C++
cosnt vector<string> cs_vec;
vector<string>::cosnt_iterator iter = cs_vec.begin();
```
【ESC 67-75】

### decltype 和 std::declval

`decltype`是C++11中引入的一个关键字，用于获取表达式或变量的类型。它的语法形式为`decltype(expression)`，其中`expression`是一个合法的C++表达式。

`std::declval`是一个模板函数，定义在`<utility>`头文件中，用于产生一种临时的、可以作为右值使用的引用。它的主要用途是在不可复制或不可移动的类型上进行声明类型推导。通常与`decltype`结合使用。

```c++
#include <iostream>
#include <utility>

struct Foo {
    int x;
    double y;
};

int main() {
    decltype(Foo().x) a;  // a的类型为int
    decltype(std::declval<Foo>().y) b;  // b的类型为double

    std::cout << typeid(a).name() << std::endl;  // 打印int的类型名
    std::cout << typeid(b).name() << std::endl;  // 打印double的类型名

    return 0;
}

```

在上述示例中，我们使用了`decltype`来推导变量`a`和`b`的类型。`decltype(Foo().x)`将返回`int`，因为`Foo().x`是一个`int`类型。而`decltype(std::declval<Foo>().y)`将返回`double`，因为`std::declval<Foo>().y`是一个`double`类型。



对`using ResultType = decltype(std::declval<FunctionType>()());` 的理解：

这行代码用于推导函数类型 `FunctionType` 的返回值类型，并将其定义为 `ResultType`。

让我们逐步解释这行代码的含义：

1. `std::declval<FunctionType>()`：`std::declval` 是一个模板函数，用于产生一个右值引用。在这里，我们使用 `std::declval` 来生成一个类型为 `FunctionType` 的临时对象（右值）。
2. `decltype(std::declval<FunctionType>())`：`decltype` 关键字会推导并返回括号中表达式的类型。在这里，我们使用 `decltype` 推导 `std::declval<FunctionType>()` 表达式的类型，即函数类型 `FunctionType`。
3. `decltype(std::declval<FunctionType>()())`：由于 `std::declval<FunctionType>()` 代表一个函数，我们通过加上额外的一对空括号 `()` 来调用该函数，并推导出调用结果的类型。
4. `using ResultType = decltype(std::declval<FunctionType>()());`：最后，使用 `using` 关键字定义别名 `ResultType` 并将 `decltype` 推导得到的函数调用结果类型赋值给它。



对`using RetType = decltype(f(args...));` 的理解：

这行代码用于推导函数调用 `f(args...)` 的返回类型，并将其定义为 `RetType`。

让我们逐步解释这行代码的含义：

1. `f(args...)`：这是一个函数调用表达式，其中 `f` 是一个函数名，`args` 是函数调用的参数。
2. `decltype(f(args...))`：`decltype` 关键字会根据括号中的表达式推导并返回其类型。在这里，我们使用 `decltype` 推导函数调用 `f(args...)` 的结果的返回类型。
3. `using RetType = decltype(f(args...));`：通过 `using` 关键字，我们定义了别名 `RetType` 并将 `decltype` 推导得到的函数调用结果类型赋值给它。

### 使用 template \<int type\> 达到和 switch case 同样的效果

当使用 `template <int type>` 进行模板定义时，以下是一个具体的代码示例：

```cpp
#include <iostream>

template <int type>
void templateFunction() {
    if (type == 0) {
        std::cout << "Type is 0." << std::endl;
    } else if (type == 1) {
        std::cout << "Type is 1." << std::endl;
    } else {
        std::cout << "Type is not recognized." << std::endl;
    }
}

int main() {
    templateFunction<0>(); // 调用 templateFunction，并传入参数 0
    templateFunction<1>(); // 调用 templateFunction，并传入参数 1
    templateFunction<2>(); // 调用 templateFunction，并传入参数 2

    return 0;
}
```

在上述示例中，`templateFunction` 是一个模板函数，它的模板参数 `type` 是一个整型。根据传入的 `type` 参数的不同值，函数将执行不同的逻辑。

在 `main` 函数中，通过使用 `<0>`、`<1>` 和 `<2>` 分别实例化了 `templateFunction` 模板函数，从而生成了三个具体的函数实例。每个实例都会根据传入的 `type` 参数值打印相应的消息。

当运行程序时，输出将如下所示：

```
Type is 0.
Type is 1.
Type is not recognized.
```

这个例子展示了模板函数根据传入的参数值在编译时生成特定的代码实例，并在运行时选择相应的逻辑。通过模板参数，可以达到类似于 `switch` 语句的效果，在不同的情况下执行不同的代码逻辑。

