

## C++编程基础

### Hello, world!

```cpp
#include <iostream>
#include <stdlib.h>  //使用atexit()
using namespace std;

void show1(void) {
	cout << "first exit main()" << endl;
}

void show2(void) {
	cout << "second exit main()" << endl;
}

int main(int argc, char* argv[]) {
	atexit(show1);
    atexit(show2);
	cout << "Hello, world!" << endl;

	system("pause");
	return 0;
}
/*打印
Hello, world!
second exit main()
first exit main()  
*/
```

#### main 函数前面的数据类型 int 与 void

main 函数的返回值是返回给主调进程，使主调进程得知被调用程序的运行结果。

标准规范中规定 main 函数的返回值为 int，一般约定返回 0 值时代表程序运行无错误，其它值均为错误号，但该约定并非强制。

如果程序的运行结果不需要返回给主调进程，或程序开发人员确认该状态并不重要，比如所有出错信息均在程序中有明确提示的情况下，可以不写 main 函数的返回值。在一些检查不是很严格的编译器中，比如 VC, VS 等，void 类型的 main 是允许的。不过在一些检查严格的编译器下，比如 g++, 则要求 main 函数的返回值必须为 int 型。

所以在编程时，区分程序运行结果并以 int 型返回，是一个良好的编程习惯。

#### main 函数执行完后执行其他语句

有时候需要在程序退出时做一些诸如释放资源的操作。我们可以用 atexit() 函数来注册程序正常终止时要被调用的函数。

atexit() 在一个程序中最多可以注册32个处理函数，这些处理函数的调用顺序与注册顺序相反，即后注册的函数先被调用。

有必要补充一下，main函数执行之前会做什么？**全局对象的构造函数会在main函数之前执行**。例

```C++
class C
{
public:
    C() { std::cout << "call C()" << std::endl; };
};

C c0; //全局变量

int main()
{
    std::cout << "main() start" << std::endl;
    C c1; // call C()
    return 0;
}
/**
call C()
main() start
call C()
*/
```

#### main函数之前执行的操作

main函数执行之前，主要就是初始化系统相关资源：

- 设置栈指针
- 初始化静态static变量和global全局变量，即.data段的内容
- 将未初始化部分的全局变量赋初值：数值型short，int，long等为0，bool为FALSE，指针为NULL等等，即.bss段的内容
- 全局对象初始化，在main之前调用构造函数
- 将main函数的参数argc，argv等传递给main函数，然后才真正运行main函数

#### "\n" 与 endl 的区别

在 C++ 中，终端输出换行时，用 cout<<......<<endl 与 "\n" 都可以，这是初级的认识。但二者有小小的区别，用 endl 时会刷新缓冲区，使得栈中的东西刷新一次，但用 "\n" 不会刷新，它只会换行，栈内数据没有变化。但一般情况，二者的区别是很小的，建议用 endl 来换行。  

```cpp
std::cout << std::endl;
```

相当于:

```C++
 std::cout << '\n' << std::flush;
```

或者

```cpp
std::cout << '\n'; std::fflush(stdout);
```

endl 除了写 '\n' 之外，还调用 flush 函数，刷新缓冲区，把缓冲区里的数据写入文件或屏幕。考虑效率就用 '\n'。

一般情况下，不加endl大多数情况下，也能正常输出，是因为在系统较为空闲时候，会查看缓存区的内容，如果发现新的内容，便进行输出。但是你并不清楚，系统什么时候输出，什么时候不输出，与系统自身的运行状况有关。而刷新缓存区，是强制性的，绝对性的输出，不取决于系统运行状况。所以正如《C++ Primer》书中所写，为了避免出现没有刷新输出流的情况发生，在使用打印语句来调试程序时，一定要加入 endl或 flush 操纵符。

这里可能会想到，以后遇到这类问题，干脆直接都使用 endl，不用 \n 不就好了吗？

也不是，要知道，endl会不停地刷新输出流，频繁的操作会降低程序的运行效率，这也是C++标准库对流的输入/输出操作使用缓冲区的原因。没有必要刷新输出流的时候应尽量使用 \n，比如对于无缓冲的流 cerr，就可以直接使用 \n。

#### 头文件里的 " " 与 < >

<> 默认去系统目录中找头文件。像标准的 C 头文件 stdio.h、stdlib.h 和 C++ 头文件 iostream、string 等用这个方法。
" " 首先在当前目录下寻找，如果找不到，再到系统目录中寻找。 这个用于 include 自定义的头文件，让系统优先使用当前目录中定义的。 

#### 命名空间 std

所谓名称空间它是一种将库函数封装起来的方法。通过这种方法，可以避免和应用程序发生命名冲突的问题。

如果想要使用 `cin`，`cout` 这两个 `iostream`对象，不仅要包含 `<iostream>` 头文件，还得让命名空间`std`内的名称曝光，即 `using namespace std;`

真正的开发过程中， 尽量避免使用 `using namespace std;` 等直接引入整个命名空间，否则会因为命名空间污染导致很多不必要的问题， 比如自己写的某个函数，名称正好和 std 中的一样， 编译器会不知道使用哪一个， 引起编译报错， 建议使用由命名空间组合起来的全称：
`std::cout << "Hello World" << std::endl;`

#### system("pause")

包含头文件 stdlib.h，并在主程序中加入 `system("pause");` 可以在程序运行完以后使黑框暂停显示，等待输入，而不是闪退。linux环境下运行该程序需去掉该语句。

#### cout 与 printf()

cout 流速度较慢，如果速度过慢可以用 <stdio.h> 库中的 printf() 格式化输出函数，不需要 `using namespace std;`。但注意 printf() 中不能使用 endl。printf 是函数。cout是ostream对象，和 << 配合使用。如果 printf 碰到不认识的类型就没办法了，而cout可以重载进行扩展。

***cout 不是线程安全的，printf 是线程安全的，所以多线程程序，一般都用 printf。***

#### main函数与命令行参数

一个程序的main()函数可以包括两个参数

- 第一个参数的类型为int型；
- 第二个参数为字符串数组。

通常情况下，将第一个参数命名为argc，第二个参数为argv（当然参数名字可以换）。由于字符串数组有两种表达方式，因此，main函数存在两种书写方法：

```C
int main(int argc, char* argv[])//这里使用char* argv[]

int main(int argc, char** argv)//这里使用char **argv
```

int argc：表示字符串的数量，操作系统会自动根据第二个参数传入数字，程序员不用管，只需要正确使用即可。若用户输入N个参数，那么argc= N + 1；因为 argv[0] 为程序的路径。  

char* argv[]：字符串数组，即多个字符串。为用户输入的一系列字符串，字符串之间以空格间隔，形式为：str1 str2 str3
在linux下，若存在可执行文件a.out，则运行该程序命令为：

```shell
./a.out str1 str2 str3
```

#### 预处理、编译与链接

- 预处理： 预处理也称为预编译，它为编译做准备工作，主要进行代码文本的替换，用于处理#开头的指令 。

- 编译：编译是将编译好的源程序\*.cpp文件翻译成二进制目标代码的过程。编译过程是使用C++提供的编译程序完成的，该过程会检查程序语法错误、函数变量的声明是否正确。正确的源程序文件经过编译在磁盘上生成目标文件（windows上是\*.obj，linux上是\*.o）。  
- 链接：链接将编译生成的各个目标程序模块（一个或者多个）及系统或者第三方提供的库函数\*.lib链接在一起，生成可以在操作系统上直接运行的可执行文件（windows上的\*.exe）  

安装 g++

```shell
sudo apt-get install g++ build-essential
```

将源文件hello.cpp编译成可执行文件hello

```shell
g++ hello.cpp -o hello
```

运行可执行文件

```shell
./hello
```

如果省略`-o hello`也是没问题的。由于命令行中未指定可执行程序的文件名，编译器采用默认的 a.out。程序可以这样来运行：

```shell
./a.out
```

如果是多个 C++代码文件，如f1.cpp，f2.cpp，编译命令如下：

```shell
g++ f1.cpp f2.cpp -o myexec
```

则会生成一个名为`myexec`的可执行文件。

##### 静态链接和动态链接

要生成可执行文件，必须经历两个阶段，即编译、链接。

在链接过程中，静态链接和动态链接就出现了区别。静态链接的过程就已经把要链接的内容已经链接到了生成的可执行文件中，就算你在去把静态库删除也不会影响可执行程序的执行；而动态链接这个过程却没有把内容链接进去，而是在执行的过程中，再去找要链接的内容，生成的可执行文件中并没有要链接的内容，所以当你删除动态库时，可执行程序就不能运行。所以动态链接生成的可执行文件要比静态链接生成的文件要小一些。

静态链接的优点：在程序发布的时候就不需要依赖库，也就是不再需要带着库一块发布，程序可以独立执行。且在可执行程序中已经具备了所有执行程序所需要的任何东西，在执行的时候运行速度比动态链接略微快一些。

静态链接的缺点：

1. 浪费内存空间。在多进程的操作系统下，同一时间，内存中可能存在多个相同的公共库函数。

   如果多个程序对同一个目标文件都有依赖，如多个程序中都调用了printf()函数，则这多个程序中都含有printf.o，所以同一个目标文件都在内存存在多个副本。

2. 程序的开发与发布流程受模块制约。 只要有一个模块更新，那么就需要重新编译打包整个代码。

   因为每当库函数的代码修改了，这个时候就需要重新进行编译链接形成可执行程序。

[深入浅出静态链接和动态链接](https://blog.csdn.net/kang___xi/article/details/80210717)

[【计算机基础】静态链接与动态链接](https://blog.csdn.net/weixin_44211968/article/details/124662836)

##### 动态库里分配的内存在主程序中不可以释放

动态库和主调程序既然是分别编译的，那么编译时他们必然要使用2个不同的堆。各自管理各自的。将动态库中申请到的堆内存的指针交给主调程序去释放时，主调程序的堆管理部分就会发现这个指针不合法，就失败了。

简单地说：谁负责分配，谁就负责释放！（一个模块分配的内存要在同一个模块中释放！）

### iostream

| 头文件      | 函数和描述                                                   |
| ----------- | ------------------------------------------------------------ |
| \<iostream> | 该文件定义了 cin、cout、cerr 和 clog 对象，分别对应于标准输入流、标准输出流、非缓冲标准错误流和缓冲标准错误流。 |
| \<iomanip>  | 该文件通过所谓的参数化的流操纵器（比如 setw 和 setprecision），来声明对执行标准化 I/O 有用的服务。 |
| \<fstream>  | 该文件为用户控制的文件处理声明服务。                         |

**标准输入流 cin**

```cpp
char name[50];
short age;
cout << "请输入您的名称与年龄： ";
cin >> name >> age;
//C++ 编译器根据要输入值的数据类型，选择合适的流提取运算符来提取值，并把它存储在给定的变量中。
//流提取运算符 >> 在一个语句中可以多次使用
```

**标准输出流 cout**

```cpp
char str[] = "Hello C++";
cout << "Value of str is : " << str << endl;
```

**标准错误流 cerr**

cerr 对象附属到标准错误设备，通常也是显示屏，但是 cerr 对象是非缓冲的，且每个流插入到 cerr 都会立即输出。

```cpp
char str[] = "Unable to read....";
cerr << "Error message : " << str << endl;
```

**标准日志流 clog**

clog 对象附属到标准错误设备，通常也是显示屏，但是 clog 对象是缓冲的。这意味着每个流插入到 clog 都会先存储在缓冲在，直到缓冲填满或者缓冲区刷新时才会输出。

```cpp
char str[] = "Unable to read....";
clog << "Error message : " << str << endl;
```

```cpp
#include <iostream>
using namespace std;
int main()
{
    cout << "cout" << endl;
    cerr << "cerr" << endl;
    return 0;
}
```

linux下命令行输入：

```shell
g++ main.cpp -o a
./a >> test.log
```

终端输出“cerr”，  
打开test.log，里面只有一行字符串“cout”。

- cout默认情况下是在终端显示器输出，cout流在内存中开辟了一个缓冲区，用来存放流中的数据，当向cout流插入一个endl，不论缓冲区是否满了，都立即输出流中所有数据，然后插入一个换行符。cout可以被重定向到文件。

- cerr不经过缓冲而直接输出，一般用于迅速输出出错信息，是标准错误，默认情况下被关联到标准输出流，但它不被缓冲，也就说错误消息可以直接发送到显示器，而无需等到缓冲区或者新的换行符时，才被显示。不被重定向。
  - 有时程序调用导致栈被用完了，此时如果使用cout 会导致无内存输出。使用cerr 会在任何情况下输出错误信息。
  - 不被缓冲就是你打一个字符就马上在显示器显示，而不是等到endl才打印。

- clog流也是标准错误流，作用和cerr一样，区别在于cerr不经过缓冲区，直接向显示器输出信息，而clog中的信息存放在缓冲区，缓冲区满或者遇到endl时才输出。clog用的少。

### 变量

#### 勿混用带符号类型和无符号类型

一个算术表达式中既有无符号又有有符号时，如int，那个int就会转换为无符号数

```C++
unsigned u = 10;
int i = -42;
std::cout << i + i << std::endl; // 输出-84
std::cout << u + i << std::endl; // 如果int占32位，输出4294967264
```

#### 无符号数不会小于0这一事实关系到循环的写法

【PRIMER 34】

```C++
// WRONG: u can never be less than 0; the condition will always succeed
for (unsigned u = 10; u >= 0; --u)
    std::cout << u << std::endl;
```

当*u*等于0时，*--u*的结果将会是4294967295。一种解决办法是用`while`语句来代替`for`语句，前者可以在输出变量前先减去1。

```c++
unsigned u = 11;    // start the loop one past the first element we want to print
while (u > 0)
{
    --u;    // decrement first, so that the last iteration will print 0
    std::cout << u << std::endl;
}
```

### 初始化

初始化不等于赋值（assignment）。初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象的当前值擦除，再用一个新值来替代。【PRIMER 39】

```C++
int a(5);  // 构造函数语法，比如复数需要初始化两个值
complex<double> purei(0, 7);
int b = 6;  // C 风格的运算符（=）初始化

//关于指针
int arr[5] = {1, 2, 3, 4, 5};
int *p = arr; // 合法，数组名即首地址
cout << p[1] << endl;

// 如果要对数组求址，就需要定义一个数组指针，指向一个包含5个元素的数组
int(*pa)[5] = &arr; 
cout << "arr[0] = " << **pa << ", arr[2] = " << (*pa)[2] << endl;
cout << "p[1] - [p0] = " << pa[1] - pa[0] << endl; 
// 输出：
// arr[0] = 1, arr[2] = 3
// p[1] - [p0] = 5，表明数组指针包含 5 个元素

vector<int> vec(arr, arr + 5);
vector<int> *pv = &vec;  // 合法
//而 vector<int> *pv = vec;  不合法，因为 vec 是 vector 型对象，它的名字不是首地址
cout << vec[1] << endl;  // 注意与数组的差别
```

new 与 vector 定义多维变长数组并初始化，查看[code](./sources/mine/initOfMultidimensionalVector.cpp)

```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int row = 2;
	int col = 3;
	int **p = new int*[row];
	for (int i = 0; i < row; ++i)
	{
		p[i] = new int[col];
		for (int j = 0; j < col; ++j)
		{
			p[i][j] = i * col + j;
		}
	}
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			printf("p[%d][%d] = %d\n", i, j, p[i][j]);


	cout << "--------------------" << endl;
	int *p1 = new int[5];  // 未初始化， p 指向含 5 的整数的堆内存空间的首地址
	cout << p1[0] << " " << p1[1] << " " << *p1 << endl;
	int *p2 = new int(5);   // 初始化一个值，p 指向一个数
	cout << p2[0] << " " << p2[1] << " " << *p2 << endl;


	cout << "----------------------" << endl;
	int a = 2, b = 2, c = 3;
	vector<vector<vector<int> > > v(a, vector<vector<int> >(b, vector<int>(c, 5)));
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v[0].size(); ++j)
			for (int k = 0; k < v[0][0].size(); ++k)
				printf("v[%d][%d][%d] = %d\n", i, j, k, v[i][j][k]);

	cout << "-------------------------" << endl;
	vector<int> v1(c, 6);
	vector<vector<int> >v2(b, v1);
	vector<vector<vector<int> > >v3(a, v2);
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v[0].size(); ++j)
			for (int k = 0; k < v[0][0].size(); ++k)
				printf("v3[%d][%d][%d] = %d\n", i, j, k, v3[i][j][k]);

	cout << "-------------------------" << endl;
	int* pmalloc = (int *)malloc(sizeof(int) * row * col);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			pmalloc[i * col + j] = i * col + j;
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			printf("pmalloc[%d * %d + %d] = %d\n", i, col, j, pmalloc[i * col + j]);
	free(pmalloc);
}
```

### 逗号表达式

```C++
// 【例 1】
cout << a_string << (cnt % line_size ? ' ' : '\n');
// 若某一行计数不超过 line_size，就打印空格，否则换行。用来限制某一行字符打印的个数
//【ESS 11】

// 【例 2】
fun(f2(v1,v2),(v3,v4,v5),(v6,max(v7,v8)));
// fun 函数的实参个数有几个？
// 答：三个。
// 第一个是 f2 的返回值，第二个是逗号表达式(v3,v4,v5)的值，第三个是逗号表达式(v6,max(v7,v8))的值。
```

### 指针

如果指针不指向任何对象，则【提领】操作（也可称为【解引用】，即取指针指向的内容）会导致未知的执行结果。这意味着在使用指针时，必须在提领前确定它的确指向某对象。

一个未指向任何对象的指针，其地址为0，也被称为 nullptr 指针。我们可以在定义阶段便初始化指针，令其值为 0.

```C++
int *p = 0;  // 初始化指针地址为0
if (p && *p != 1024)  // 如果 p 地址不为零，才能有 *p 操作
    *p = 1024;
// 当 p 的地址为 0，直接提领，会报错
//【ESS 28】
```

#### 野指针

指的是没有被初始化过的指针。指针变量未初始化时不会自动成为 nullptr，而是一个随机值。

```C++
int main() { 
    int* p;     // 未初始化
    std::cout<< *p << std::endl; // 未初始化就被使用
    return 0;
}
```

因此，为了防止出错，对于指针初始化时都是赋值为 nullptr，这样在使用时编译器就会直接报错，产生非法内存访问。

#### 悬空指针

悬空指针，指针最初指向的内存已经被释放了的一种指针。（指针操作超越变量的作用域，比如函数返回栈内存的指针或引用）

```C++
int main() { 
    int * p = nullptr;
    int* p2 = new int;
    p = p2;
    delete p2;
}
```

此时 p和p2就是悬空指针，指向的内存已经被释放。继续使用这两个指针，行为不可预料。需要设置为p=p2=nullptr。此时再使用，编译器会直接保错。

野指针和悬空指针，无法通过简单地判断是否为 nullptr 避免，所以要习惯在初始化时赋值或析构时赋为nullptr。

`void*`是一种特殊的指针类型，可以存放任意对象的地址，但不能直接操作`void*`指针所指的对象。

#### 指针与数组名的区别

- 修改内容上的差别：

  ```C++
  char a[] = "hello";
  a[0] = 'H';
  char *p = "world";  // p 指向常量字符串，该字符串存储在文字常量区，不可更改
  // p[0] = "W"  		// 所以这个赋值有问题
  ```

    ```C++
  int main() {
      char a[] = "hello";
      char *p = a;  // 这样让指针指向数组 a，而非常量字符串，就可以修改了
      p[0] = 'H';
      a[1] = 'E';
      printf("%d", sizeof(p)); // 64 位机器
      std::cout << p << std::endl; 
      return 0;
  }
  //输出：8HEllo 
    ```

- sizeof

  ```C++
  sizeof(a);  // 输出6，包含 '\0'
  sizeof(p);  //  64 位机器输出 8
  /*
  指针类型对象占用内存为一个机器字的长度：
  这意味着在16位cpu上是16位 = 2字节
  32位cpu上是32位 = 4字节
  64位cpu上就是64位也就是8字节了
  */
  ```

#### 数组指针与指针数组

```C
type (*p)[]; // 数组指针
/*
type a[]，a 是一个数组，数组内元素都是 type 类型，将 a 换成 (*p)，
可以理解为 （*p）是一个数组，数组内元素都是 type 类型，那么 p 就是指向这样的数组的指针，即数组指针。
*/

type *p[]; // 指针数组
/*
type *p[]即(type *)p[]，则 p 是一个 type* 类型的数组(类比int a[10]，a 是 int 型数组）
即 p 是一个数组，数组内元素都是指针（ type *）
*/

// 在后文的介绍中使用右左法则，更容易理解
```

稍微复杂一些的指针数组：

```C++
const int seq_cnt = 6;
vector<int> *seq_addrs[seq_cnt] = {
    &fibonacci, &lucas, &pell,
    &triangular, &square, &pentagonal
};
// seq_addrs 是一个数组，存储 vector<int> * 型的指针，
// seq_addrs[0] 的内容为指针，该指针指向 fibonacci，
// 而 fibonacci 的类型为 vector<int>。
//【ESS 29】
```

#### 指针函数与函数指针

**指针函数**：返回类型是指针的函数，如

```C
char *StrCat(char *ptr1, char *ptr2)
{
    char *p;
    do something;
    return p;
}
```

**函数指针**：指向函数的指针，如

```C
#include <stdio.h>
int max(int x, int y)
{
    return x > y? x: y;
}
int main()
{
    // int max(int x, int y);
    int (*ptr)(int, int);
    ptr = max;
    int max_num = (*ptr)(12, 18);  // int max_num = ptr(12, 18);也是对的
    printf("%d", max_num);
    return 0;
}
// 打印 18。
```

```C
int (*ptr)(); // “()” 表明该指针指向函数，函数返回值为 int
int (*ptr)[3]; // “[]” 表明该指针指向一维数组，该数组里包含三个元素，每一个元素都是int类型。
```

数组名指向了内存中一段连续的存储区域，可以通过数组名的指针形式去访问，也可以定义一个相同类型的指针变量指向这段内存的起始地址，从而通过指针变量去引用数组元素。

每一个函数占用一段内存区域，而函数名就是指向函数所占内存区的起始地址的函数指针（地址常量），故**函数指针解引用与不解引用没有区别** 。通过引用函数名这个函数指针让正在运行的程序转向该入口地址执行函数的函数体，也可以把函数的入口地址赋给一个指针变量，使该指针变量指向该函数。

#### 复杂指针声明

**函数指针数组**

```C++
const vector<int>* (*seq_array[])(int) = {
    fibon_seq, lucas_seq, pell_seq,
    triang_seq, square_seq, pent_seq
};
```

seq_array 是一个可以持有六个函数指针的指针数组，第一个元素指向函数 fibon_seq()，该函数原型为 `const vector<int> *fibon_seq(int);`。

【ESS 62】

解读复杂指针使用右左法则：首先从未定义的标识符所在的圆括号看起，然后往右看，再往左看。每当遇到圆括号就调转阅读方向。一旦解析完圆括号里的东西，就跳出圆括号。重复这个过程，直到整个声明解析完毕。

```C++
int (*func)(int *p, int (*f)(int*));
// func左边有一个*表明func是一个指针，跳出圆括号看右边，右边有括号，说明func是一个函数指针，
// 指向的函数接收两个形参，分别是整型指针 int * 和函数指针 int (*f)(int*)，返回值为 int。

int (*func[5])(int *p);
// func 是一个数组，含5个元素，左边*号，表明 func 是一个指针数组（由于[]优先级高于*，func先跟[]结合，然后*修饰func[5]，故该数组的元素都是指针）。
//再往右看，是括号，说明 func 里的指针是函数指针，函数指针所指向的函数接收 int * 型参数并返回 int。

int (*(*func)[5])(int *p);
// func 是一个指针，指向含有 5 个元素的数组，数组里的元素都是指针，而且都是函数指针，
// 函数指针指向的函数接收 int * 型形参并返回 int。

int (*(*func)(int *p))[5];
// func 是一个指针，该指针指向一个函数，该函数接收 int * 型参数返回一个指针，
// 返回的指针指向一个数组，该数组含有 5 个元素，每一个元素都是 int 型。
```

### 指针(pointer)与引用(reference)

```C++
int ival = 1024;
int *pi = &ival;  // pointer
int &rval = ival;  // reference
```

- 引用是别名，而指针是地址。指针可以被赋值，以指向另一个不同的对象，而引用只能在定义时被初始化一次，以后不能修改，但引用的那个对象内容却可以改变。可以把引用理解为指针常量，而普通指针为指针变量。

- 引用不能为空，指针可以为空。故在使用上，指针可能（也可能不）指向一个对象，提领时一定要先确定其值非 0。而引用，则必定会代表某个对象，所以不需要作此检查。

- 从内存分配上来看，程序为指针变量分配内存区域，而不为引用分配内存区域。

- 引用使用时无需解引用(*)，指针需要解引用；

- 引用没有 const，指针有 const；

- “sizeof 引用” 得到的是所指向的变量(对象)的大小，而 “sizeof 指针” 得到的是指针本身的大小；

- 指针可以有多级，但是引用只能是一级（int **p；合法 而 int &&a是不合法的）

- 指针和引用的自增(++)运算意义不一样；

  ```C++
  int a = 0;
  int &b = a;
  int *p = &a;
  b++; // 相当于 a++; b 只是 a 的一个别名，和 a 一样使用。
  p++; // p 指向 a 后面的内存
  (*p)++; // 相当于 a++ 
  ```

（在二进制层面，引用一般是通过指针来实现的，只不过编译器帮我们完成了转换。总的来说，引用既具有指针的效率，又具有变量使用的方便性和直观性。）

【ESS 46，47】

#### 引用作为函数参数

- 传递引用给函数与传递指针给函数的效果是一样的。这时，被调函数的形参就成为原来主调函数中的实参变量或对象的一个别名来使用，所以在被调函数中对形参变量的操作就是对其相应的目标对象（在主调函数中）的操作。

- 使用引用传递函数的参数，在内存中并没有产生实参的副本，它是直接对实参操作；而使用一般变量传递函数的参数，当发生函数调用时，需要给形参分配临时存储单元，形参变量是实参变量的副本；如果传递的是对象，还将调用拷贝构造函数。因此，当参数传递的数据较大时，用引用比用一般变量传递参数的效率和所占空间都好。
- 使用指针作为函数的参数虽然也能达到与使用引用的效果，但是，在被调函数中同样要给形参分配存储单元，且需要重复使用 "*指针变量名" 的形式进行运算，这很容易产生错误且程序的可读性较差；另一方面，在主调函数的调用点处，必须用变量的地址作为实参。而引用更容易使用，更清晰。

#### 常引用作为函数参数

如果既要利用引用提高程序的效率，又要保护传递给函数的数据不在函数中被改变，就应使用常引用

```C++
void foo(const string &s) {
    cout << s << endl;
}  

// 如果形参里的 const 去掉，程序就报错，
// 因为 ss 与 "world!" 都是常量，你不能把一个 const 类型转换成非 const 类型。
// 所以 foo() 形参必定要用 const 修饰。

int main() {
    const string ss("hello ");
    foo(ss);
    foo("world!");
}
```

对于常量类型的变量，其引用也必须是常量类型的；对于非常量类型的变量，其引用可以是非常量的，也可以是常量的。但是要注意，无论什么情况都不能使用常量引用修改其引用的变量的值。

#### 函数返回引用与返回值

返回引用的好处：在内存中不产生被返回值的副本。

同时注意，正是因为这点原因，所以返回一个局部变量的引用是不可取的。因为随着该局部变量生存期的结束，相应的引用也会失效，产生 runtime error!

【注意】

- 最好不要返回局部变量的引用；
- 最好不要返回函数内部 new 分配的内存的引用；
- 流操作符重载返回值应为引用；
- 全局变量和局部静态变量的返回值可以是引用；
- 可以返回类成员的引用；

### 指针运算

#### \*&p和&\*p

- &：取出变量的存储地址。对指针变量 p，&p 取指针变量 p 所占用内存的地址，可以说是二级指针。  
- \*：引用指针所指向单元的内容。

```C++
1、*&p 等价于*(&p)
2、&*p 等价于&(*p)
p 是 int 变量，那么 *&p = p，而 &*p 是非法的。因为 *p 非法
p 是 int* 变量，那么 *&p = p，&*p = p，都是 p
```

#### p+(或-)n

指针加减一个数，是指该指针上移或下移n个数据之后的内存地址。即：

```C++
p +(或-) n * sizeof(type);
```

#### \*p++，*(p++)， (\*p)++，\*++p，++\*p

- \*p++ 和 \*(p++) 没有区别，因为 ++ 在变量之后，运算得先用再自增，所以先执行\*p，p再自增。这又与 (\*p)++ 有区别，这里面先 \*p，\*p 再自增而不是 p 自增。

  ```C++
  // 一个 ++ 在变量后，先用再自增的例子。
  int a = 3;
  int b = 3;
  printf("%d",a++); //打印3,但a值已经变成4了。先用a，a再自增，所以就是先打印3,打印完再自增。
  printf("%d",++b); //先自增，自增完，再用。
  ```
  
- \*++p 等价于 \*(++p)，p 先自增，自增完后再取 \*p 的值，即取下一个元素的值，而不是当前元素。    
  ++\*p，*p自增。

### i++ 与 ++i 的效率

- 对于内置数据类型，两者差别不大；
- 对于自定义数据类型（如类），++i 返回对象的引用，而 i++ 返回对象的值，导致较大的复制开销，因此效率低。

前缀++和后缀++的原型为：【PRIMER 501】

```c++
// class C;
C& C::operator++(); // 前缀运算符返回递增或递减后对象的引用
C C::operator++(int);  // 后缀运算符返回对象的值。为了与前缀运算符作区分，后缀版本接受一个（不被使用，编译器默认设为0）int类型的形参。
```

### sizeof

#### sizeof 计算普通变量与指针所占空间的大小

```C++
// 在32 位操作系统上，用 sizeof 计算下列变量所占空间的大小
// 32位，char:1，short:2, int:4，long:4
char str[] = "hello";  		// 6
char *p = str;         		// 4
int n = 10;            		// 4
void fun(char str[100])
{
    sizeof(str);			// 4，函数形参对传入的数组是按照指针处理的，在函数体内可以通过修改 str 修改函数外的数组
}
void *p = malloc(100);		// 4, p 指向 100 个字节的堆内存，但本质上还是指针。
```

#### sizeof 计算空类的大小

```C++
class A {};
cout << sizeof(A) << endl;	// 1
// 空类不包含任何信息，本来求 sizeof 的时候应该是 0，但是当我们声明该类型的实例的时候，它必须在内存中占用空间，否则无法使用。至于占多少空间由编译器来决定，使用 gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04) 编译打印 1。
```

```C++
class A
{
public:
	A() {};
	~A() {};
	// virtual void f() {};  //【1】
  // static int a; // 【2】
};
cout << sizeof(A) << endl;
// 注释【1】【2】，无虚函数，依旧占用空间 1 字节
// 只注释【1】，因为 static 变量不属于类，且无虚函数，依旧占用空间 1 字节
// 如果去掉【1】处注释，含虚函数，得占用内存 4。有虚函数时，默认有一个指针指向虚函数表。该指针占 4 字节。
// 普通成员函数不占用类的空间。类的函数是该类所有实例共享的，调用时通过隐藏的 this 指针和类的实例相关联，
// 普通成员函数代码编译后存储在程序代码区，根本就不在类实例中，所以不占实例空间。
```

#### sizeof 计算类对象与结构体、联合体所占空间的大小

[内存对齐 #program pack()](https://blog.csdn.net/sweetfather/article/details/79771288)

在 32 位操作系统上，占用空间 int:4, long:4, long long:8, double:8, float:4

在 64 位操作系统上，占用空间 int:4, long:8, long long:8, double:8, float:4

编译32位程序要加-m32选项

```shell
g++ t.cpp  -o t -std=c++14  -m32
```

如果提示如下错误

```shell
In file included from t.cpp:3:
/usr/include/stdio.h:27:10: fatal error: bits/libc-header-start.h: 没有那个文件或目录
 #include <bits/libc-header-start.h>
          ^~~~~~~~~~~~~~~~~~~~~~~~~~
```

则需要安装

```shell
sudo apt-get install g++-multilib
sudo apt-get install gcc-multilib
```

测试程序如下：

```C++
#include <iostream>
#include <thread>

// 以下运行皆在 64 位系统上，区别在于设置的内存对齐方式不同
#pragma pack(4)
//#pragma pack(8)

class A // 1
{
public:
    char ch;
};

// 4 字节对齐：4 + 8 + 2 + 填充2 = 16
// 8 字节对齐：4 + 填充4 + 8 + 2 + 填充6 = 24
class B
{
public:
    int i;
    long k;
    short j;
};

// 4 字节对齐：4 + 2 + 1 + 填充1 = 8
// 8 字节对齐：4 + 2 + 1 + 填充1 = 8
class C
{
public:
    int i;
    short j;
    char c1;
};

// 4 字节对齐：1 + 填充3 + 4 + 1 + 填充1 + 2 + 8 = 20
// 8 字节对齐：1 + 填充3 + 4 + 1 + 填充1 + 2 + 填充4 + 8 = 24
class D
{
public:
    char c1;
    int i;
    char c2;
    short j;
    long k;
};

// 4 字节对齐：4 + 8 + 1 + 1 + 2 = 16
// 8 字节对齐：4 + 填充4 + 8 + 1 + 1 + 2 + 填充4 = 24
class E
{
public:
    int i;
    long k;
    char c1;
    char c2;
    short j;
};

int main()
{
    // 【注意】类 C，D 的区别在于变量定义的顺序不一样
    E e;
    printf("int:%d, long:%d, long long:%d, double:%d, float:%d\n", sizeof(int), sizeof(long), sizeof(long long), sizeof(double), sizeof(float));
    printf("%d, %d, %d, %d, %d\n", sizeof(A), sizeof(B), sizeof(C), sizeof(D), sizeof(E));
    printf("%x, %x, %x, %x, %x, %x\n", &e, &e.i, &e.k, &e.c1, &e.c2, &e.j);
}
```

```C++
// 内存对齐方式为4
// 注意 S1 与 S2 也就是成员变量定义时顺序不一样而已
struct S1			// 4 + 1 + 1 + 填充2 = 8
{
	int a1;
	char c1;
	char c2;
};

struct S2			// 1 + 填充3 + 4 + 1 + 填充3 = 12
{
	char c1;
	int a1;
	char c2;
};

S2 s2;
printf("%x, %x, %x, %x\n", &s2, &s2.c1, &s2.a1, &s2.c2);
// 输出：10ff794, 10ff794, 10ff798, 10ff79c
```

```C++
// 内存对齐方式为4
union u1			// 8
{
	double a;
	int b;
};

union u2			// 13，对齐方式是1，13 是 1 的整数倍
{
	char a[13];
	char b;
};

union u3			// 16，对齐方式是 4，16 是 4 的整数倍
{
	char a[13];
	int b;
}；
```

这一切都与字节对齐有关：

- 结构体变量的首地址能够被其最宽基本类型成员的大小所整除；
- 结构体每一个成员相对于结构体首地址的偏移量都是成员大小的整数倍，如有需要，编译器会在成员之间加上填充字节；
- 结构体的总大小为结构体最宽基本数据类型成员大小的整数倍，如有需要，编译器会在最末一个成员之后加上填充字节。

联合体（共用体），类同理。

#### sizeof 与 strlen 区别

- sizeof 是操作符，strlen 是函数；

- 数组做 sizeof 参数不退化，传递给 strlen 就退化成指针（函数的形参将数组按指针处理）；

  ```C++
  char *s = "hello";
  char str[20] = "hello";
  cout << sizeof(s) << ' ' << sizeof(str) << endl;  // sizeof 对字符指针和字符数组的处理不同
  // cout << sizeof s << ' ' << sizeof str << endl; 
  // sizeof 后面不加括号也正确，因为 sizeof 是运算符不是函数，但用 sizeof 求类型大小，必须加括号，比如 sizeof(int)
  cout << strlen(s) << ' ' << strlen(str) << endl;
  /* 打印
  4 20
  5 5
  */
  ```

- sizeof 在编译阶段就计算出来了，所以可以定义数组的维度，而strlen是在运行时候才计算出来；

### strcpy 与 memcpy 区别

- 复制的内容不同。strcpy 只能复制字符串，而 memcpy 可以复制任意内容，例如字符数组、整型、结构体、类等。
- 复制的方法不同。strcpy 不需要指定长度，它遇到被复制字符的结束符 "\0" 才结束，所以容易溢出。memcpy 则是根据其第 3 个参数决定复制的长度。
- 用途不同。通常在复制字符串时用 strcpy，而需要复制其他类型数据时则一般用 memcpy 。 

### 作用域与生存周期

c++ 变量有两个属性非常重要：作用域和生存周期。

#### 花括号作用域

```C++
// 花括号可以看作是作用域标识符，除了在写函数时候用到，它还有一个作用是表示变量的作用域：
{ 					// 外花括号
    int a = 0;
    {				// 内花括号
        int b = 0;
        a = 1;  	//【1】正确，对外花括号内的 a 重新赋值
    }
    // b = 1;   	// 错误，b 已经被销毁了
    cout << a << endl;
    /*
    输出为 1。如果将【1】处 a = 1； 改成 int a = 1；此时输出为 0。
    因为前者 a = 1 表明修改的是外花括号内的 a，而后者表明定义一个局部变量 a 并初始化，
    内花括号的 a 屏蔽了外花括号的 a，而 cout 打印的是外花括号的 a
    */
}

// 对于 if, while, for 在花括号里定义的变量，出了花括号就被释放了，
    int a = 1;
    for (int a = 2; a == 2; ++a)
    {
        cout << a << endl; //for 中定义的 a 作用域在花括号内，屏蔽 for 外定义的 a
    }
    cout << a << endl; // 打印外花括号的 a
/* 打印
2
1
*/
```

【PRIMER 44】

作用域中一旦声明了某个名字，在它所嵌套着的所有作用域中都能访问该名字。同时，允许在内层作用域中重新定义外层作用域已有的名字，此时内层作用域中新定义的名字将屏蔽外层作用域的名字。

可以用作用域操作符`::`来覆盖默认的作用域规则。因为全局作用域本身并没有名字，所以当作用域操作符的左侧为空时，会向全局作用域发出请求获取作用域操作符右侧名字对应的变量。

#### 内存分配

一个程序将操作系统分配给其运行的内存块分为 5 个区域：

- 静态区（全局区）：存放程序的全局变量和静态变量。初始化的全局变量和静态变量在一个区域， 未初始化的全局变量和未初始化的静态变量在相邻的另一块区域。程序结束后由系统释放。（在以前的C语言中，全局变量又分为初始化的和未初始化的，在C++里面没有这个区分了，他们共同占用同一块内存区。）

- 堆区：存放程序的动态数据。

- 栈区：存放程序的局部数据，即各个函数的参数和局部变量等。函数结束，自动释放。

- （文字）常量区：常量字符串存放的区域，程序结束后由系统释放。

- 代码区：存放程序的代码，即程序中的各个函数代码块。

```c++
int a = 0; // 全局初始化区
char *p1;  // 全局未初始化区
int main() {
    int b;    // 栈
    char s[] = "abc"; // 栈
    char *p2; // 栈
    char *p3 = "123456";  // 字符常量 “123456\0” 在常量区，p3 在栈上。
    static int c = 0;  // 全局（静态）初始化区
    p1 = (char *)malloc(10);
    p2 = (char *)malloc(20);  // 分配得来的 10 和 20 字节的区域在堆区。
    strcpy(p1, "123456");  // “123456\0” 放在文字常量区，编译器可能会将它与 p3 所指向的 "123456\0" 优化成一个地方
}
```

#### 局部变量和全局变量

局部变量也称为内部变量，它是在函数内定义的。其作用域仅限于函数内，离开该函数后再使用这种变量是非法的。

全局变量也称为外部变量，它是在函数外部定义的变量。它不属于哪一个函数，它属于一个源程序文件。其作用域是整个源程序。在函数内部，局部变量可以屏蔽全局变量。如果一个全局变量用 static 修饰，它就是静态全局变量，它的作用域是该文件范围（称为文件作用域，即其它文件不能使用它）

##### 操作系统和编译器是怎么知道变量是全局还是局部？

操作系统和编译器，可能是通过内存分配的位置来知道的，全局变量分配在全局数据段并且在程序开始运行的时候被加载。局部变量则分配在堆栈里面。

#### 静态存储与动态存储

变量的生存周期只与变量的存储位置（存储类别）有关。可以分为：

- 静态存储方式（在程序运行期间，系统对变量分配**固定的**存储空间）
- 动态存储方式（在程序运行期间，系统对变量动态（**不固定**）的分配存储空间）

而变量的存储类别可以分为静态存储和动态存储

- auto  自动变量(动态存储方式) 
- static 静态变量(静态存储方式)  
- register 寄存器变量(动态存储方式) 
- extern 外部变量(静态存储方式) 

#### C++变量保存在堆还是栈？

- 如果对象是函数内的非静态局部变量，则对象，对象的成员变量保存在栈区。
- 如果对象是全局变量，则对象，对象的成员变量保存在静态区。
- 如果对象是函数内的静态局部变量，则对象，对象的成员变量保存在静态区。
- 如果对象是 new 出来的，则对象，对象的成员变量保存在堆区。

```C++
void foo() {
    int* p = new int[5]; 
}
// 在栈内存中存放了一个指向一块堆内存的指针 p
// 程序会先确定在堆中分配内存的大小，然后调用 operator new 分配内存
// 然后返回这块内存的首地址，存入栈中
```

#### 堆与栈的效率

栈是程序启动的时候，系统分好了给你的，你自己用，系统不干预。

堆是用的时候才向系统申请的，用完了还回去，这个申请和交还的过程开销相对就比较大了。

堆相对于栈，效率低，多次分配（malloc/new）容易产生碎片，使用时最好结合相关操作系统（Linux、Windows、RTOS ）使用，因为系统针对内存管理有专门的优化算法，减少内存碎片。堆虽然有一定的缺点，但其最大的优点是使用灵活，而且堆容量大，一般需要申请比较大的内存块时，都会从堆中申请。

### new 与 delete

堆内存（空闲空间）里的内存分配通过 new 表达式来完成，释放通过 delete 表达式来完成。堆内存由程序员自行管理。

```C++
int *p1 = new int;  // 未初始化
int *p2 = new int(1024); // 指定初值, p2 指向一个 int 对象，其值为 1024
int *p3 = new int[1024]; // 从 heap 中分配一个数组，含有1024个元素，p3 指向数组第一个元素
delete p1;
delete p2;  
delete [] p3  // new[] 与 delete[] 要一一对应
// 如果不使用 delete，由 heap 分配而来的对象就永远不会被释放，这被称之为内存泄漏。
```

【ESS 49，50】

#### new/delete 与 malloc/free 关系

malloc/free 是 C/C++ 的**标准库函数**，new/delete 是 C++ 的**运算符**。它们都可用于申请动态内存和释放内存。

对于非内部数据类型的对象而言，光用 malloc/free 无法满足动态对象的要求。对象在创建的同时要自动执行构造函数，对象在消亡之前要自动执行析构函数。由于 malloc/free 是库函数而不是运算符，不在编译器控制权限之内，不能够把执行构造函数和析构函数的任务强加于 malloc/free（malloc 只能申请内存，不能在申请内存的时候对所申请的内存进行初始化工作，而构造函数可以。free 只能释放内存，而如果析构函数设计得好的话，在释放内存的同时还可以完成额外的其他工作）。因此 C++ 语言需要一个能完成动态内存分配和初始化工作的运算符 new ，以及一个能完成清理与释放内存工作的运算符 delete 。

- new / new[]：完成两件事，先底层调用 malloc 分配内存，然后调用构造函数（创建对象）。
- delete/delete[]：也完成两件事，先调用析构函数（清理资源），然后底层调用 free 释放空间。
- new 在申请内存时会自动计算所需字节数，而 malloc 则需我们自己输入申请内存空间的字节数。

**malloc/free 的使用**

```C++
#include <iostream>
using namespace std;
int main() {
    int *score, num;
    cin >> num;
    if ((score = (int *)malloc(sizeof(int) * num)) == nullptr)
        cerr << "fail" << endl;
    else {
        do something;
        free(score); // 释放内存
    }
}
```

#### malloc、calloc、realloc的区别

- malloc与calloc的区别为1块与n块的区别

- realloc将 ptr 指向的内存的大小增大到 size，新增加的内存块没有初始化。

```c++
(type *)malloc(sizeof(type));	// 分配一个长度为 sizeof(type) 的连续空间，且未初始化，是随机数
(type *)calloc(n, sizeof(type)); // 分配 n 块 长度为 sizeof(type) 的连续空间，初始化，均为 0。
(type *)realloc(ptr, size)       // 将ptr指向的空间增大到size，新增加的内存块没有初始化。
```

### 宏


```C++
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define POW(x) ((x) * (x))
// 为什么用括号？因为宏只是简单的字符替换
```
### 头文件

- 头文件的扩展名习惯上是.h，标准库例外。
- 函数的定义只能有一份，倒是可以有多份声明。我们不能把函数的定义放在头文件，因为一个程序的多个代码文件可能都会包含这个头文件。但只定义一份的规则有一个例外，内联函数。**为了能够扩展内联函数的内容，以便在每个调用点上，编译器都取得其定义，必须将内联函数的定义放在头文件中，而不是放在各个不同程序代码文件中**（如果两个函数在定义时函数名和参数列表都一样(返回类型可以不一样)，则会出错，因为重载要保证参数列表不一样）。
- 一个对象和变量同函数一样，也只能在程序中定义一次，因此也应该将定义放在程序代码文件中，而不是头文件中。一般地，加上 extern 就可以放在头文件中作为声明了。

```C++
// 如果想声明一个变量而非定义它，就在变量名前添加 extern 关键字，而且不要显式地初始化变量
extern int x;  // 声明 x 而非定义
int y;         // 声明并定义 y
```

- `const int a = 6;`就可以放入头文件中，因为 const object 就和 inline 函数一样，是”一次定义“规则下的例外。因为 const 定义一出文件外便不可见（文件作用域），这意味着可以在多个不同的文件中加以定义。

- 头文件用 <> 表明此文件被认为是标准的或项目专属的头文件，编译器搜索此文件时，会先在系统默认的磁盘目录下寻找；头文件用 ” “ 表明此文件被认为是用户提供的头文件，会先在包含此文件的磁盘目录开始寻找，找不到再去系统默认的目录下寻找。

【ESS 63，64】

#### #ifndef/#define/#endif作用

防止头文件的重复包含和编译

```C++
#ifndef A_H // 意思是 if not define a.h"  如果不存在a.h
#define A_H // 就引入 a.h
#include <math.h> // 引用标准库的头文件 
… 
#include “header.h” // 引用非标准库的头文件 
… 
void Function1(…); // 全局函数声明 
… 
class Box // 类结构声明 
{ 
… 
}; 
#endif  // 最后一句应该写 #endif，它的作用相当于 if 的反花括号 '}'
```

#### extern “C” 
作为C语言的扩展，C++ 保留了一部分过程式语言的特点，因而它可以定义不属于任何类的全局变量和函数。但是，C++ 毕竟是一种面向对象的设计语言，为了支持函数的重载，C++ 对全局函数的处理方式有着明显的不同。 

首先看一下 C++ 对类似C的函数是怎样编译的： 

作为面向对象的语言，C++ 为了支持函数重载，函数在被 C++ 编译后在符号库中的名字与 C 语言的不同。假如某个函数的原型为 void foo(int x, int  y);，该函数被 C 编译器编译后在**符号库**中的名字为 \_foo，而 C++ 编译器则会产生 \_foo_int_int 之类的名字。_foo_int_int 这样的名字是包含了函数名以及形参，C++就是靠这种机制来实现函数重载的。 如果在 C 中连接 C++ 编译的符号时，就会因找不到符号问题而发生连接错误。

**被 extern “C” 修饰的函数或者变量是按照 C 语言方式编译和链接的，所以可以用一句话来概括 extern “C” 的真实目的：实现 C++ 与 C 的混合编程。**

### typedef 声明

可以使用 typedef 为一个已有的类型取一个新的名字。 

typedef 可以声明各种类型名，但不能用来定义变量。用 typedef 可以声明数组类型、字符串类型，使用比较方便。 

用 typedef 只是对已经存在的类型增加一个类型名，而没有创造新的类型。

```cpp
typedef int feet;		// 告诉编译器，feet 是 int 的另一个名称：可以理解 feet 为 int 的别名
feet distance;			// 它创建了一个整型变量 distance

typedef int A[];		// 定义了数组类型，数组大小由初始化时候决定
typedef int B[9];		// 定义了大小为9的数组类型，用 B 定义并初始化数组时，元素个数不应超过9
A arra = { 0, 1, 2, 3, 4 };			// arra 长度为 5
cout << arra[3] << ' ' << sizeof arra/sizeof arra[0] << endl; // 打印 3 5
B arrb = { 0, 1, 2, 3, 4 };  		// 实际是 {0， 1， 2， 3， 4， 0， 0， 0， 0}
cout << arrb[8] << ' ' << sizeof arrb / sizeof arrb[0] << endl; // 打印 0 9

typedef int (*pfun)(int x, int y);  // 定义一个 pfun 类型，表明一个函数指针类型
int fun(int x, int y);
pfun p = fun;						// 定义了一个 pfun 类型的函数指针，并指向函数 fun
int ret = p(2, 3);

typedef struct Student				// 定义了一个 ST 类型的结构体，下次定义结构体可直接用 ST 定义，
{									// ST Lux = { 123, 'F' };
	int id;
	char sex;
}ST;
```

### decltype 类型指示符

【PRIMER 62】

C++11新增`decltype`类型指示符，作用是选择并返回操作数的数据类型，此过程中编译器不实际计算表达式的值。

```c++
decltype(f()) sum = x;  // sum has whatever type f returns
```

`decltype`处理顶层`const`和引用的方式与`auto`有些不同，如果`decltype`使用的表达式是一个变量，则`decltype`返回该变量的类型（包括顶层`const`和引用）。

```c++
const int ci = 0, &cj = ci;
decltype(ci) x = 0;     // x has type const int
decltype(cj) y = x;     // y has type const int& and is bound to x
decltype(cj) z;     // error: z is a reference and must be initialized
```

如果`decltype`使用的表达式不是一个变量，则`decltype`返回表达式结果对应的类型。如果表达式的内容是解引用操作，则`decltype`将得到引用类型。如果`decltype`使用的是一个不加括号的变量，则得到的结果就是该变量的类型；如果给变量加上了一层或多层括号，则`decltype`会得到引用类型，因为变量是一种可以作为赋值语句左值的特殊表达式。

`decltype((var))`的结果永远是引用，而`decltype(var)`的结果只有当*var*本身是一个引用时才会是引用。

```C++
int i = 42;
decltype((i)) d1 = i; // d1 has type int&
decltype(i) d2 = i;   // d2 has type int
```

### 枚举类型

如果一个变量只有几种可能的值，可以定义为枚举(enumeration)类型。每个枚举元素在声明时被分配一个整型值，默认从 0 开始，逐个加 1。也可以在声明时将枚举元素的值一一列举出来。

注意

- 枚举元素是常量，除了初始化时不可给它赋值。
- 枚举变量的值只可取列举的枚举元素值。

```cpp
enum 枚举名{ 
     标识符[=整型常数], 
     标识符[=整型常数], 
... 
     标识符[=整型常数]
} 枚举变量;
```

如果枚举没有初始化,，即省掉 "=整型常数" 时，则从第一个标识符开始。

```cpp
enum color { red, green, blue } c;
c = blue; // c 为枚举变量，把枚举元素 blue 赋给 c，此时 c = 2
// 若直接这样赋值 c = 2；就会报错！你只能把{ red, green, blue }赋值给 c。
// blue = 2；报错！blue 是常量而不是变量。
// 未初始化默认 red = 0, green = 1, blue = 2
```

若给某一个标识符赋值如 green = 5

```c++
enum color { red, green = 5, blue } c;
c = blue;	// 6
color d;	// d 也为枚举变量
d = red;	// d = 0
// 部分值初始化，要满足后面的值比前面值大 1，此时 red 默认为 0
// green 初始化为 5 ，blue 要满足比 green 大 1 即 blue = 6
```

### [C结构体、C++结构体、C++类的区别](https://www.cnblogs.com/cthon/p/9170596.html) 

**C 结构体与 C++ 结构体**

- C 语言中的结构体不能为空，否则会报错
- C 语言中的结构体只涉及到数据结构，而不涉及到算法，也就是说在 C 中数据结构和算法是分离的。换句话说就是 C 语言中的结构体只能定义成员变量，但是不能定义成员函数（虽然可以定义函数指针，但毕竟是指针而不是函数）。然而 C++ 中结构体既可以定义成员变量又可以定义成员函数， C++ 中的结构体和类体现了数据结构和算法的结合。

**C++ 中结构体与类**

- 相同之处： 结构体中也可以包含函数；也可以定义 public、private、protected 数据成员；定义了结构体之后，可以用结构体名来创建对象。**也就是说在 C++ 当中，结构体中可以有成员变量，可以有成员函数，可以从别的类继承，也可以被别的类继承，可以有虚函数**。总的一句话：class 和 struct 的语法基本相同，从声明到使用，都很相似。
- 区别：对于成员**访问权限和继承方式**，class 中默认的是 private，而 struct 中则是 public。class 还可以用于表示模板类型，struct 则不行。

实际上`C++`中保留`struct`关键字是为了使`C++`编译器能够兼容`C`语言开发的程序

#### 结构体与联合体（共用体）的区别

- 结构和联合都是由多个不同的数据类型成员组成, 但在任何同一时刻, 联合中只存放了一个被选中的成员（所有成员共用一块地址空间）, 而结构体的所有成员都存在（不同成员的存放地址不同）。 （在 struct 中，各成员都占有自己的内存空间，它们是同时存在的。一个 struct 变量的总长度等于所有成员长度之和。在 Union 中，所有成员不能同时占用它的内存空间，它们不能同时存在。Union 变量的长度等于最长的成员的长度。）
- 对联合体不同成员赋值, 将会对其它成员重写, 原来成员的值就不存在了, 而对于结构的不同成员赋值是互不影响的。

### 类型转换

【PRIMER 142-146】

无须程序员介入，会自动执行的类型转换叫做隐式转换（implicit conversions）。

#### 算术转换

（Integral Promotions）

把一种算术类型转换成另一种算术类型叫做算术转换。

整型提升（integral promotions）负责把小整数类型转换成较大的整数类型。

#### 其他隐式类型转换

（Other Implicit Conversions）

在大多数表达式中，数组名字自动转换成指向数组首元素的指针。

常量整数值0或字面值`nullptr`能转换成任意指针类型；指向任意非常量的指针能转换成`void*`；指向任意对象的指针能转换成`const void*`。

任意一种算术类型或指针类型都能转换成布尔类型。如果指针或算术类型的值为0，转换结果是`false`，否则是`true`。

指向非常量类型的指针能转换成指向相应的常量类型的指针。

#### 显式转换

（Explicit Conversions）

显式类型转换也叫做强制类型转换（cast）。虽然有时不得不使用强制类型转换，但这种方法本质上是非常危险的。建议尽量避免强制类型转换。

命名的强制类型转换（named cast）形式如下：

```c++
cast-name<type>(expression);
```

其中*type*是转换的目标类型，*expression*是要转换的值。如果*type*是引用类型，则转换结果是左值。*cast-name*是`static_cast`、`dynamic_cast`、`const_cast`和`reinterpret_cast`中的一种，用来指定转换的方式。

- `dynamic_cast`支持运行时类型识别。
- 任何具有明确定义的类型转换，只要不包含底层`const`，都能使用`static_cast`。
- `const_cast`只能改变运算对象的底层`const`，不能改变表达式的类型。同时也只有`const_cast`能改变表达式的常量属性。`const_cast`常常用于函数重载。
- `reinterpret_cast`通常为运算对象的位模式提供底层上的重新解释。

早期版本的C++语言中，显式类型转换包含两种形式：

```C++
type (expression);    // function-style cast notation
(type) expression;    // C-language-style cast notation
```

#### 类型安全

类型安全是指同一段内存在不同的地方，会被强制要求使用相同的办法来解释(内存中的数据是用类型来解释的)。

Java 语言是类型安全的，除非强制类型转换。

C 语言不是类型安全的，因为同一段内存可以用不同的数据类型来解释，比如 1 用 int 来解释就是 1，用 boolean来解释就是 true。

C++ 也**不是**绝对类型安全的，但使用得当，它将远比 C 更有类型安全性。

**C++提供了一些新的机制保障类型安全：**

- 操作符 new 返回的指针类型严格与对象匹配，而不是 void
- C 中很多以 void* 为参数的函数可以改写为 C++ 模板函数，而模板是支持类型检查的；
- 引入 const 关键字代替 #define constants，它是有类型、有作用域的，而 #define constants 只是简单的文本替换；
- 一些 #define 宏可被改写为 inline 函数，结合函数的重载，可在类型安全的前提下支持多种类型，当然改写为模板也能保证类型安全；
- C++ 提供了 dynamic_cast 关键字，使得转换过程更加安全，因为 dynamic_cast 比 static_cast 涉及更多具体的类型检查。

### try语句块和异常处理

【PRIMER 172】

异常（exception）是指程序运行时的反常行为，这些行为超出了函数正常功能的范围。当程序的某一部分检测到一个它无法处理的问题时，需要使用异常处理（exception handling）。

异常处理机制包括`throw`表达式（throw expression）、`try`语句块（try block）和异常类（exception class）。

- 异常检测部分使用`throw`表达式表示它遇到了无法处理的问题（`throw`引发了异常）。
- 异常处理部分使用`try`语句块处理异常。`try`语句块以关键字`try`开始，并以一个或多个`catch`子句（catch clause）结束。`try`语句块中代码抛出的异常通常会被某个`catch`子句处理，`catch`子句也被称作异常处理代码（exception handler）。
- 异常类用于在`throw`表达式和相关的`catch`子句之间传递异常的具体信息。

#### throw表达式

`throw`表达式包含关键字`throw`和紧随其后的一个表达式，其中表达式的类型就是抛出的异常类型。

#### try语句块

`try`语句块的通用形式：

```c++
try
{
    program-statements
}
catch (exception-declaration)
{
    handler-statements
}
catch (exception-declaration)
{
    handler-statements
} // . . .
```

例子参考[try_catch.cpp](./sources/mine/try_catch.cpp)或者C语言中文网的[链接](http://c.biancheng.net/cpp/biancheng/view/3026.html)

`try`语句块中的*program-statements*组成程序的正常逻辑，其内部声明的变量在块外无法访问，即使在`catch`子句中也不行。`catch`子句包含关键字`catch`、括号内一个对象的声明（异常声明，exception declaration）和一个块。当选中了某个`catch`子句处理异常后，执行与之对应的块。`catch`一旦完成，程序会跳过剩余的所有`catch`子句，继续执行后面的语句。

如果最终没能找到与异常相匹配的`catch`子句，程序会执行名为`terminate`的标准库函数。该函数的行为与系统有关，一般情况下，执行该函数将导致程序非正常退出。类似的，如果一段程序没有`try`语句块且发生了异常，系统也会调用`terminate`函数并终止当前程序的执行。

#### 标准异常

异常类分别定义在4个头文件中：

- 头文件*exception*定义了最通用的异常类`exception`。它只报告异常的发生，不提供任何额外信息。

- 头文件*stdexcept*定义了几种常用的异常类。

  ![](assets/C-plus-plus/5-2.png)

- 头文件*new*定义了`bad_alloc`异常类。

- 头文件*type_info*定义了`bad_cast`异常类。

标准库异常类的继承体系：

![](assets/C-plus-plus/5-3.png)

只能以默认初始化的方式初始化`exception`、`bad_alloc`和`bad_cast`对象，不允许为这些对象提供初始值。其他异常类的对象在初始化时必须提供一个`string`或一个C风格字符串，通常表示异常信息。`what`成员函数可以返回该字符串的`string`副本。

## 类 & 对象

类包含对象所需的数据，以及描述用户与数据交互所需的操作。

成员函数可以定义在类内部，或者单独使用**范围解析运算符（域区分符） ::** 来定义。在类定义中定义的成员函数把函数声明为**内联**的，即使没有使用 inline 标识符。

类的成员名和方法的参数名不能相同，建议成员名加上 'm' 前缀或者末尾加上 '_'。

【PLUS 353】

### 类对象声明

```c++
class C
{
public:
    C() { std::cout << "call C()" << std::endl; };
    C(int _m) : m(_m) { std::cout << "call C(int m)" << std::endl; };

private:
    int m;
};

int main()
{
    C c1;    // call C()
    C c2();  // 仅仅声明了一个函数 c2，它返回 C 类型，所以不要乱加括号
    C c3(1); // call C(int m)

    return 0;
}
```

### 类访问修饰符

- public：公有成员在程序中类的外部是可访问的。可以不使用任何成员函数来设置和获取公有变量的值。
- private：私有成员变量或函数在类的外部是不可访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员（派生类也不能访问）。
- protected：保护成员变量或函数与私有成员十分相似，但有一点不同，保护成员在派生类（即子类）中是可访问的。

### 封装继承多态

#### **封装**

封装是实现面向对象程序设计的第一步，封装就是将数据或函数等集合在一个个的单元中（称之为类）。

封装的意义在于保护或者防止代码（数据）被无意中破坏。

#### **继承**

继承主要实现代码重用，节省开发时间。子类可以继承父类的一些东西。

有 public,  protected,  private 三种继承方式，它们相应地改变了派生类的用户以及派生类的派生类的访问权限。

- public 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private

- protected 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private

- private 继承：基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private, private, private

但无论哪种继承方式，上面两点都没有改变：

- private 成员只能被本类成员（类内，不是实例化的对象）和友元访问，不能被派生类访问；
- protected 成员可以被派生类（类内，不是实例化的对象）访问。

##### 私有继承的作用

私有继承时，编译器一般不会将派生类对象转换成基类对象。且派生类与基类不是 `is a` 的关系，而是意味着“`is implement in terms of`”（以......实现）的关系。如果类D私有继承于B，这样做，只是因为D想使用B中的某些代码，而不是因为类D的对象与类B的对象之间有什么概念上的关系。因此，私有继承在软件“设计”过程中毫无意义，只是在软件“实现”时才有用。

##### 私有继承与组合的不同

- 组合是`has a`关系，如果需要使用一个对象的某些方法，可以用组合，也可以私有继承。**选择它们的原则是尽可能使用组合，万不得已才使用继承。继承最大的问题就在于：继承层次过深、继承关系过于复杂会影响到代码的可读性和可维护性（继承了无用或者有害的方法，代码膨胀等，还有，在继承时，基类之间或基类与派生类之间发生成员同名时，将出现对成员访问的不确定性，即同名二义性）。**
- **私有继承中派生类能访问基类的protected成员，并且可以重写基类的虚函数，甚至当基类是抽象类的情况。组合不具有这样的功能。**

#### **多态**

同一个方法在派生类和基类中的行为是不同的，即方法的行为取决于调用该方法的对象。有两种重要的机制可以实现多态公有继承：

- 在派生类中重新定义基类的方法
- 使用虚方法

【注意】在派生类中重新定义基类的方法，会导致基类方法被隐藏（函数隐藏），这不是重载，重载是一个类中的方法与另一个方法同名，但是参数表不同，这种方法称之为重载方法。

#### **重载与重写**

- 重写（overried，覆盖、覆写）：是指子类重新定义父类虚函数的方法。与多态有关。

- 重载（overload）：是指允许存在多个同名函数，而这些函数的参数列表不同（或许参数个数不同，或许参数类型不同，或许两者都不同）返回值类型随意。与多态无关。

  - [`C++`中 `const` 用于函数重载](https://www.cnblogs.com/qingergege/p/7609533.html)。常成员函数不能更新类的成员变量，也不能调用该类中没有用`const`修饰的成员函数，只能调用常成员函数。非常量对象可以调用常成员函数和非常成员函数，但是如果有重载的非常成员函数则会调用非常成员函数。

    ```c++
    class C
    {
    public:
        C(int v) : mValue(v){};
        void fun() const { std::cout << "void fun() const" << std::endl; };
        void fun() { std::cout << "void fun()" << std::endl; };
    
    private:
        int mValue;
    };
    
    int main()
    {
        const C c1(1);
        C c2(2);
        c1.fun();
        c2.fun();
        return 0;
    }
    /* 打印
    void fun() const
    void fun()
    **/
    ```

  - 顶层`const`是不支持重载的，因为函数调用的时候，存在形实结合的过程，所以不管有没有`const`都不会改变实参的值。

    ```c++
    void fun(char *s)
    {
        std::cout << "non-const fun() " << s << std::endl;
    }
    
    void fun(char *const s) // 顶层 const 不支持重载
    {
        std::cout << "const fun() " << s << std::endl;
    }
    /** 编译出错
    test.cpp:21:6: error: redefinition of ‘void fun(char*)’
     void fun(char *const s)
          ^~~
    test.cpp:16:6: note: ‘void fun(char*)’ previously defined here
     void fun(char *s)
          ^~~
    */
    ```

  - ​	底层`const`支持重载

    ```c++
    void fun(char *s)
    {
        std::cout << "non-const fun() " << s << std::endl;
    }
    
    void fun(const char *s) // 底层 const 支持重载
    {
        std::cout << "const fun() " << s << std::endl;
    }
    
    int main()
    {
        char *ptr1 = "hello";
        const char *ptr2 = "world";
        fun(ptr1);
        fun(ptr2);
        return 0;
    }
    /**
    non-const fun() hello
    const fun() world
    */
    // 对于引用也是同样的道理，如
    // void fun(int &i) 和 void fun(const int &i) 也是可以重载的。
    // 原因是第一个 i 引用的是一个变量，而第二个 i 引用的是一个常量，两者是不一样的，类似于上面的指向变量的指针和指向常量的指针。
    ```

### 构造函数与析构函数

```C++
class Line
{
	private:
	double length;
	
	public:
		void setLength(double len);
		Line(double len); 	// 构造函数的名称与类的名称完全相同。不会返回任何类型，也不会返回 void，常用于赋初值
		~Line();  			// 析构函数，函数名与类完全相同，只是在前面加了一个波浪号（~）作为前缀，它不会返回任何值，也不会返回void，也不能带有任何参数（所以不可以被重载）。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
		double Line::getLength(void)  //方法可以定义在类中
        {
			return length;
		}
};

Line::Line(double len) // 方法也可以通过范围解析运算符定义在类外，这是构造函数的具体实现，注意函数前无类型
{
	cout << "Object is being created, length = " << len << endl;
	length = len; //初始化属性
}

Line::~Line(void)
{
	cout << "Object is being deleted" << endl;
}
```

也可以使用初始化列表来初始属性

```C++
Line::Line( double len): length(len)
{
    cout << "Object is being created, length = " << len << endl;
}
```

```C++
// 同时初始化多个值
Person::Person( double name, double age, double job): Name(name), Age(age), Job(job)  
// 将参数 name, age, job 初始化给属性 Name, Age, Job
{
  ....
}
```

**构造函数不同于类方法，因为它创建新的对象，而其他类对象只是被现有的类调用。这是构造函数不能被继承的原因之一。** 继承意味着派生类继承基类的成员函数和成员变量，然而，在构造函数完成其工作之前，对象并不存在。

一定要使用显式析构函数来释放类构造函数使用 new 分配的所有内存，并完成类对象所需的任何特殊的清理工作。对于基类即使它不需要析构函数，也应提供一个虚析构函数。

**初始化派生类把基类中所有的成员继承过来，除了构造函数和析构函数。友元函数不属于类，它只是给类开了一个后门，自然不能被继承。**子类继承父类，那么默认的，就是继承了父类的成员函数和成员变量。

初始化子类时，会先自动调用父类的构造函数，然后才调用子类的构造函数。

析构时，按相反顺序进行。

构造从类层次的最根处开始，在每一层中，首先调用基类的构造函数，然后调用成员对象的构造函数。析构则严格按照与构造相反的次序执行，该次序是唯一的，否则编译器将无法自动执行析构过程。

【PLUS 524，525，527】

#### 构造函数不能声明为const

**不同于其他函数，构造函数不能被声明为`const`。当我们创建类的一个`const`对象时，直到构造函数完成初始化过程，对象才真正取得其常量属性。因此，构造函数在`const`对象的构造过程中可以向其写值。**

【PRIMER 235】

构造函数可以被重载，**析构函数不可以被重载**。因为析构函数只能有一个且不带参数。

### 委托构造函数

C++11扩展了构造函数初始值功能，可以定义委托构造函数。委托构造函数使用它所属类的其他构造函数执行它自己的初始化过程。【PRIMER 261】

### = default和=  delete

在C++中，声明自定义的类型之后，编译器会默认生成一些成员函数，这些函数被称为默认函数。其中包括：

```C++
class A
{
    // C++03
    A();                     // 默认构造函数
    A(const A &);            // 拷贝构造函数
    ~A();                    // 析构函数
    A &operator=(const A &); // 拷贝赋值运算符

    // C++11 新增
    A(A &&);            // 移动构造函数
    A &operator=(A &&); // 移动赋值运算符
};
```

这6个函数的实现例子，以string为例，[查看实现](./sources/mine/MyString.cpp)

另外，编译器还会默认生成一些操作符函数，包括：

（7）operator ,

（8）operator &，有两个，const版本和非const版本

```c++
A* operator&();                 //取址运算符
const A* operator&() const;     //取址运算符(const版本)
```

（9）operator &&

（10）operator *

（11）operator ->

（12）operator ->*

（13）operator new

（14）operator delete

#### 不建议重载的运算符

通常情况下，不应该重载逗号、取地址（前面两个已有内置含义）、逻辑与和逻辑或运算符。

即使是重载，也要让它们与内置类型保持一致，否则，它们的行为将异于常态，导致用户无法被适应。

![](assets/C-plus-plus/14-1.png)

#### = default 显示缺省函数

**只有当类没有声明任何构造函数时，编译器才会自动生成默认构造函数。一旦类定义了其他构造函数，那么除非再显式地定义一个默认的构造函数，否则类将没有默认构造函数。**【PRIMER 236】

在C++11中，如果类需要默认的函数行为，可以通过在参数列表后面添加`=default`来要求编译器生成构造函数。其中`=default`既可以和函数声明一起出现在类的内部，也可以作为定义出现在类的外部。和其他函数一样，如果`=default`在类的内部，则默认构造函数是内联的。

```C++
Sales_data() = default;
```

#### = delete 显示删除函数

另一方面，有时候可能需要限制一些默认函数的生成。

例如：需要禁止拷贝构造函数的使用。以前通过把拷贝构造函数声明为`private`访问权限，这样一旦使用编译器就会报错。

而在 C++11 中，只要在函数的定义或者声明后面加上`= delete`就能实现这样的效果。这种方式不容易犯错，且更容易理解。

在C ++ 11之前，操作符delete 只有一个目的，即释放已动态分配的内存。而C ++ 11标准引入了此操作符的另一种用法，即：禁用成员函数的使用。这是通过附加`= delete`说明符到该函数声明的结尾。

### 拷贝（复制）构造函数

```C++
class Line
{
    public:
    	Line(int len);  //构造函数
    	Line(const Line &obj);  //拷贝构造函数
    	~Line();  //  析构函数
    
    private:
    	int *ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}
 
Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}
 
Line::~Line(void)
{
    cout << "释放内存" << endl;
    delete ptr;
}
```

#### 什么情况使用拷贝构造函数

```C++
class Test
{
public:
	int a;
	Test(int x) : a(x) { cout << "Test(int x)" << endl; }
	Test(const Test& t)
	{
		cout << "copy constructor" << endl;
		a = t.a;
	}
};

void fun1(Test test)
{
	cout << "fun1()" << endl;
}

Test fun2()
{
	Test t(2);
	cout << "fun2()" << endl;
	return t;
}

int main(int argc, char* argv[]) {
	Test t1(1);
	cout << "-------\n";
	Test t2(t1);					// 通过使用另一个同类型的对象来初始化新创建的对象。
	cout << "-------\n";
	fun1(t1);						// 复制对象把它作为参数传递给函数。
	cout << "-------\n";
	fun2();							// 复制对象，并从函数返回这个对象，返回对象时调用拷贝构造函数。
	//Test t3 = fun2();
    
	getchar();
	return 0;
}
/* 打印
Test(int x)
-------
copy constructor
-------
copy constructor
fun1()
-------
Test(int x)
fun2()
copy constructor
*/
```

**类的对象需要拷贝时，拷贝构造函数将会被调用。**以下情况都会调用拷贝构造函数：

- 通过使用另一个同类型的对象来初始化新创建的对象。
- 复制对象，把它作为参数传递给函数。
- 复制对象，并从函数返回这个对象。

#### 浅复制与深复制

如果在类中没有显式地声明一个复制构造函数，那么，编译器将会自动生成一个**默认的复制构造函数，该构造函数完成对象之间的浅复制。**

自定义复制构造函数是一种良好的编程风格，它可以阻止编译器形成默认的复制构造函数，提高源码效率。

所谓浅复制，直接为数据成员赋值即可。比如一个实类 c1 里的数据成员里有一个指针 c1.p 指向字符数组 str[] = “hello”，使用浅复制来初始化类 c2，则赋值为 c2.p = c1.p，那么通过 c1.p 改变了 str，c2.p 指向的内容也会改变。

而深复制要创建新的对象，要为对象的数据成员分配存储空间，直接赋值就将值保存在相应的空间中。比如

```C++
// c1, c2 均是类
c2.p = new char[strlen(c1.p) + 1]; 
strcpy(c2.p, c1.p); 
```

让 c2.p 指向 new 出来的空间，这时 c1.p 里的内容改变了也不会影响 c2.p。

#### 编译器与默认的 copy constructor

- 如果用户定义了一个构造函数（不是拷贝构造函数），且此时在代码中用到了拷贝构造函数，那么编译器会生成默认的拷贝构造函数；如果没有使用，编译器就不会生成默认的拷贝构造函数；
- 如果用户定义了拷贝构造函数，则编译器就不会再生成拷贝构造函数。

#### 为什么复制构造函数可以访问参数对象的私有成员

**封装是编译期的概念，是针对类型而非对象的，在类的成员函数中可以访问同类型实例对象的私有成员变量。**

参考：https://blog.csdn.net/ganwenbo2011/article/details/100919900

#### 拷贝构造函数与赋值函数的区别

```C++
A (const A&other) // 拷贝构造函数重载声明
A& operator = (const A& other) // 赋值函数重载声明
```

- 一般来说在数据成员包含指针对象的时候，需要考虑两种不同的处理需求：一种是复制指针对象，另一种是引用指针对象。拷贝构造函数大多数情况下是复制，而赋值函数是引用对象。

- 拷贝构造函数是一个对象初始化一块内存区域，这块内存就是新对象的内存区。赋值构造函数则是把一个对象赋值给一个原有的对象，所以，对于赋值函数，如果原来的对象中有内存分配，就要先把内存释放掉，而且还要检查一下两个对象是不是同一个对象，如果是的话就不做任何检测。

```C++
class A;
A a;
A b = a;   // 调用拷贝构造函数（b 不存在）
A c(a) ;   // 调用拷贝构造函数
A d;
d = a;     // 调用赋值函数（d 已初始化）
```

以字符串的为例子，理解拷贝构造函数和赋值函数

```c++
String::String(const String &other) //拷贝构造函数
{
    cout << "copy construct" << endl;
    m_string = new char[strlen(other.m_string) + 1]; //分配空间并拷贝
    strcpy(m_string, other.m_string);
}

String &String::operator=(const String &other) //赋值运算符
{
    cout << "operator =funtion" << endl;
    if (this == &other) //如果对象和other是用一个对象，直接返回本身
    {
        return *this;
    }
    delete[] m_string; //先释放原来的内存
    m_string = new char[strlen(other.m_string) + 1];
    strcpy(m_string, other.m_string);
    return *this;
}
```

### 临时对象的复制与析构

```C++
class C
{
public:
    C() : mValue(0)
    {
        std::cout << "default constructor, value = " << mValue << std::endl;
    };
    C(const C &c)
    {
        mValue = c.mValue;
        std::cout << "copy constructor, value = " << mValue << ", this = " << std::hex << this << std::endl;
    };
    C &operator=(const C &c)
    {
        if (this == &c)
            return *this;
        mValue = c.mValue;
        std::cout << "assignment function, value = " << mValue << ", this = " << std::hex << this << std::endl;
        return *this;
    };
    C(int v) : mValue(v)
    {
        std::cout << "constructed by parameter: " << std::dec << mValue << ", this = " << std::hex << this << std::endl;
    };
    virtual ~C()
    {
        std::cout << "destructor, value = " << mValue << ", this = " << std::hex << this << std::endl;
    };

private:
    int mValue;
};

C create(C c)
{
    std::cout << "start creat" << std::endl;
    return c;
}

int main()
{
    C c1 = create(5);
    std::cout << "finish creat c1" << std::endl;
    C c2 = create(c1);
    std::cout << "finish creat c2" << std::endl;
    C c3 = create(8);
    std::cout << "finish creat c3" << std::endl;
    C c4 = 12;
    std::cout << "finish creat c4" << std::endl;
    c4 = c1;
    return 0;
}
// g++ test.cpp -o test -std=c++11 -m32
/* 打印
constructed by parameter: 5, this = 0xffb5a528 // create 函数值传递，调用带参数的构造函数，生成临时对象
start creat
copy constructor, value = 5, this = 0xffb5a520 // return 值，调用拷贝构造函数，生成临时对象
destructor, value = 5, this = 0xffb5a528       // 析构值传递所产生的临时对象（形参）
finish creat c1
copy constructor, value = 5, this = 0xffb5a530 // create 函数值传递，调用拷贝构造函数，生成临时对象
start creat
copy constructor, value = 5, this = 0xffb5a518 // return 值，调用拷贝构造函数，生成临时对象
destructor, value = 5, this = 0xffb5a530       // 析构值传递所产生的临时对象（形参）
finish creat c2
constructed by parameter: 8, this = 0xffb5a538 // create 函数值传递，调用带参数的构造函数，生成临时对象
start creat
copy constructor, value = 8, this = 0xffb5a510 // return 值，调用拷贝构造函数，生成临时对象
destructor, value = 8, this = 0xffb5a538       // 析构值传递所产生的临时对象（形参）
finish creat c3
constructed by parameter: 12, this = 0xffb5a508 // 隐式转换，调用带参数的构造函数
finish creat c4
assignment function, value = 5, this = 0xffb5a508 // 调用赋值函数，将 c1 赋给 c4
destructor, value = 5, this = 0xffb5a508 // c4 析构
destructor, value = 8, this = 0xffb5a510 // c3 析构
destructor, value = 5, this = 0xffb5a518 // c2 析构
destructor, value = 5, this = 0xffb5a520 // c1 析构
*/
```

### 空类的成员函数

```C++
  class Empty { 
  public:
    Empty(); 
    Empty(const Empty& );
    ~Empty();

    Empty& operator=(consy Empty& );
    Empty* operator& ();               // 取地址运算符
    const Empty* operator& () const;   // const 类型取地址运算符
  };
```

- 缺省构造函数。
- 缺省拷贝构造函数。
- 缺省析构函数。
- 赋值运算符。
- 取址运算符。
- 取址运算符 const 。

有些书上只是简单的介绍了前四个函数。没有提及后面这两个函数。但后面这两个函数也是空类的默认函数。另外需要注意的是，**只有当实际使用这些函数的时候，编译器才会去定义它们。**

### 初始化列表

#### [使用初始化列表的原因](https://www.cnblogs.com/graphics/archive/2010/07/04/1770900.html)

初始化类的成员有两种方式，一是使用初始化列表，二是在构造函数体内进行赋值操作。

主要是性能问题，对于内置类型，如 int, float 等，使用初始化列表和在构造函数体内初始化差别不是很大，但是对于类类型来说，最好使用初始化列表，**因为使用初始化列表少了一次调用默认构造函数的过程**，这对于数据密集型的类来说，是非常高效的（参考下文代码段例1）。

#### 必须使用初始化列表的情况

（只能使用初始化而不能赋值）【PRIMER 259】

**初始化和赋值的区别事关底层效率**：前者直接初始化数据成员，后者则先初始化再赋值。

除了效率问题之外，有些时候初始化列表是不可或缺的，以下几种情况时必须使用初始化列表：

- 常量成员，因为常量只能初始化不能赋值，所以必须放在初始化列表里面；

- 引用类型，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表里面；

- **没有默认构造函数的类类型（比如构造函数为私有），因为使用初始化列表可以不必调用默认构造函数来初始化，而是直接调用拷贝构造函数初始化**。（参考下文代码段例1）

  **如果在子类的构造函数中需要初始化父类的 private 成员。直接对其赋值是不行的，只有调用父类的构造函数才能完成对它的初始化**。（参考下文代码段例2）

【总结】**当类中含有 const 常量、reference 成员变量；基类的构造函数都需要初始化列表。**

```c++
// 例1
class A
{
public:
    int num;
    A() // 无参构造函数
    {
        cout << "Construct A" << endl;
    }

    A(const A &obj) // 拷贝构造函数
    {
        cout << "Copy constructor for A" << endl;
        this->num = obj.num;
    }

    A &operator=(const A &obj) // 赋值运算符
    {
        cout << "assignment for A" << endl;
        this->num = obj.num;
        return *this;
    }
};

class B
{
public:
    A a;
    B(A &obj) { a = obj; } // 【1】
    //B(A &obj) : a(obj) {}  // 【2】
};

int main()
{
    A a;
    B b(a);
    return 0;
}
/**
 * 开放【1】注释【2】打印
 * Construct A // main 函数里的 A a 打印
 * Construct A // 因为在 class B 中，语句 A a 调用了默认构造函数，使用列表初始化就不调用它，转而去调用拷贝构造函数
 * assignment for A
 * 开放【2】注释【1】打印
 * Construct A
 * Copy constructor for A
*/
```

```C++
// 例2
class A
{
private:
	int a;
public:
	A(int x) : a(x) {}
};

class B : public A
{
private:
	int b;
public:
	B(int x, int y) : A(x)
	{
		// a = x;			// a 为 private，无法在子类中被访问
		// A(x);			// 在函数体内调用父类的构造函数不合法
		b = y;
	}
};
```

#### 初始化顺序

成员是按照他们在类中出现的顺序进行初始化的，而不是按照他们在初始化列表出现的顺序初始化的。

```C++
class foo {
    public:
    int i;
    int j;
    foo(int x): i(x), j(i) {} // ok, 先初始化 i，后初始化 j
};
```

再看下面的代码：

```C++
class foo {
    public:
    int i;
    int j;
    foo(int x): j(x), i(j) {} // i 值未定义
    /*
    这里 i 的值是未定义。因为虽然 j 在初始化列表里面出现在 i 前面，
    但是 i 先于 j 定义，所以先初始化 i，而 i 由 j 初始化，
    此时 j 尚未初始化，所以导致 i 的值未定义。
    一个好的习惯是，按照成员定义的顺序进行初始化。
    */
};
```

### 友元

#### 友元函数

友元函数声明只能出现在类定义的内部，在类内部出现的位置不限（一般在类定义的开始或结束前的位置集中声明友元）。友元不是类的成员函数，也不受它所在区域访问控制级别的约束。

友元声明仅仅指定了访问权限，而并非一个通常意义上的函数声明。如果希望类的用户能调用某个友元函数，就必须在友元声明之外再专门对函数进行一次声明（部分编译器没有该限制）。

为了使友元对类的用户可见，通常会把友元的声明（类的外部）与类本身放在同一个头文件中。

友元函数的定义在类外部，但与成员函数有相同的权限，所以可以访问类的所有私有（private）成员和保护（protected）成员。

友元可以是一个函数，该函数被称为友元函数。友元也可以是一个类，该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。

【PRIMER 241, 242】

```C++
// Sales_data.h
class Sales_data 
{
    // friend declarations for nonmember Sales_data operations added
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    
    // other members and access specifiers as before
public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(std::istream&);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);
    
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// declarations for nonmember parts of the Sales_data interface
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
```

#### 友元类

除了普通函数，类还可以把其他类或其他类的成员函数声明为友元。友元类的成员函数可以访问此类包括非公有成员在内的所有成员。

```c++
class Screen 
{
    // Window_mgr members can access the private parts of class Screen
    friend class Window_mgr;
    // ... rest of the Screen class
};
```

友元关系不存在传递性。

把其他类的成员函数声明为友元时，必须明确指定该函数所属的类名。

如果类想把一组重载函数声明为友元，需要对这组函数中的**每一个分别声明**。

```c++
class Screen
{
    // Window_mgr::clear must have been declared before class Screen
    friend void Window_mgr::clear(ScreenIndex);
    // ... rest of the Screen class
};
```

友元函数可以直接定义在类的内部，这种函数是隐式内联的。但是必须在类外部提供相应声明令函数可见。如下：

```c++
struct X
{
    friend void f() { /* friend function can be defined in the class body */ }
    X() { f(); }   // error: no declaration for f
    void g();
    void h();
};

void X::g() { return f(); }     // error: f hasn't been declared
void f();   // declares the function defined inside X
void X::h() { return f(); }     // ok: declaration for f is now in scope
```

【PRIMER 250~252】

#### 友元访问控制与继承

一个类可以使用`protected`关键字来声明外部代码无法访问，但是派生类对象可以访问的成员。

派生类的成员或友元只能访问派生类对象中的基类部分的`protected`成员。对于普通的**基类对象**中的`protected`成员没有任何访问权限。

```c++
class Base
{
protected:
    int prot_mem;   // protected member
};

class Sneaky : public Base
{
    friend void clobber(Sneaky&);   // can access Sneaky::prot_mem
    friend void clobber(Base&);     // can't access Base::prot_mem
    int j;   // j is private by default
};

// ok: clobber can access the private and protected members in Sneaky objects
void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }
// error: clobber can't access the protected members in Base
void clobber(Base &b) { b.prot_mem = 0; }
```

【PRIMER 543】

### 内联函数

C++ 内联函数是通常与类一起使用。如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。**在类中定义的函数都是内联函数，即使不用 inline 说明符**。定义不在类里面，且声明和定义都没有inline，就不会隐式内联。[C++类里面的哪些成员函数是内联函数？](https://blog.csdn.net/qq_18343569/article/details/83755202)

引入内联函数的目的是为了解决程序中函数调用的效率问题，因为编译器使用相同的函数代码代替函数调用，对于内联代码，程序无需跳转到另一个位置执行代码，再跳回来。因此内联函数的运行速度比常规函数稍快，但代价是需要占用更多的内存。如果在程序的多个不同的地方调用内联函数，该程序将包含该内联函数的多个副本。总的来说就是用空间换时间。所以内联函数一般都是1-5行的小函数。关于内联函数可以总结为：

- 相当于把内联函数里面的内容写在调用内联函数处；
- 相当于不用执行进入函数的步骤，直接执行函数体；
- 相当于宏，却比宏多了类型检查，真正具有函数特性；
- 不能包含循环、递归、switch 等复杂操作；
- **在类声明中定义的函数，除了虚函数的其他函数都会自动隐式地当成内联函数。在类外定义需要显式内联**；
  使用内联函数不过是向编译器提出一种申请，编译器可以拒绝你的申请。

#### 内联函数与宏的区别

- 内联函数在编译时展开，宏在预编译（预处理）时展开；
- 在编译的时候，内联函数可以直接被镶嵌到目标代码里，而宏只是一个简单的文本替换；
- 内联函数可以完成诸如类型检测、语句是否正确等编译功能，宏就不具有这样的功能；
- 内联函数是函数，宏不是函数；
- 宏在定义时要小心处理宏参数（用括号括起来），否则会出现二义性，而内联函数定义时不会出现二义性

### volatile

volatile 关键字是一种类型修饰符，用它声明的类型变量表示这个变量可能被意想不到的修改（比如：操作系统、硬件或者其它线程等）。遇到这个关键字声明的变量，编译器对访问该变量的代码就不再进行优化，从而可以提供对特殊地址的稳定访问。当要求使用 volatile 声明的变量的值的时候，系统总是重新从它所在的内存读取数据，即使它前面的指令刚刚从该处读取过数据。

虽然volatile在嵌入式方面应用比较多，但是在PC软件的多线程中，volatile修饰的临界变量也是非常实用的。

[聊聊C++的mutable和volatile](https://www.jb51.net/article/195277.htm#:~:text=C%2B%2B%E4%B8%AD%E4%BF%AE%E9%A5%B0%E6%95%B0%E6%8D%AE%E5%8F%AF%E5%8F%98%E7%9A%84%E5%85%B3%E9%94%AE%E5%AD%97%E6%9C%89%E4%B8%89%E4%B8%AA%EF%BC%9A%20const%20%E3%80%81%20volatile%20%E5%92%8C%20mutable%20%E3%80%82%20const,mutable%20%E6%81%B0%E5%A5%BD%E7%9B%B8%E5%8F%8D%EF%BC%8C%E6%8C%87%E7%A4%BA%E6%95%B0%E6%8D%AE%E6%80%BB%E6%98%AF%E5%8F%AF%E5%8F%98%E7%9A%84%E3%80%82%20mutable%20%E5%92%8C%20volatile%20%E5%9D%87%E5%8F%AF%E4%BB%A5%E5%92%8C%20const%20%E6%90%AD%E9%85%8D%E4%BD%BF%E7%94%A8%EF%BC%8C%E4%BD%86%E4%B8%A4%E8%80%85%E5%9C%A8%E4%BD%BF%E7%94%A8%E4%B8%8A%E6%9C%89%E6%AF%94%E8%BE%83%E5%A4%A7%E5%B7%AE%E5%88%AB%E3%80%82)

#### 一个参数可以既是 const 又是 volatile 吗

可以，用const和volatile同时修饰变量，表示这个变量在程序内部是只读的，不能改变的，只在程序外部条件变化下改变，并且编译器不会优化这个变量。每次使用这个变量时，都要小心地去内存读取这个变量的值，而不是去寄存器读取它的备份。

注意：**在此一定要注意const的意思，const只是不允许程序中的代码改变某一变量，其在编译期发挥作用，它并没有实际地禁止某段内存的读写特性。**

### explicit

普通函数是能够被隐式调用（如使用=），而 explicit 构造函数只能被显式调用。

explicit 是用来防止隐式转换的，它只对一个实参的构造函数有效，且只允许出现在类内的构造函数声明处。

```C++
class Test1
{
public:
    int num;
    char *str;
    Test1(int n, char *s)
    {
        num = n, str = s;
        cout << "call Test1(int n, char *s)\n";
    }
};

class Test2
{
public:
    int num;
    char *str;
    string type_info;

    explicit Test2(int n, char *s) : num(n), str(s)
    {
        cout << "call explicit Test2(int n, char *s)\n";
    }

    explicit Test2(string) : type_info("call explicit Test2(string)\n")
    {
        cout << type_info;
    }

    explicit Test2(char) : type_info("call explicit Test2(char)\n")
    {
        cout << type_info;
    }

    Test2(int) : type_info("call explicit Test2(int)\n") { cout << type_info; }

    explicit Test2(short) : type_info("call explicit Test2(short)\n")
    {
        cout << type_info;
    }
};

int main(int argc, char *argv[])
{
    Test1 t1 = {12, "hello..."}; // 隐式调用成功
    //Test2 t2 = { 12, "hello..." };		// 编译错误，不能隐式调用其构造函数
    Test2 t3(12, "hello..."); // 显式调用成功
    short n = 42;
    Test2 t4 = n; // 虽然 n 是 short 类型，但因为 explicit Test2(short) 不能隐式调用，故退而求其次把 n 转换成 int 调用 Test2(int)
    Test2 t5(n);  // 显示调用 explicit Test2(short)
}
/* 打印
call Test1(int n, char *s)
call explicit Test2(int n, char *s)
call explicit Test2(int)
call explicit Test2(short)
*/
```

### const

```C++
const Stock &Stock::topval(const Stock & s) const
{......}
//有两只股票，返回价格高的那一只股票【PLUS 363，365】
```

该函数显式的访问一个对象（参数），又隐式的访问另一个对象（调用的对象），并返回其中一个对象的引用。参数中的 const 表明，该函数不会修改被显式访问的对象（不会修改参数指针指向的内容），而括号后的 const 表明，该函数不会修改被隐式地访问的对象（该类方法 Stock::topval() 不会修改类里的数据），最前面的 const 表明函数的返回值不能被修改。

#### const形参和实参

当形参有顶层`const`时，传递给它常量对象或非常量对象都是可以的。

可以使用非常量对象初始化一个底层`const`形参，但是反过来不行。

把函数不会改变的形参定义成普通引用会极大地限制函数所能接受的实参类型，同时也会给别人一种误导，即函数可以修改实参的值。

顶层cosnt作形参，不会重载。如：

```C++
#define do_something std::cout << "hello" << std::endl;
void fun(int *const i) { do_something };
void fun(int *i) { do_something }; // 错误，重复定义了fun(int)
/*
t.cpp:20:6: error: redefinition of ‘void fun(int*)’
 void fun(int *i) { do_something }; // 错误，重复定义了fun(int)
      ^~~
t.cpp:19:6: note: ‘void fun(int*)’ previously defined here
 void fun( int *const i) { do_something };
      ^~~
*/
```

【PRIMER 191， 207】

#### 函数返回引用

返回引用能节省调用拷贝（复制）构造函数生成的副本所需的时间和析构函数删除副本所需的时间。但并不总是可以返回引用，函数不能返回在函数中创建的临时对象的引用，因为当函数结束，临时对象就消失了。
【PLUS 526】

引用返回左值【PRIMER 202】

一般地：可以取地址，有名字的就是左值；反之，右值。

```C++
char &get_val (string &str, string::size_type ix)
{
    return str[ix];
}
int main()
{
    string s("a value");
    get_val(s, 0) = 'A'; // 函数返回引用可作为左值（如果是常量引用则不可），将s[0]的值改为A
    return 0;
}
```

#### const作用

- 修饰变量，说明该变量不可以被改变；

- 修饰指针，分为指向常量的指针和指针常量；

- 修饰函数引用参数，即避免了拷贝，又避免了函数对引用值的修改；

  如`void fun(A const &a);`A是用户自定义类型。相比于值传递减少了临时对象的构造、复制、析构过程，用 const 修饰引用，避免函数通过引用修改 a。
  
- 修饰函数返回值，说明该返回值不能被修改，且该返回值只能赋值给加 const 修饰的同类型变量

- **修饰类的成员函数，说明在该成员函数内不能修改成员变量。**

*默认情况下，`const`对象被设定成仅在文件内有效。当多个文件中出现了同名的`const`变量时，其实等同于在不同文件中分别定义了独立的变量。【PRIMER 54】*

如果想在多个文件间共享`const`对象：

- 若`const`对象的值在编译时已经确定，则应该定义在头文件中。其他源文件包含该头文件时，不会产生重复定义错误。

- 若`const`对象的值直到运行时才能确定，则应该在头文件中声明，在源文件中定义。此时`const`变量的声明和定义前都应该添加`extern`关键字。

  ```c++
  // file_1.cc 定义并初始化一个常量，该常量能被其它文件访问
  extern const int bufSize = fcn();
  // file_1.h
  extern const int bufSize;   // 与file_1.cc中定义的是同一个
  ```

**const使用**

```C++
// 类
class A
{
private:
    const int a;                // 常对象成员，只能在初始化列表赋值

public:
    // 构造函数
    A() : a(0) { };
    A(int x) : a(x) { };        // 初始化列表

    // 后置const可用于对重载函数的区分
    int getValue();             // 普通成员函数
    int getValue() const;       // 常成员函数，不得修改类中的任何数据成员的值
};

void function()
{
    // 对象
    A b;                        // 普通对象，可以调用全部成员函数
    const A a;                  // 常对象，只能调用常成员函数、更新常成员变量
    const A *p = &a;            // 常指针
    const A &q = a;             // 常引用

    // 指针
    char greeting[] = "Hello";
    char* p1 = greeting;                // 指针变量，指向字符数组变量
    const char* p2 = greeting;          // 指针变量，指向字符数组常量
    char* const p3 = greeting;          // 常指针，指向字符数组变量
    const char* const p4 = greeting;    // 常指针，指向字符数组常量
}

// 函数
void function1(const int Var);           // 传递过来的参数在函数内不可变
void function2(const char* Var);         // 参数指针所指内容为常量
void function3(char* const Var);         // 参数指针为常指针
void function4(const int& Var);          // 引用参数在函数内为常量

// 函数返回值
const int function5();      // 返回一个常数
const int* function6();     // 返回一个指向常量的指针变量，使用：const int *p = function6();
int* const function7();     // 返回一个指向变量的常指针，使用：int* const p = function7();
```

#### const修饰指针

指针本身是一个独立的对象，它又可以指向另一个对象。所以指针和 const 同时使用时，有两种情况：【PRIMER 57】

```cpp
int i = 0;
int *const j = &i; // 顶层 const
// 指针常量,指向不可变地址的指针，但可以对它指向的内容进行修改。
// 指针j指向i，const修饰指针j本身，
// 所以不允许修改j，但可以通过j修改i的值
const int *k = &i; // 底层 const
// 常量指针，指向常量的指针，该指针指向的地址里的内容不可变。
// 指针k指向i，const修饰k指向的i，
// 所以可以修改k，但不可以通过k修改i的值
int const *p = &i; // 底层 const
// 即 const int *p，同上，为常量指针。
// const 修饰离右边最近的那一个，int const *p 等价于 const int *p
// 都可以理解为 const 修饰（*p）而不是 p，那么 p 可变,p 指向的值不可变
const int * const p = &i;
// p 只能指向 i，且 p 指向的 i 也不可变
```

#### constexpr和常量表达式

【PRIMER 58】

*常量表达式（constant expressions）指值不会改变并且在编译过程就能得到计算结果的表达式。*

一个对象是否为常量表达式由它的数据类型和初始值共同决定。

```c++
const int max_files = 20;           // max_files is a constant expression
const int limit = max_files + 1;    // limit is a constant expression
int staff_size = 27;        // staff_size is not a constant expression
const int sz = get_size();  // sz is not a constant expression
```

C++11允许将变量声明为`constexpr`类型以便由编译器来验证变量的值是否是一个常量表达式。

```c++
constexpr int mf = 20;          // 20 is a constant expression
constexpr int limit = mf + 1;   // mf + 1 is a constant expression
constexpr int sz = size();      // ok only if size is a constexpr function
```

指针和引用都能定义成`constexpr`，但是初始值受到严格限制。`constexpr`指针的初始值必须是0、`nullptr`或者是存储在某个固定地址中的对象。

函数体内定义的普通变量一般并非存放在固定地址中，因此`constexpr`指针不能指向这样的变量。相反，函数体外定义的变量地址固定不变，可以用来初始化`constexpr`指针。

*在`constexpr`声明中如果定义了一个指针，限定符`constexpr`仅对指针本身有效，与指针所指的对象无关。`constexpr`把它所定义的对象置为了顶层`const`。*

```c++
const int *p = &i;			// p是一个指向整型常量的指针：底层const，p可变，但p指向的内存里的值不可被修改。
constexpr int *p2 = &i;     // p2是指向整数的常量指针：顶层const，p2不可变，但可通过p2修改其指向的内存里面的值
constexpr const int *p3 = &i;   // p3是指向const int的const指针，可以理解为const int *const p3 = &i;
```

`const`和`constexpr`限定的值都是常量。但`constexpr`对象的值必须在编译期间确定，而`const`对象的值可以延迟到运行期间确定。

建议使用`constexpr`修饰表示数组大小的对象，因为数组的大小必须在编译期间确定且不能改变。

#### const 与 #define

```C++
#define PI 3.1415926
const float pi = 3.1415926;
```

- const 常量有数据类型，而宏常量没有数据类型。编译器可以对前者进行类型安全检查。而对后者只进行字符替换，没有类型安全检查，并且在字符替换可能会产生意料不到的错误 。
- 宏定义是直接替换，它的生命周期止于编译期，不会分配内存，存储于程序的代码段中；
  const 常量存在于程序的数据段，并分配了实际的内存。

### mutable

使用关键字`mutable`可以声明可变数据成员（mutable data member）。可变数据成员永远不会是`const`的，即使它在`const`对象内。因此`const`成员函数可以修改可变成员的值。

```c++
class Screen 
{
public:
    void some_member() const;
private:
    mutable size_t access_ctr;  // may change even in a const object
    // other members as before
};

void Screen::some_member() const
{
    ++access_ctr;   // keep a count of the calls to any member function
    // whatever other work this member needs to do
}
```

### 存储类

#### auto

C++ 11 以来，auto 关键字用于两种情况：声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符。 

auto是类型推导，让使用者获得动态语言的使用体验；但是有区别，那就是 auto 声明的变量类型，你可以不知道，但是编译器一定要知道，这样才不会报错。 

根据初始化表达式自动推断被声明的变量的类型，如：

```cpp
auto a; 							// 报错！a未初始化，编译器推算不出来 a 是什么类型，就不知道要开辟多大的空间。
auto f = 3.14;      				// double
auto s("hello");  					// const char*
auto z = new auto(9); 				// int*
auto x1 = 5, x2 = 5.0, x3 = 'r';  	// 报错！
/*
当在同一行中定义多个变量时，编译器只对第一个类型进行推导，
然后用推导出来的类型定义其它变量
*/
```

注意：  

- auto 不可作为函数的参数：参数要被编译成指令，auto 做参数，会不知道要开辟多大的空间。
- auto 不可直接用来声明数组：因为不知道要开辟多大空间。

*auto 在实际中最常见的优势用法是 C++11 提供的新式 for 循环，还有 lambda 表达式等进行配合使用。*

#### static作用

- 修饰变量：修改变量的存储区域和生命周期，使变量存储在静态区，变量只初始化一次。
  - 当修饰全局变量的时候，就是静态全局变量。静态全局变量与非静态全局变量都是存储在静态区，但是它们的作用域不一样：静态全局变量的作用域只在该文件里有效（文件作用域），而非静态全局变量的作用域是在整个源程序里有效。
  - 当修饰局部变量的时候，一般用在函数体中，静态局部变量的作用域与普通局部变量一样，只在该函数中有效，但静态局部变量存储在静态区，在函数调用结束会维持其值不变，下次调用该函数不会初始化而是直接使用上一次调用时的值。


- 修饰普通函数：表明函数的作用范围，仅在定义该函数的文件内才能使用。在多人开发项目时，为了防止与他人命名的函数重名，可以将函数定义为 static。

- 修饰成员变量：静态成员变量用来表示唯一的、可共享的成员变量。它可以在同一个类的所有对象中被访问。静态成员变量只有唯一的一份实体。不需要生成对象就可以访问该成员。

  static 成员变量必须**在类声明的外部进行初始化，以示与普通数据成员的区别**。在类外部定义静态成员时，不能重复`static`关键字，其只能用于类内部的声明语句。【PRIMER 270】

  例如：`int Class_name::static_val = 5;`

  static 成员变量和普通 static 变量一样，都在内存分区的**全局数据区**分配内存，到程序结束后释放。这就意味着，static 成员变量不随对象的创建而分配内存，也不随对象的销毁而释放内存。而普通成员变量在对象创建时分配内存，在对象销毁时释放内存。

- 修饰成员函数：静态成员函数使得不需要生成对象就可以访问该函数。**静态成员函数和静态成员变量一样，不属于类，所以静态成员函数不含 this 指针，也就无法访问类的非静态成员。**

【对1，2条的总结】

static 最重要的一条在于修饰普通变量与普通函数时，隐藏普通变量与普通函数。因为未加 static 前缀的全局变量和函数都具有全局可见性。

##### 静态数据成员与全局变量相比的优势

- 静态数据成员没有进入程序的全局命名空间，因此不存在与其他全局变量名字冲突的可能；
- 使用静态数据成员可以隐藏信息。因为静态数据成员可以是 private 成员，而全局变量不能；

#### extern

extern 存储类用于提供一个全局变量的引用，全局变量对所有的程序文件都可见。使用 'extern' 时，对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置(定义只有一次，不可重复定义)。 

多个文件定义了一个可以在其他文件中使用的全局变量或函数时，可以在其他文件中使用 extern 来得到已定义的变量或函数的引用。可以这么理解，extern 是用来在另一个文件中声明一个全局变量或函数。

### 类型转换运算符

 C++ 中四种类型转换是：`static_cast, dynamic_cast, const_cast, reinterpret_cast `

```C++
cast-name<type>(expression) 
// type是转换的目标类型，expression 是被转换的值。
```

- const_cast(常量转换)

  用于将 const 变量转为非 const ，也可以去除 volatile，除此之外不允许任何类型转换。即常量指针被转换成非常量指针，并且仍然指向原来的对象；常量引用被转换成非常量引用，并且仍然引用原来的对象。

- static_cast(静态转换)

  任何编写程序时能够明确的类型转换都可以使用 static_cast（static_cast 不能转换掉底层 const，volatile 和 __unaligned 属性）。由于不提供运行时的检查，所以叫 static_cast，因此，需要在编写程序时确认转换的安全性。

  主要在以下几种场合中使用：

  - 用于类层次结构中，父类和子类之间指针和引用的转换；进行上行转换，把子类对象的指针/引用转换为父类指针/引用，这种转换是安全的；进行下行转换，把父类对象的指针/引用转换成子类指针/引用，这种转换是不安全的，需要编写程序时来确认；
  - 用于基本数据类型之间的转换，例如把 int 转 char，int 转 enum 等，需要编写程序时来确认安全性；
  - 把 void 指针转换成目标类型的指针（这是极其不安全的）；

- dynamic_cast(动态转换)

  用于动态类型转换。**只能用于含有虚函数的类，用于类层次间的向上和向下转化，只能转指针或引用**。向下转化时，如果是非法的对于指针返回 nullptr，对于引用抛异常。要深入了解内部转换的原理。

  向上转换：指的是子类向基类的转换。此时与 static_cast 和隐式转换一样，都是非常安全的。 注意菱形继承中的向上转换要指明路径。

  向下转换：指的是基类向子类的转换；

  它通过变量运行时的类型和要转换的类型是否相同，来判断是否能够进行向下转换。 

  **为什么只能用于含有虚函数的类？**

  因为类中存在虚函数，说明它可能有子类，这样才有类型转换的情况发生，由于运行时类型检查需要运行时类型信息，而这个信息存储在类的虚函数表中，只有定义了虚函数的类才有虚函数表。 

  [static_cast和dynamic_cast](https://zhuanlan.zhihu.com/p/489998070)

- reinterpret_cast(重解释)

  几乎什么都可以转，比如将 int 转指针，可能会出问题，尽量少用； 

####   为什么不使用 C 的强制转换

  C 的强制转换表面上看起来功能强大什么都能转，但是转化不够明确，不能进行错误检查，容易出错。 

### C++转换运算符

转换运算符是C++中一种特殊的成员函数，允许将类对象转换为其他类型。

转换运算符的语法如下：

```cpp
operator Type() const;
```

其中：

- 不需要返回类型（隐含返回类型为Type）
- 通常声明为const，因为转换不应该修改对象
- 不接受参数

```c++
#include <iostream>

class Money
{
private:
    double amount;

public:
    Money(double amount = 0.0) : amount(amount)
    {
        std::cout << "构造Money对象: " << amount << std::endl;
    }

    // 声明double转换
    operator double() const
    {
        std::cout << "执行Money到double的转换" << std::endl;
        return amount;
    }

    // 声明int转换
    operator int() const
    {
        std::cout << "执行Money到int的转换" << std::endl;
        return static_cast<int>(amount);
    }

    void display() const
    {
        std::cout << "Money金额: $" << amount << std::endl;
    }
};

int main()
{
    Money wallet(42.50);
    wallet.display();

    // 显式转换
    double balance = static_cast<double>(wallet);
    std::cout << "显式转换后的余额: " << balance << std::endl;

    // 隐式转换
    double amount = wallet;  // 自动调用operator double()
    std::cout << "隐式转换后的金额: " << amount << std::endl;

    // 显式转换到int
    int explicit_dollars = static_cast<int>(wallet);
    std::cout << "显式转换整数部分: $" << explicit_dollars << std::endl;

    // 隐式转换到int
    int dollars = wallet;
    std::cout << "整数部分: $" << dollars << std::endl;

    return 0;
}
/*
构造Money对象: 42.5
Money金额: $42.5
执行Money到double的转换
显式转换后的余额: 42.5
执行Money到double的转换
隐式转换后的金额: 42.5
执行Money到int的转换
显式转换整数部分: $42
执行Money到int的转换
整数部分: $42
*/
```



### this指针

每个非静态成员函数（包含构造函数和析构函数）都有一个`this`指针，`this`指针指向调用对象，`this`是地址，如果要引用调用对象本身，用`*this`。

（只有成员函数才有 this 指针，静态成员函数和友元函数都不含 this 指针）

当一个成员函数被调用时，自动向它传递一个隐含的参数，该参数是一个指向这个成员函数所在的对象的指针。this 指针被隐含地声明为: `ClassName *const this`，这意味着不能给 `this` 指针赋值；在 `ClassName` 类的 `const` 成员函数中，`this` 指针的类型为：`const ClassName* const`，这说明 `this` 指针所指向的这种对象是不可修改的（即不能对这种对象的数据成员进行赋值操作）。

一个类的成员函数只有一份，并不是每一个对象对应一个单独的成员函数体，而成员函数之所以能把属于此类的各个对象的数据区分开，就在于每次执行类成员函数时，都会把当前的`this`指针（对象首地址）传入成员函数，函数体内所有对类数据成员的访问都会转化为`this->数据成员`的方式。

【PLUS 364】

【注意】静态成员函数里，不能使用 this 指针：

静态成员函数并不是针对某个类的实例对象，而是属于整个类的，为所有的对象实例所共有。他在作用域的范围内是全局的，独立于类的对象之外的。他只对类内部的静态成员变量做操作。当实例化一个类的对象时候，里面不存在静态成员的。this 指针是相当于一个类的实例的指针，this 是用来操作对象实例的内容的，既然静态成员函数和变量都是独立于类的实例对象之外的，它就不能用 this 指针，也不能操作非静态成员。

### 虚函数

```C++
/*BrassPlus 是 Brass 的子类， ViewAcct() 是两个类中都有的方法。
由于 bp是父类指针，如果基类不用虚方法那么就会调用基类的 ViewAcct() 方法
若在基类中将 ViewAcct() 声明为虚，则 bp->ViewAcct() 根据对象类型（BrassPlus）调用 BrassPlue::ViewAcct()方法*/
BrassPlus ophelia;
Brass *bp;
bp = &ophelia;
bp->ViewAcct();  // 是调用子类还是父类的 ViewAcct() 方法？
```

【PLUS 503】

当且仅当通过指针或引用调用虚函数时，才会在运行过程解析该调用，也只有在这种情况下对象的动态类型有可能与静态类型不同。

在派生类中覆盖某个虚函数时，可以再次使用`virtual`关键字说明函数性质，但这并非强制要求。因为一旦某个函数被声明为虚函数，则在所有派生类中它都是虚函数。

在派生类中覆盖某个虚函数时，该函数在基类中的形参必须与派生类中的形参严格匹配。

派生类可以定义一个与基类中的虚函数名字相同但形参列表不同的函数，但编译器会认为该函数与基类中原有的函数是相互独立的，此时派生类的函数并没有覆盖掉基类中的版本。这往往会发生错误，因为我们原本希望派生类可以覆盖基类中的虚函数，但是一不小心把形参列表写错了。想调试并发现这样的错误非常困难，C++11允许派生类使用`override`关键字显式地注明虚函数。如果`override`标记了某个函数，但该函数并没有覆盖已存在的虚函数，编译器将报告错误。`override`位于函数参数列表之后。

```c++
struct B
{
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1 : B 
{
    void f1(int) const override;    // 正确：f1() 与基类中的 f1() 匹配
    void f2(int) override;      	// 错误：B 没有形如 f2(int) 的函数
    void f3() override;     // 错误：f3() 不是虚函数
    void f4() override;     // 错误：B 没有名为 f4() 的函数
}
```

**与禁止类继承类似，函数也可以通过添加`final`关键字来禁止覆盖操作**。

```c++
struct D2 : B
{
    // 从 B 继承 f2() 和 f3(),覆盖 f1(int)
    void f1(int) const final;   // 不允许后续的其他类覆盖 f1(int)
};
struct D3 : D2
{
    void f2();	// 正确：覆盖从 B 继承而来的 f2()
    void f1(int) const;	// 错误：D2 已经将 f1 声明成 final。
}
```

`final`和`override`关键字出现在形参列表（包括任何`const`或引用修饰符）以及尾置返回类型之后。

虚函数也可以有默认实参，每次函数调用的默认实参值由本次调用的静态类型决定。如果通过基类的指针或引用调用函数，则使用基类中定义的默认实参，即使实际运行的是派生类中的函数版本也是如此。

如果虚函数使用默认实参，则基类和派生类中定义的默认实参值最好一致。

【PRIMER 536~538】

#### 回避虚函数

在某些情况下，我们希望对虚函数的调用不要进行动态绑定，而是强迫执行虚函数的某一个特定版本。使用作用域运算符`::`可以强制执行虚函数的某个版本，不进行动态绑定。

```c++
// 强行调用 Quote 的 net_price 函数而不管 baseP 的动态类型到底是什么
double undiscounted = baseP->Quote::net_price(42);
```

通常情况下，只有成员函数或友元中的代码才需要使用作用域运算符来回避虚函数的动态绑定机制。

**如果一个派生类虚函数需要调用它的基类版本，但没有使用作用域运算符，则在运行时该调用会被解析为对派生类版本自身的调用，从而导致无限递归。**

【PRIMER 539】

也可以参考例子：[具有默认实参的虚函数及虚函数回避机制](https://blog.csdn.net/gettogetto/article/details/50117769)

#### 虚函数原理

虚函数是通过虚函数表实现的。如果一个类中有一个虚函数，则系统会为这个类分配一个指针成员指向一张虚函数表（vtbl），表中每一项指向一个虚函数地址，虚函数表实际上就是一个函数指针数组。  

[C++虚函数原理](https://blog.csdn.net/weixin_40673608/article/details/88551020)

[C++中的虚函数表实现机制以及用C语言对其进行的模拟实现](https://blog.twofei.com/496/)

#### [虚函数是否可以内联](https://www.yuque.com/huihut/interview/readme#ikirca)

- 虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
- 内联是在编译期间编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。
- `inline virtual` 唯一可以内联的时候是：编译器知道所调用的对象是哪个类，这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。

#### 虚析构函数

```C++
// Employee 是基类，Singer 是派生类
Employee *pe = new Singer;
...
delete pe;  // call ~Employee() or ~Singer()?
```

如果基类中的析构函数**不是虚的**，就只调用对应于指针类型(Employee)的析构函数，但实际中，是想调用派生类的析构函数。如果基类的析构函数是虚的，将调用相应对象类型(Singer)的析构函数，然后自动调用基类的析构函数。因此，使用虚析构函数可以保证正确的析构函数序列被调用。
【PLUS 501，505】

```C++
// Employee 是基类，Singer 是派生类
Singer *pe = new Singer;
...
delete pe;  // 先调用 ~Singer() 再调用 ~Employee()，
			// 因为 pe 是 Singer* 类型指针，而不是 Employee* 类型指针。
```

#### 静态联编和动态联编

将源程序中的函数调用解释为执行特定的函数代码块被称为函数名联编。在 C 语言中由于不支持函数重载，这很容易，在 C++ 中，由于支持函数重载，编译器必须查看函数的参数才知道调用的是哪一个函数。C++ 在编译过程中就可以完成这种联编，故称为静态联编，又称为早期联编。编译器总是对非虚方法使用静态联编。

然而虚函数使编译器不知道在编译时到底用哪一个函数，因为编译器不知道用户将选择哪种类型的对象，所以编译器必须生成能够在程序运行时选择正确的虚函数的代码，这被称之为动态联编，也被称为晚期联编。

【PLUS 501】

#### 在构造函数和析构函数内调用虚函数

**从编程习惯来看，在构造和析构函数中，不要用虚函数。**如果必须用，那么分离出一个Init函数和一个close函数，实现相关功能即可。假设在构造函数和析构函数内调用了虚函数，那么：

- 如果有继承，构造函数会先调用父类构造函数，而如果构造函数中有虚函数，此时子类还没有构造，所以此时的对象还是父类的，不会触发多态。更容易记的是基类构造期间，virtual函数不是virtual函数。

- 析构函数也是一样，子类先进行析构，这时，如果有virtual函数的话，子类的内容已经被析构了，执行父类的virtual函数。

- 非构造和析构函数内部，使用父类的指针调用虚函数是调用子类override的实现（前提是子类有重写）。

另一个解释[C++构造函数和析构函数调用虚函数时都不会使用动态联编](https://www.cnblogs.com/bonelee/p/5826196.html)

构造函数和析构函数调用虚函数时都不使用动态联编，如果在构造函数或析构函数中调用虚函数，则运行的是为构造函数或析构函数自身类型定义的版本。

原因分析：

- 不要在构造函数中调用虚函数的原因：因为父类对象会在子类之前进行构造，此时子类部分的数据成员还未初始化， 因此调用子类的虚函数是不安全的，故而C++不会进行动态联编。
- 不要在析构函数中调用虚函数的原因：析构函数是用来销毁一个对象的，在销毁一个对象时，先调用子类的析构函数，然后再调用基类的析构函数。所以在调用基类的析构函数时，派生类对象的数据成员已经“销毁”，这个时再调用子类的虚函数已经没有意义了。

示例如下：

```C++
#include <memory>
#include <iostream>

class A
{
public:
    A() { f1(); }
    virtual ~A() { f2(); }

    virtual void f1() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    virtual void f2() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

};

class B : public A
{
public:
    B() : A() { f1(); }
    virtual ~B() { f2(); };

#if 1  // 【１】
    virtual void f1() override { std::cout << __PRETTY_FUNCTION__ << std::endl;}
    virtual void f2() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
#endif
};

int main()
{
    A *b = new B(); // 在执行 A 的构造和析构时，是执行 A 自己的虚函数，即使子类 B 已经重写了父类虚函数

    b->f1(); // 多态

    delete b;
    return 0;
}

/*
$ g++ t.cpp -o main 
$ ./main 
virtual void A::f1()
virtual void B::f1()
virtual void B::f1()
virtual void B::f2()
virtual void A::f2()

### 如果关闭【1】处的宏，则只打印父类的虚函数 
$ g++ t.cpp -o main 
$ ./main 
virtual void A::f1()
virtual void A::f1()
virtual void A::f1()
virtual void A::f2()
virtual void A::f2()
*/
```

#### 有关虚函数的注意事项

- **构造函数不能是虚函数。**先构造父类对象，然后才能是子类对象，如果构造函数设为虚函数，那么当你在构造父类的构造函数时就不得不显式的调用构造，还有一个原因就是为了防错，试想如果你在子类中一不小心重写了个跟父类构造函数一样的函数，那么你的父类的构造函数将被覆盖，即不能完成父类的构造，就会出错。 
- 析构函数应当是虚函数，除非类不用做基类。即使类不用作基类，通常应给基类提供一个虚析构函数
- 友元不能是虚函数，因为友元不是类成员，只有类成员才能是虚函数
- 如果派生类没有重新定义函数，将使用该函数的基类版本。如果派生类位于派生链中，则将使用最新的虚函数版本
- 如果派生类重新定义函数，将隐藏同名基类方法，这不同于重载
- **模板函数不能是虚函数。**因为，类会在`vtbl`中存放类中的所有的虚函数的函数指针，而一个模板函数如果设计为虚函数是无法获悉这个模板函数会被实例化为哪些具体的函数。

【PLUS 503，504】

- 除构造函数之外的任何非静态函数都能定义为虚函数。`virtual`关键字只能出现在类内部的声明语句之前而不能用于类外部的函数定义。如果基类把一个函数声明为虚函数，则该函数在派生类中隐式地也是虚函数。
- 成员函数如果没有被声明为虚函数，则其解析过程发生在编译阶段而非运行阶段。

【PRIMER 528】

#### 纯虚函数

纯虚函数是一种特殊的虚函数，纯虚函数只是一个接口，是让派生类实现细节的，在纯虚函数中也可以定义具体实现，但没意义。**包含纯虚函数的类是抽象基类（ABC，abstract base class），它只能作为基类，不能创建对象。**可以从抽象基类派生出具体类（普通类），这些类可以创建对象。

```C++
class C
public:
	virtual int f1() = 0;  //函数原型中的 =0 使虚函数成为纯虚函数
	virtual double area() const = 0;  
	virtual ~C() {}
```

【PLUS 509，510】

#### 虚函数、纯虚函数

- 类里如果声明了虚函数，这个函数是实现的，哪怕是空实现，它的作用就是为了能让这个函数在它的子类里面可以被覆盖，这样的话，这样编译器就可以使用后期绑定来达到多态了。纯虚函数只是一个接口，是个函数的声明而已，它要留到子类里去实现。
- 虚函数在子类里面也可以不重载的；但纯虚函数必须在子类去实现。
- 虚函数的类用于 “实作继承”，继承接口的同时也继承了父类的实现。当然大家也可以完成自己的实现。纯虚函数关注的是接口的统一性，实现由子类完成。
- 带纯虚函数的类叫抽象类，这种类不能直接生成对象，而只有被继承，并重写其虚函数后，才能使用。

#### 抽象类与虚基类

类B、C继承类A；类D继承类B、C；按照正常的公有继承方式，类D中将包含2份类A的对象/方法。这样浪费存储空间，而且使用对象/方法时需要说明是从哪一个父类继承而来的。

 所以继承时将基类声明成虚基类，同一个虚基类的对象/方法，在子类中只会出现一次。

参考：[C++抽象基类与虚基类（C++ primer）](https://blog.csdn.net/pix_csdn/article/details/89761780)

### 继承

- 类派生列表中的访问说明符用于控制派生类从基类继承而来的成员是否对派生类的用户可见。

- 如果派生类没有覆盖其基类的某个虚函数，则该虚函数的行为类似于其他的普通函数，派生类会直接继承其在基类中的版本。

- C++标准并没有明确规定派生类的对象在内存中如何分布，**一个对象中继承自基类的部分和派生类自定义的部分不一定是连续存储的**。

- 每个类控制它自己的成员初始化过程，派生类必须使用基类的构造函数来初始化它的基类部分。**派生类的构造函数通过构造函数初始化列表来将实参传递给基类构造函数**。

```c++
// class Bulk_quote : public Quote
Bulk_quote(const std::string& book, double p, 
            std::size_t qty, double disc) :
    Quote(book, p), min_qty(qty), discount(disc) { }
```

除非特别指出，否则派生类对象的基类部分会像数据成员一样执行默认初始化。

派生类初始化时首先初始化基类部分，然后按照声明的顺序依次初始化派生类成员。

派生类可以访问基类的公有成员和受保护成员。

**如果基类定义了一个静态成员，则在整个继承体系中只存在该成员的唯一定义。如果某静态成员是可访问的，则既能通过基类也能通过派生类使用它。**

只有声明并定义的类才能被用作基类。

```c++
class Base { /* ... */ } ;
class D1: public Base { /* ... */ };
class D2: public D1 { /* ... */ };
```

*Base*是*D1*的直接基类（direct base），是*D2*的间接基类（indirect base）。最终的派生类将包含它直接基类的子对象以及每个间接基类的子对象。

C++11中，在类名后面添加`final`关键字可以禁止其他类继承它。

```c++
class NoDerived final { /* */ };    // NoDerived can't be a base class
class Base { /* */ };
// Last is final; we cannot inherit from Last
class Last final : Base { /* */ };  // Last can't be a base class
class Bad : NoDerived { /* */ };    // error: NoDerived is final
class Bad2 : Last { /* */ };        // error: Last is final
```

【PRIMER 529~533】

#### 访问控制

基类中成员的访问说明符和派生列表中的访问说明符都会影响某个类对其继承成员的访问权限。

派生访问说明符对于派生类的成员及友元能否访问其直接基类的成员没有影响，对基类成员的访问权限只与基类中的访问说明符有关。

派生访问说明符的作用是控制派生类（包括派生类的派生类）用户对于基类成员的访问权限。

- 如果使用公有继承，则基类的公有成员和受保护成员在派生类中属性不发生改变。
- 如果使用受保护继承，则基类的公有成员和受保护成员在派生类中变为受保护成员。
- 如果使用私有继承，则基类的公有成员和受保护成员在派生类中变为私有成员。

派生类到基类转换的可访问性（假定*D*继承自*B*）：

- 只有当*D*公有地继承*B*时，用户代码才能使用派生类到基类的转换。
- 不论*D*以什么方式继承*B*，*D*的成员函数和友元都能使用派生类到基类的转换。
- 如果*D*继承*B*的方式是公有的或者受保护的，则*D*的派生类的成员函数和友元可以使用*D*到*B*的类型转换；反之，如果*D*继承*B*的方式是私有的，则不能使用。

对于代码中的某个给定节点来说，如果基类的公有成员是可访问的，则派生类到基类的类型转换也是可访问的。

友元对基类的访问权限由基类自身控制，即使对于派生类中的基类部分也是如此。

友元关系不能继承，每个类负责控制各自成员的访问权限。

[c++ 派生类向基类转换的可访问性](https://www.cnblogs.com/FdWzy/p/12596238.html)

#### 改变成员的可访问性

使用`using`声明可以改变派生类继承的某个名字的访问级别。新的访问级别由该`using`声明之前的访问说明符决定。

```c++
class Base
{
public:
    std::size_t size() const { return n; }
protected:
    std::size_t n;
};

class Derived : private Base // 注意: 私有继承。继承而来的 size() 和 n 都是私有的
{ 
public:
   	// using 改变 size() 的可访问性为 public
    using Base::size;
protected:
    // using 改变 n 的可访问性为 protected
    using Base::n;
};
```

派生类只能为那些它可以访问的名字提供`using`声明。

默认情况下，使用`class`关键字定义的派生类是私有继承的，而使用`struct`关键字定义的派生类是公有继承的。

建议显式地声明派生类的继承方式，不要仅仅依赖于默认设置。

#### 不存在从基类向派生类的隐式转换

之所以存在派生类向基类的隐式转换，是因为每个派生类对象都包含一个基类部分，而基类的引用或指针可以绑定到该基类部分上。一个基类既可以独立存在，也可以作为派生类的一部分存在。如果基类对象不是派生类对象的一部分，则它只含有基类定义的成员，而不含有派生类定义的成员，所以用基类的指针去访问派生类中基类没有的方法或成员，必然出现错误。（**承诺过多**）【PRIMER 534】

#### 多重继承与虚继承以及消除二义性方法

```C++
class Person
{
	string s = "Person";
public:
	void sleep() { cout << s + " sleep" << endl; }
	void eat() { cout << s + " eat" << endl; }
};

class Author : public Person		// 标记【1】Author puplic 继承自 Person
{
	string s = "Author";
public:
	void writeBook() { cout << s + " wirte book" << endl; }
};

class Programmer : public Person	// 标记【2】
{
	string s = "Programmer"; 
public:
	void writeCode() { cout << s + " write Code" << endl; }
};

class Programmer_Author : public Programmer, public Author  // 多重继承
{
	string s = "Programmer_Author";
};


int main(int argc, char* argv[]) {
	Programmer_Author pa;
	pa.writeBook();
	pa.writeCode();
	//pa.eat();						// 标记【3】编译错误
	pa.Person::eat();
	pa.Programmer::sleep();
	return 0;
}
/* 打印
Author wirte book
Programmer write Code
Person eat
Person sleep
*/
```

标记【3】处编译错误，是因为通过多重继承 Programmer_Author 类拥有 Programmer 类和 Author 类的一份拷贝，而 Programmer 类和 Author 类都分别拥有 Person 类的一份拷贝，所以 Programmer_Author 类拥有 Person 的两份拷贝，在调用 Person 类的两份接口时，编译器不清楚需要调用哪一份拷贝，从而产生错误。

对于这个问题通常有两个解决方案：

-  加上范围解析运算符（域区分符）确定调用哪一份拷贝。比如 `pa.Programmer::sleep();`

- 使用虚拟继承，使得多重继承类 Programmer_Author 只有 Person 类的一份拷贝。

  ```C++
  // 在上面代码标记【1】标记【2】处加入 virtual 即可，这样 pa.eat(); 就不会产生错误了。
  class Author : virtual public Person		// 标记【1】
  class Programmer : virtual public Person	// 标记【2】
  ```

【总结】多重继承的优点是对象可以调用多个基类中的接口，但是容易出现继承上的二义性。

#### 多继承中构造函数的调用顺序

多继承中构造函数的调用顺序总结，构造顺序从上到下依次为：

1. 任何虚拟基类的构造函数按照它们被继承的顺序构造（而不是构造函数的初始化列表的顺序）；
2. 任何非虚拟基类的构造函数按照它们被构造的顺序构造；
3. 任何成员对象的构造按照它们声明的顺序构造，而不是在初始化列表中的顺序；
4. 类自身的构造函数；

### 右值引用

右值引用就是必须绑定到右值的引用。可以通过`&&`来获得右值引用。

一般而言，一个左值表达式表示的是一个对象的身份，而一个右值表达式表示的是对象的值。

```c++
int i = 42;			// ok：i 是左值
int &r = i;         // ok：r 是左值引用
int &&rr = i;       // error: 不能将一个右值引用绑定到左值上
int &r2 = i * 42;   // error: i * 42 是右值，而 r2 是左值引用
const int &r3 = i * 42;    // ok: 可以绑定一个 const 左值引用到右值，可以见下文的实例函数 void show1(const int &a)
int &&rr2 = i * 42;        // ok: 将右值引用 rr2 绑定到右值上
```

右值引用只能绑定到即将被销毁，并且没有其他用户的临时对象上。使用右值引用的代码可以自由地接管所引用对象的资源。

变量表达式都是左值，所以不能将一个右值引用直接绑定到一个变量上，即使这个变量的类型是右值引用也不行。

```c++
int &&rr1 = 42;     // ok: rr1 是右值引用
//int &&rr2 = rr1;    // error: 但此时作为表达式的 rr1 是左值，而 rr2 却是右值引用
int &&rr3 = std::move(rr1);
int &&rr4 = rr1 * 1;
rr1 = 5;
cout << "rr1 =" << rr1 << "   rr3 = " << rr3 << "   rr4 = " << rr4 << endl;
// 打印: rr1 =5   rr3 = 5   rr4 = 42
```

```C++
#include <iostream>

void show1(const int &a)
{
    //a = 3; // 不可修改
    std::cout << a << std::endl;
}

void show2(int &&a)
{
    a = 3; // 可修改，形参必须右值引用
    std::cout << a << std::endl;
}

int main()
{
    int b = 5;
    // 下面两次调用都是针对临时值，而不是变量，可以观察到 const 左值引用与右值引用的区别
    show1(9);						// 9
    show2(9);						// 3
    std::cout << b << std::endl;	// 5

    return 0;
}
```

调用`move`函数可以获得绑定在左值上的右值引用，此函数定义在头文件*utility*中。

#### 左值与右值

**左值持久，右值短暂**：左值有持久的状态，而右值要么是字面常量，要么是表达式求值的过程中创建的临时对象。

由于右值引用只能绑定到临时对象上，可知：

- 所引用的对象将要被销毁
- 该对象没有其他用户

这两个特性意味着：使用右值引用的代码可以自由地接管所引用的对象的资源。

【PRIMER 471, 472】

## 智能指针

智能指针主要用于管理在堆上分配的内存，它将普通的指针封装为一个栈对象。当栈对象的生存周期结束后，会在析构函数中释放掉申请的内存，从而防止内存泄漏。C++  11中最常用的智能指针类型为`shared_ptr`，它采用引用计数的方法，记录当前内存资源被多少个智能指针引用。该引用计数的内存在堆上分配。当新增一个时引用计数加 1 ，当过期时引用计数减一。只有引用计数为 0 时，智能指针才会自动释放引用的内存资源。对shared_ptr进行初始化时不能将一个普通指针直接赋值给智能指针，因为一个是指针，一个是类，可以通过构造函数传入普通指针。（ 从`auto_ptr`也带一点，虽然C++ 11已经遗弃）

`std::auto_ptr<string> ptr(new string);`

`std::shared_ptr<string> p1;`    

`std::shared_ptr<list<int>> p2;`  

```C++
auto_ptr<char*> ap(new char*);
*ap = "ap1";
*ap = "ap2";
char **bp = new char*;
*bp = "bp1";
cout << *ap << endl;	// "ap2"
cout << *bp << endl;	// "bp1"
```

```C++
#include <memory>
double *p = new double;
shared_ptr<double> pshared(p);		// 合法，显示转换，explicit conversion
//shared_ptr<double> pshared = p;  // 不合法，隐式转换，implicit conversion
```

```C++
int main(int argc, char* argv[]) {
	string str("hello world!");
	// 程序能运行，但是在要释放 pshared 指向的内存时会出错
	// 因为 str 不是存在堆中，当 pshared 过期时，delete 运算符会用于非堆内存，造成错误
	shared_ptr<string> pshared(&str);
	cout << *pshared << endl;
	getchar();
}
```

- **auto_ptr 是C++98提供的解决方案，C++11已经摒弃，并提供了以下几种方案**

- shared_ptr 被称为共享指针，用于管理多个智能指针共同拥有的动态分配对象， 

- unique_ptr 唯一拥有指定的对象，相比普通指针，拥有 RAII 的特性使得程序出现异常时，动态资源可以得到释放。 

  RAII，Resource Acquisition Is Initialization，资源获取即初始化： 其核心是把资源和对象的生命周期绑定，对象创建获取资源，对象销毁释放资源 

-  weak_ptr 是为了配合shared_ptr而引入的一种智能指针，因为它不具有普通指针的行为，没有重载operator*和->,它的最大作用在于协助shared_ptr工作，像旁观者那样观测资源的使用情况。 

### 智能指针的内存泄露以及解决方法

当两个对象相互使用一个 `shared_ptr` 成员变量指向对方，会造成循环引用，使引用计数失效，从而导致内存泄漏。

为了解决循环引用导致的内存泄漏，引入了 `weak_ptr` 弱指针，`weak_ptr` 的构造函数不会修改引用计数的值，从而不会对对象的内存进行管理，其类似一个普通指针，但不指向引用计数的共享内存，但是其可以检测到所管理的对象是否已经被释放，从而避免非法访问。  

### 为什么摒弃 auto_ptr

```C++
auto_ptr<string> p1(new string("hello"));
auto_ptr<string> p2;
p2 = p1;		
// 当 p1, p2 过期时，将删除同一个对象两次
```

**解决之道：**

- 定义复制运算符，使之执行深复制
- 建立所有权概念，使同时只有一个智能指针可拥有它。这样，只有拥有对象的智能指针有权析构该对象，这是auto_ptr 的策略，unique_ptr 的策略更严格。
- 创建智能更高的指针，跟踪引用特定对象的智能指针数。这称为引用计数。

```C++
int main(int argc, char* argv[]) {
	auto_ptr<string> p1(new string("hello"));
	auto_ptr<string> p2;
	cout << *p1 << endl;  // 正常打印
	p2 = p1;			  // p1 丧失了对 string 对象的所有权，p1 此时是空指针
	cout << *p1 << endl;  // 编译通过，但运行时报错，因为试图提领空指针
	getchar();
}
//	将 auto_ptr 换成 unique_ptr，编译器认为语句 p2 = p1; 非法，在编译阶段报错（因为 p1 不是临时右值）。 
//	将 auto_ptr 换成 shared_ptr，编译运行阶段都没问题，正常打印。
//	shared_ptr 采用的策略是引用计数，赋值时，计数加一，过期时，计数减一。仅当最后一个指针过期时，才调用 delete。
```

```C++
shared_ptr<string> p1(new string("hello"));
shared_ptr<string> p2(p1);		// 合法，将右值 p1 赋给 p2
```

```C++
unique_ptr<string> p1(new string("hello"));
//shared_ptr<string> p2(p1);		// 不合法，右值 p1 是 unique_ptr，若能赋给 p2，则 p1，p2 指向同一个对象，导致 p1 不合法，此语句编译不通过
//unique_ptr<string> p2(p1);		// 不合法，p1 不是临时右值，注意临时。
```

```C++
unique_ptr<string> foo() {
	unique_ptr<string> p1(new string("hello"));
	return p1;
}
// 函数返回的 unique_ptr<string> 为临时右值，此时可赋给另一个 unique_ptr 型指针
int main(int argc, char* argv[]) {
	unique_ptr<string> p2(foo());
}
```

[左值，右值](https://www.jianshu.com/p/d19fc8447eaa)

### 更多用法（C++ 11）

`shared_ptr`和`unique_ptr`都支持的操作：

![12-1](assets/C-plus-plus/12-1.png)

`shared_ptr`独有的操作：

![12-2](assets/C-plus-plus/12-2.png)

`make_shared`函数（定义在头文件*memory*中）在动态内存中分配一个对象并初始化它，返回指向此对象的`shared_ptr`。

### 智能指针与普通指针的转换

```c++
void show(string s)
{
    cout << s << endl;
}

int main()
{
    std::shared_ptr<std::string> s = std::make_shared<std::string>("hello\n");
    show(*s.get()); // s.get() 获得内置指针 string *，需要解引用传到show()中
    // 特别注意，不要使用get()初始化另一个智能指针或为智能指针赋值。
    return 0;
}
```

```c++
shared_ptr<int> p(new int(42));    // reference count is 1
int *q = p.get();   // ok: but don't use q in any way that might delete its pointer
{   // new block
    // undefined: two independent shared_ptrs point to the same memory
    shared_ptr<int>(q);
} // block ends, q is destroyed, and the memory to which q points is freed
int foo = *p;   // undefined; the memory to which p points was freed
```

智能指针的`get`函数返回一个内置指针，指向智能指针管理的对象。主要用于向不能使用智能指针的代码传递内置指针。使用`get`返回指针的代码不能`delete`此指针。

不要使用`get`初始化另一个智能指针或为智能指针赋值。

【PRIMER 414】

### shared_ptr是否线程安全

![img](assets/C-plus-plus/20210719003015151.png)

指针和引用计数是线程安全的，但指针所指对象中的操作就需要自己做控制，并不是线程安全的。因为shared_ptr 有两个数据成员（指向被管理对象的指针，和指向控制块的指针），读写操作不能原子化。**使得多线程读写同一个 std::shared_ptr 对象需要加锁**。

1. 同一个shared_ptr被多个线程“读”是安全的。
2. 同一个shared_ptr被多个线程“写”是不安全的。
3. 共享引用计数的不同的shared_ptr被多个线程”写“ 是安全的。

参考：[C++11提供智能指针shared_ptr是不是线程安全的](https://blog.csdn.net/weixin_41318405/article/details/99076912)

#### **1. 引用计数更新，线程安全**

这里我们讨论对智能指针进行拷贝的情况，由于此操作读写的是引用计数，而引用计数的更新是原子操作，因此这种情况是线程安全的。下面这个例子，两个线程同时对同一个智能指针进行拷贝，引用计数的值总是20001。

```cpp
    std::shared_ptr<int> p = std::make_shared<int>(0);
    constexpr int N = 10000;
    std::vector<std::shared_ptr<int>> sp_arr1(N);
    std::vector<std::shared_ptr<int>> sp_arr2(N);

    void increment_count(std::vector<std::shared_ptr<int>>& sp_arr) {
    for (int i = 0; i < N; i++) {
        sp_arr[i] = p;
    }
    }

    std::thread t1(increment_count, std::ref(sp_arr1));
    std::thread t2(increment_count, std::ref(sp_arr2));
    t1.join();
    t2.join();
    std::cout<< p.use_count() << std::endl; // always 20001
```

#### **2. 同时修改指向的内存区域，线程不安全**

下面这个例子，两个线程同时对同一个智能指针指向内存的值进行自增操作，最终的结果不是我们期望的20000。因此同时修改智能指针指向的内存区域不是线程安全的。

```cpp
    std::shared_ptr<int> p = std::make_shared<int>(0);
    void modify_memory() {
        for (int i = 0; i < 10000; i++) {
            (*p)++;
        }
    }

    std::thread t1(modify_memory);
    std::thread t2(modify_memory);
    t1.join();
    t2.join();
    std::cout << "Final value of p: " << *p << std::endl; // possible result: 16171, not 20000
```

#### **3. 直接修改shared_ptr对象本身的指向，线程不安全。**

下面这个程序示例，两个线程同时修改同一个智能指针对象的指向，程序发生了异常终止。

```cpp
    std::shared_ptr<int> sp = std::make_shared<int>(1);
    auto modify_sp_self = [&sp]() {
        for (int i = 0; i < 1000000; ++i) {
            sp = std::make_shared<int>(i);
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(modify_sp_self);
    }
    for (auto& t : threads) {
        t.join();
    }
```

报错为：

```text
pure virtual method called
terminate called without an active exception
```

用gdb查看函数调用栈，发现是在调用`std::shared_ptr<int>::~shared_ptr()`时出错，

```shell
(gdb) bt
#0  __GI_raise (sig=sig@entry=6) at ../sysdeps/unix/sysv/linux/raise.c:50
#1  0x00007ffff7bc7859 in __GI_abort () at abort.c:79
#2  0x00007ffff7e73911 in ?? () from /lib/x86_64-linux-gnu/libstdc++.so.6
#3  0x00007ffff7e7f38c in ?? () from /lib/x86_64-linux-gnu/libstdc++.so.6
#4  0x00007ffff7e7f3f7 in std::terminate() () from /lib/x86_64-linux-gnu/libstdc++.so.6
#5  0x00007ffff7e80155 in __cxa_pure_virtual () from /lib/x86_64-linux-gnu/libstdc++.so.6
#6  0x00005555555576c2 in std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>::_M_release() ()
#7  0x00005555555572fd in std::__shared_count<(__gnu_cxx::_Lock_policy)2>::~__shared_count() ()
#8  0x0000555555557136 in std::__shared_ptr<int, (__gnu_cxx::_Lock_policy)2>::~__shared_ptr() ()
#9  0x000055555555781c in std::__shared_ptr<int, (__gnu_cxx::_Lock_policy)2>::operator=(std::__shared_ptr<int, (__gnu_cxx::_Lock_policy)2>&&) ()
#10 0x00005555555573d0 in std::shared_ptr<int>::operator=(std::shared_ptr<int>&&) ()
#11 0x000055555555639f in main::{lambda()#1}::operator()() const ()
... 
```

其原因为：在并发修改指向的情况下，可能对已析构对象再次调用析构函数，导致了此异常。

对程序加锁后，程序可正常运行:

```cpp
    std::shared_ptr<int> sp = std::make_shared<int>(1);
    std::mutex m;
    auto modify = [&sp]() {
        // make the program thread safe
        std::lock_guard<std::mutex> lock(m);
        for (int i = 0; i < 1000000; ++i) {
            sp = std::make_shared<int>(i);
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(modify);
    }
    for (auto& t : threads) {
        t.join();
    }
    std::cout << *sp << std::endl;  // running as expected, result: 999999
```

#### 4.如果多个线程同时读`shared_ptr`指向的内存对象，是线程安全的。

**总结**

- `shared_ptr`本身不是一个线程安全的STL，因此并发读写对应内存区域是不安全的。
- 由于赋值操作涉及原内存释放、修改指针指向等多个修改操作，其过程不是原子操作，因此对`shared_ptr`进行并发赋值不是线程安全的。
- 对`shared_ptr`进行并发拷贝，对数据指针和控制块指针仅进行读取并复制，然后对引用计数进行递增，而引用计数增加是原子操作。因此是线程安全的。

参考[C++ :  shared_ptr是线程安全的吗？](https://zhuanlan.zhihu.com/p/664993437)

### unique_ptr

与`shared_ptr`不同，同一时刻只能有一个`unique_ptr`指向给定的对象。当`unique_ptr`被销毁时，它指向的对象也会被销毁。

`make_unique`函数（C++14新增，定义在头文件*memory*中）在动态内存中分配一个对象并初始化它，返回指向此对象的`unique_ptr`。

```c++
unique_ptr<int> p1(new int(42));
// C++14
unique_ptr<int> p2 = make_unique<int>(42);
```

由于`unique_ptr`独占其指向的对象，因此`unique_ptr`不支持普通的拷贝或赋值操作。

`unique_ptr`操作：

![12-4](assets/C-plus-plus/12-4.png)

`release`函数返回`unique_ptr`当前保存的指针并将其置为空。

`reset`函数成员接受一个可选的指针参数，重新设置`unique_ptr`保存的指针。如果`unique_ptr`不为空，则它原来指向的对象会被释放。

```c++
// 将所有权从 p1 (which points to the string Stegosaurus) 转移给 p2
unique_ptr<string> p2(p1.release());    // release makes p1 null
unique_ptr<string> p3(new string("Trex"));
// transfers ownership from p3 to p2
p2.reset(p3.release()); // reset deletes the memory to which p2 had pointed
```

调用`release`会切断`unique_ptr`和它原来管理的对象之间的联系。`release`返回的指针通常被用来初始化另一个智能指针或给智能指针赋值。如果没有用另一个智能指针保存`release`返回的指针，程序就要负责资源的释放。

```c++
p2.release();   // WRONG: p2 won't free the memory and we've lost the pointer
auto p = p2.release();   // ok, but we must remember to delete(p)
```

不能拷贝`unique_ptr`的规则有一个例外：可以拷贝或赋值一个即将被销毁的`unique_ptr`（移动构造、移动赋值）。

```c++
unique_ptr<int> clone(int p)
{
    unique_ptr<int> ret(new int (p));
    // . . .
    return ret;
}
```

老版本的标准库包含了一个名为`auto_ptr`的类，

类似`shared_ptr`，默认情况下`unique_ptr`用`delete`释放其指向的对象。`unique_ptr`的删除器同样可以重载，但`unique_ptr`管理删除器的方式与`shared_ptr`不同。定义`unique_ptr`时必须在尖括号中提供删除器类型。创建或`reset`这种`unique_ptr`类型的对象时，必须提供一个指定类型的可调用对象（删除器）。

```c++
// p points to an object of type objT and uses an object of type delT to free that object
// it will call an object named fcn of type delT
unique_ptr<objT, delT> p (new objT, fcn);

void f(destination &d /* other needed parameters */)
{
    connection c = connect(&d);  // open the connection
    // when p is destroyed, the connection will be closed
    unique_ptr<connection, decltype(end_connection)*> p(&c, end_connection);
    // use the connection
    // when f exits, even if by an exception, the connection will be properly closed
} // 当 p 被摧毁时，自动调用 end_connection 函数
```

### weak_ptr

`weak_ptr`是一种不控制所指向对象生存期的智能指针，它指向一个由`shared_ptr`管理的对象。将`weak_ptr`绑定到`shared_ptr`不会改变`shared_ptr`的引用计数。如果`shared_ptr`被销毁，即使有`weak_ptr`指向对象，对象仍然有可能被释放。

![12-5](assets/C-plus-plus/12-5.png)

创建一个`weak_ptr`时，需要使用`shared_ptr`来初始化它。`weak_ptr`只能配合`std::shared_ptr`使用，不能单独使用。

```c++
auto p = make_shared<int>(42);
weak_ptr<int> wp(p);    // wp weakly shares with p; use count in p is unchanged
```

使用`weak_ptr`访问对象时，必须先调用`lock`函数。该函数检查`weak_ptr`指向的对象是否仍然存在。如果存在，则返回指向共享对象的`shared_ptr`，否则返回空指针。

```c++
if (shared_ptr<int> np = wp.lock())
{
    // true if np is not null
    // inside the if, np shares its object with p
}
```

#### 使用weak_ptr防止循环引用

```C++
#include <memory>
#include <iostream>

class Foo : public std::enable_shared_from_this<Foo>
{
public:
    Foo() { std::cout << __PRETTY_FUNCTION__ << std::endl; }
    ~Foo() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

    void self()
    {
        mPtr = shared_from_this();
    }

private:
    // std::shared_ptr<Foo> mPtr; // 【1】由于循环引用，不会调用析构函数，改 mPtr 为 std::weak_ptr 类型即可
    std::weak_ptr<Foo> mPtr; //【2】
};

int main()
{
    {
        std::shared_ptr<Foo> c = std::make_shared<Foo>();
        c->self();
    }
    return 0;
}
/**
注释【1】打开【2】，打印
Foo::Foo()
Foo::~Foo()
注释【2】打开【1】，打印
Foo::Foo()
由于循环引用，不会调用析构函数
*/
```

`std::enable_shared_from_this<T>::shared_from_this` 是个侵入式设计。为的解决传入`this`导致对象被析构两次的问题。    

什么情况下需要使用 `shared_from_this()`? 用于返回当前对象 `this`的`std::shared_ptr`类型指针时：

```cpp
#include <memory>
#include <iostream>

class Foo : public std::enable_shared_from_this<Foo>
{
public:
    Foo() { std::cout << "Foo()\n"; }
    ~Foo() { std::cout << "~Foo()\n"; }

    std::shared_ptr<Foo> getSelf()
    {
        return shared_from_this();
    }
};

int main()
{
    Foo *foo = new Foo;
    std::shared_ptr<Foo> sp1(foo);
    std::shared_ptr<Foo> sp2 = sp1->getSelf(); // 【1】为了对 foo对象进行共享
    //std::shared_ptr<Foo> sp2(foo); // 【2】

    // std::boolalpha 的作用是使 bool 型变量按照 false、true 的格式输出。如不使用该标识符，那么结果会按照 1、0 的格式输出
    std::cout << std::boolalpha << (sp2.get() == foo) << std::endl;
    std::cout << sp1.use_count() << "    " << sp2.use_count() << std::endl;
}
/* 打印
Foo()
true
2    2
~Foo()
*/
```

如果注释【1】打开【2】，则会析构两次，产生未定义的行为，打印如下

```shell
Foo()
true
1    1
~Foo()
~Foo()
free(): double free detected in tcache 2
已放弃 (核心已转储)
```

尽管`sp1`和`sp2`都指向了`foo`，但是却不共享计数，当析构的时候就会被析构两次，产生未定义行为。
`std::weak_ptr`可以接受`std::shared_ptr`参数来构造自己，`std::shared_ptr`也具有接受`std::weak_ptr`参数来构造自己。 

enable_shared_from_this 函数原型

```cpp
    template<typename _Tp>
    class enable_shared_from_this {
    protected:
        ...
    public:
        shared_ptr<_Tp>
        shared_from_this() { 
            return shared_ptr<_Tp>(this->_M_weak_this); 
        }

        shared_ptr<const _Tp>
        shared_from_this() const { 
            return shared_ptr<const _Tp>(this->_M_weak_this); 
        }
    private:
        ...
        mutable weak_ptr<_Tp>  _M_weak_this;
    }
```

 `enable_shared_from_this`的子类需要返回自身的`std::shared_ptr`指针，那么就需要继承这个类。 

成员变量为什么是`weak_ptr`类型  
因为如果是`std::shared_ptr`类型，那么就永远无法析构对象自身。   

  这个`_M_weak_this`不是这个类中初始化，而是在`shared_ptr`中初始化，初始化的值就是`this`。因此如果智能指针类型是`std::shared_ptr`，那么这个类对象一旦创建，引用计数就是1，那么永远也无法析构。

为什么不直接传回`this`  
`std::shared_ptr`的引用计数增加是需要用`operator=`实现的。

### 使用 std::shared_ptr管理buffer或者数组

```C++
class O
{
  public:
    O() : mValue(0){};
    ~O() { printf("call ~O(), mValue = %d\n", mValue); };

    int mValue;
};

int main()
{
    int bufferSize = 10;
    auto pData     = std::shared_ptr<uint8_t>(new uint8_t[bufferSize], [](uint8_t *ptr) {
        std::cout << "delete[] buffer pData" << std::endl;
        delete[] ptr;
    });

    auto sp = std::shared_ptr<O>(new O[5], [](O *ptr) { delete[] ptr; });
    O *p    = sp.get();
    for (int i = 0; i < 5; ++i)
    {
        (p + i)->mValue = i;
    }

}  
/*
call ~O(), mValue = 4
call ~O(), mValue = 3
call ~O(), mValue = 2
call ~O(), mValue = 1
call ~O(), mValue = 0
delete[] buffer pData
*/
```

## 基于范围的 for 循环

```C++
int main(int argc, char* argv[]) {
	int arr[10] = {1, 2, 3, 4, 5, 6};
	for (int &x : arr)		// 只有使用引用 & 才能通过 x 修改 arr 里的值
	{
		cout << (x % 2 ? "奇" : "偶") << ' ';
		x = x + 1;
	}
	cout << endl;
	for (int x : arr) cout << x << ' ';
	getchar();
}
//	奇 偶 奇 偶 奇 偶 偶 偶 偶 偶
//	2 3 4 5 6 7 1 1 1 1
```

### 处理多维数组

**使用范围`for`语句处理多维数组时，为了避免数组被自动转换成指针，语句中的外层循环控制变量必须声明成引用类型。**

```c++
for (const auto &row : ia)  // for every element in the outer array
    for (auto col : row)    // for every element in the inner array
        cout << col << endl;
```

如果*row*不是引用类型，编译器初始化*row*时会自动将数组形式的元素转换成指向该数组内首元素的指针，这样得到的*row*就是`int*`类型，而之后的内层循环则试图在一个`int*`内遍历，程序将无法通过编译。

```c++
for (auto row : ia)
    for (auto col : row)
```

使用范围`for`语句处理多维数组时，除了最内层的循环，其他所有外层循环的控制变量都应该定义成引用类型。

## lambda 表达式

`find_if`函数接受两个迭代器参数和一个谓词参数。迭代器参数用于指定序列范围，之后对序列中的每个元素调用给定谓词，并返回第一个使谓词返回非0值的元素。如果不存在，则返回尾迭代器。

对于一个对象或表达式，如果可以对其使用调用运算符`()`，则称它为可调用对象（callable object）。可以向算法传递任何类别的可调用对象。

一个`lambda`表达式表示一个可调用的代码单元，类似未命名的内联函数，但可以定义在函数内部。其形式如下：

```c++
[capture list] (parameter list) -> return type { function body }
```

其中，*capture list*（捕获列表）是一个由`lambda`所在函数定义的局部变量的列表（通常为空）。*return type*、*parameter list*和*function body*与普通函数一样，分别表示返回类型、参数列表和函数体。但与普通函数不同，`lambda`必须使用尾置返回类型，且不能有默认实参。

定义`lambda`时可以省略参数列表和返回类型，但必须包含捕获列表和函数体。省略参数列表等价于指定空参数列表。省略返回类型时，若函数体只是一个`return`语句，则返回类型由返回表达式的类型推断而来。否则返回类型为`void`。

```c++
auto f = [] { return 42; };
cout << f() << endl;    // prints 42
```

`lambda`可以使用其所在函数的局部变量，但必须先将其包含在捕获列表中。捕获列表只能用于局部非`static`变量，`lambda`可以直接使用局部`static`变量和其所在函数之外声明的名字。

```c++
// get an iterator to the first element whose size() is >= sz
auto wc = find_if(words.begin(), words.end(),
                    [sz](const string &a) { return a.size() >= sz; });
```

`for_each`函数接受一个输入序列和一个可调用对象，它对输入序列中的每个元素调用此对象。

```c++
// print words of the given size or longer, each one followed by a space
for_each(words.begin(), words.end(),
            [] (const string &s) { cout << s << " "; });
```

### lambda捕获变量和返回

**被`lambda`捕获的变量的值是在`lambda`创建时拷贝，而不是调用时拷贝。在`lambda`创建后修改局部变量不会影响`lambda`内对应的值。**

```c++
size_t v1 = 42; // local variable
// copies v1 into the callable object named f
auto f = [v1] { return v1; };
// auto f = [v1] { return ++v1; }; // error: increment of read-only variable ‘v1’，不可以修改 v1 
// auto f = [v1] () mutable { return ++v1; }; // 在参数列表后加 mutable 就可以解决问题。返回 43
v1 = 0;
auto j = f();   // j is 42; f stored a copy of v1 when we created it
```

**默认情况下，对于值方式捕获的变量，`lambda`不能修改其值。如果希望修改，就必须在参数列表后添加关键字`mutable`。**

```c++
size_t v1 = 42; // local variable
// f can change the value of the variables it captures
auto f = [v1] () mutable { return ++v1; };
v1 = 0;
auto j = f();   // j is 43
```

`lambda`可以以引用方式捕获变量，但必须保证`lambda`执行时变量存在。

```c++
size_t v1 = 42; // local variable
// the object f2 contains a reference to v1
auto f2 = [&v1] { return ++v1; };
v1 = 0;
auto j = f2();  // j is 1; f2 refers to v1; it doesn't store it
```

**可以让编译器根据`lambda`代码隐式捕获函数变量，方法是在捕获列表中写一个`&`或`=`符号。`&`为引用捕获，`=`为值捕获。**

可以混合使用显式捕获和隐式捕获。混合使用时，捕获列表中的第一个元素必须是`&`或`=`符号，用于指定默认捕获方式。显式捕获的变量必须使用与隐式捕获不同的方式。

```c++
// os implicitly captured by reference; c explicitly captured by value
for_each(words.begin(), words.end(),
            [&, c] (const string &s) { os << s << c; });
// os explicitly captured by reference; c implicitly captured by value
for_each(words.begin(), words.end(),
            [=, &os] (const string &s) { os << s << c; });
```

`lambda`捕获列表形式：

![10-2](assets/C-plus-plus/10-2.png)

本小节在【PRIMER 350~354】

### 参数绑定

`std::bind`可以绑定普通函数，但不能区分重载，也可以绑定类内成员函数。也可以通过占位符方便更换形参。

`std::bind`在默认情况下，是依靠值传递，使用了`std::ref`来包裹传入参数才是使用引用传递。

```C++
#include <functional>
#include <iostream>

class Foo
{
public:
    Foo() = default;

    void add(const int &lhs, const int &rhs)
    {
        std::cout << __PRETTY_FUNCTION__ << " sum = " << (lhs + rhs) << std::endl;
    }
};

void f(int n) { std::cout << "void f(int n)" << std::endl; }
void f(double n) { std::cout << "void f(double n)" << std::endl; }

int main()
{
    auto g1 = [] { f(1); };    // OK
    auto g11 = [] { f(1.0); }; // OK
    //auto g2 = std::bind(f, 2); // 错误，因为无法确定要绑定哪个重载的 f()
    auto g3 = std::bind(static_cast<void (*)(int)>(f), 3.0); // OK，强行转换为 void f(int n)，即使传的形参是 double

    g1();
    g11();
    g3();

    Foo foo;
    auto g4 = std::bind(&Foo::add, &foo, 1, 2); // std::_Bind<void (Foo::*(Foo *, int, int)> g4
    auto g5 = std::bind(&Foo::add, &foo, std::placeholders::_1, std::placeholders::_2);
    auto g6 = std::bind(&Foo::add, &foo, 1, std::placeholders::_2);

    g4();         // 1 + 2 = 3
    g4(100);      // 1 + 2 = 3
    g4(100, 200); // 1 + 2 = 3
    g5(3, 4);     // 3 + 4 = 7
    g6(3, 4);     // 1 + 4 = 5
    // g6(3);        // error

    return 0;
}
/*
void f(int n)
void f(double n)
void f(int n)
void Foo::add(const int&, const int&) sum = 3
void Foo::add(const int&, const int&) sum = 3
void Foo::add(const int&, const int&) sum = 3
void Foo::add(const int&, const int&) sum = 7
void Foo::add(const int&, const int&) sum = 5
*/
```

`bind`函数定义在头文件*functional*中，相当于一个函数适配器，它接受一个可调用对象，生成一个新的可调用对象来适配原对象的参数列表。一般形式如下：

```c++
auto newCallable = bind(callable, arg_list);
```

其中，*newCallable*本身是一个可调用对象，*arg_list*是一个以逗号分隔的参数列表，对应给定的*callable*的参数。之后调用*newCallable*时，*newCallable*会再调用*callable*，并传递给它*arg_list*中的参数。*arg_list*中可能包含形如`_n`的名字，其中*n*是一个整数。这些参数是占位符，表示*newCallable*的参数，它们占据了传递给*newCallable*的参数的位置。数值*n*表示生成的可调用对象中参数的位置：`_1`为*newCallable*的第一个参数，`_2`为*newCallable*的第二个参数，依次类推。这些名字都定义在命名空间*placeholders*中，它又定义在命名空间*std*中，因此使用时应该进行双重限定。

```c++
using std::placeholders::_1;
using namespace std::placeholders;
bool check_size(const string &s, string::size_type sz);

// check6 is a callable object that takes one argument of type string
// and calls check_size on its given string and the value 6
auto check6 = bind(check_size, _1, 6);
string s = "hello";
bool b1 = check6(s);    // check6(s) calls check_size(s, 6)
```

`bind`函数可以调整给定可调用对象中的参数顺序。

```c++
// sort on word length, shortest to longest
sort(words.begin(), words.end(), isShorter);
// sort on word length, longest to shortest
sort(words.begin(), words.end(), bind(isShorter, _2, _1));
```

默认情况下，`bind`函数的非占位符参数被拷贝到`bind`返回的可调用对象中。但有些类型不支持拷贝操作。

如果希望传递给`bind`一个对象而又不拷贝它，则必须使用标准库的`ref`函数。`ref`函数返回一个对象，包含给定的引用，此对象是可以拷贝的。`cref`函数生成保存`const`引用的类。

```c++
ostream &print(ostream &os, const string &s, char c);
for_each(words.begin(), words.end(), bind(print, ref(os), _1, ' '));
```

【PRIMER 354~356】

## 函数调用运算符

### 重载operator()运算符

函数调用运算符必须定义为成员函数。一个类可以定义多个不同版本的调用运算符，相互之间必须在参数数量或类型上有所区别。

该类也可以称为可调用对象，或函数对象。

```c++
class PrintString
{
public:
    PrintString(ostream &o = cout, char c = ' '):
        os(o), sep(c) { }
    void operator()(const string &s) const
    {
        os << s << sep;
    }

private:
    ostream &os;   // 用于写入的目的流
    char sep;      // 用于将不同输出隔开的字符
};

PrintString printer;  // uses the defaults; prints to cout
printer(s);     // prints s followed by a space on cout
```

如果类定义了调用运算符，则该类的对象被称作函数对象（function object），函数对象常常作为泛型算法的实参。

```c++
for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));
```

### lambda是函数对象

编写一个`lambda`后，编译器会将该表达式转换成一个未命名类的未命名对象，类中含有一个重载的函数调用运算符。

```c++
// sort words by size, but maintain alphabetical order for words of the same size
stable_sort(words.begin(), words.end(),
    [](const string &a, const string &b) { return a.size() < b.size(); });

// acts like an unnamed object of a class that would look something like
class ShorterString
{
public:
    bool operator()(const string &s1, const string &s2) const
    {
        return s1.size() < s2.size();
    }
};
```

`lambda`默认不能改变它捕获的变量。因此在默认情况下，由`lambda`产生的类中的函数调用运算符是一个`const`成员函数。如果`lambda`被声明为可变的，则调用运算符就不再是`const`函数了。

`lambda`通过引用捕获变量时，由程序负责确保`lambda`执行时该引用所绑定的对象确实存在。因此编译器可以直接使用该引用而无须在`lambda`产生的类中将其存储为数据成员。相反，通过值捕获的变量被拷贝到`lambda`中，此时`lambda`产生的类必须为每个值捕获的变量建立对应的数据成员，并创建构造函数，用捕获变量的值来初始化数据成员。

```c++
// get an iterator to the first element whose size() is >= sz
auto wc = find_if(words.begin(), words.end(),
            [sz](const string &a) { return a.size() >= sz; });

// would generate a class that looks something like
class SizeComp
{
public:
    SizeComp(size_t n): sz(n) { }   // parameter for each captured variable
    // call operator with the same return type, parameters, and body as the lambda
    bool operator()(const string &s) const
    {
        return s.size() >= sz;
    }

private:
    size_t sz;   // a data member for each variable captured by value
};
```

`lambda`产生的类不包含默认构造函数、赋值运算符和默认析构函数，它是否包含默认拷贝/移动构造函数则通常要视捕获的变量类型而定。

**标准库定义的函数对象**

标准库在头文件*functional*中定义了一组表示算术运算符、关系运算符和逻辑运算符的类，每个类分别定义了一个执行命名操作的调用运算符。这些类都被定义为模板的形式，可以为其指定具体的应用类型（即调用运算符的形参类型）。

![14-2](assets/C-plus-plus/14-2.png)

关系运算符的函数对象类通常被用来替换算法中的默认运算符，这些类对于指针同样适用。

```c++
vector<string *> nameTable;    // vector of pointers
// error: the pointers in nameTable are unrelated, so < is undefined
sort(nameTable.begin(), nameTable.end(),
        [](string *a, string *b) { return a < b; });
// ok: library guarantees that less on pointer types is well defined
sort(nameTable.begin(), nameTable.end(), less<string*>());
```

### 可调用对象与function

调用形式指明了调用返回的类型以及传递给调用的实参类型。不同的可调用对象可能具有相同的调用形式。

标准库`function`类型是一个模板，定义在头文件*functional*中，用来表示对象的调用形式。

![14-3](assets/C-plus-plus/14-3.png)

创建一个具体的`function`类型时必须提供其所表示的对象的调用形式。

```c++
// ordinary function
int add(int i, int j) { return i + j; }
// function-object class
struct div
{
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

function<int(int, int)> f1 = add;      // function pointer
function<int(int, int)> f2 = div();    // object of a function-object class
function<int(int, int)> f3 = [](int i, int j) { return i * j; };  // lambda
                                   
cout << f1(4,2) << endl;   // prints 6
cout << f2(4,2) << endl;   // prints 2
cout << f3(4,2) << endl;   // prints 8
```

不能直接将重载函数的名字存入`function`类型的对象中，这样做会产生二义性错误。消除二义性的方法是使用`lambda`或者存储函数指针而非函数名字。

C++11新标准库中的`function`类与旧版本中的`unary_function`和`binary_function`没有关系，后两个类已经被`bind`函数代替。

## 尾置返回类型

用于函数返回类型的自动推导，一般用于**返回类型比较复杂**，或者需要**通过模板参数（亦或其它表达式）来推导返回类型**的情况，通常会结合 **decltype** 一起使用，本质上算是一种语法糖，在函数定义的**参数列表右侧添加 ->ReturnType** 来**代表函数返回类型**，将**通常放置函数返回类型的地方使用 auto 代替**。

语法格式：

```cpp
auto FuncName(ArgsList) -> ReturnType { }
```

使用示例：

```cpp
// 结合decltype，依据模板参数推导返回类型 
template<typename ArgType1, typename ArgType2>
auto Func1(ArgType1& a, ArgType2& b) -> decltype(a + b) 
{ 
    return (a + b);
}

// 在C++14中可省略箭头返回值部分，直接将函数返回类型设置为auto 
template<typename ArgType1, typename ArgType2>
auto Func2(ArgType1& a, ArgType2& b)
{ 
    return (a + b);
}

// 也可以直接将返回类型定义为 decltype(auto) 
template<typename ArgType1, typename ArgType2>
decltype(auto) Func3(ArgType1& a, ArgType2& b)
{
    return (a + b);
}
```

**特别注意：**对于 Func1、Func2 和 Func3 的**函数定义是等价的**，当它们都是相同函数名时相当于定义了多个相同的重载函数，但是这种等价的定义在**不使用时不会导致编译报错**，而在实际**调用**中，会因为对**重载函数的不明确调用**而导致编译报错。

**补充：**将尾置返回类型放在参数列表后面，是因为C++函数的**返回类型是前置定义**，在前置定义中，此时还未定义参数列表，所以如果要通过参数来推导返回类型就必须将推导的表达式放在参数列表后面，C++14虽然可以省略类型推导表达式，但仍然不能在前置定义的返回类型中依据参数推导返回类型：

```cpp
// 编译报错，找不到 a 和 b 的定义 
template<typename ArgType1, typename ArgType2>
decltype(a + b) Func4(ArgType1& a, ArgType2& b)
{
    return (a + b);
}

// 需要注意的是上述代码不代表 decltype 不能用于函数前置声明，如：
vector<int> VEC;
template<typename ArgType1, typename ArgType2>
decltype(VEC) Func5(ArgType1 a, ArgType2 b)
{
    vector<int> arr{a, b};
    return arr;
}
```

# C++14 新特性

## 函数返回值可以使用`auto`推导

```c++
#include <iostream>

using namespace std;

auto func(int i) {
    return i;
}

int main() {
    cout << func(4) << endl;
    return 0;
}
```

【注】

- 函数内如果有多个return语句，它们必须返回相同的类型，否则编译失败。
- 如果return语句返回初始化列表，返回值类型推导也会失败
- 如果函数是虚函数，不能使用返回值类型推导

## std::make_unique

C++11中有std::make_shared，却没有std::make_unique，在C++14已经改善

```C++
struct A {};
std::unique_ptr<A> ptr = std::make_unique<A>();
```

## std::shared_timed_mutex与std::shared_lock

C++14 通过`std::shared_timed_mutex`和`std::shared_lock`来实现读写锁，保证多个线程可以同时读，但是写线程必须独立运行，写操作不可以同时和读操作一起进行。

例子如下：

```c
struct ThreadSafe {
    mutable std::shared_timed_mutex mutex_;
    int value_;

    ThreadSafe() {
        value_ = 0;
    }

    int get() const {
        std::shared_lock<std::shared_timed_mutex> lock(mutex_);
        return value_;
    }

    void increase() {
        std::unique_lock<std::shared_timed_mutex> lock(mutex_);
        value_ += 1;
    }
};
```

## deprecated

用来表示一个名字或者实体不再推荐使用或者已经弃用，通常已经有了更好的方法来代替这个名字或者实体，只不过为了兼容之前的老代码可能还要保留原来这个名字或者实体。

在C++中deprecated有两种语法格式，一种不需要加字符字面值，一种需要加字符字面值，形式如下：
```shell
 [[deprecated]]
 [[deprecated(字符字面值)]]
```

指示允许使用声明有此属性的名称或实体，但因故不鼓励使用。编译器通常会对其使用情况发出警告。若指定了 字符字面量，则它通常被包含于警告中。

下列名字或实体的声明中允许使用这个属性：

- [class/struct/union](https://www.apiref.com/cpp-zh/cpp/language/classes.html)：struct [[deprecated]] S;，
- [typedef 名](https://www.apiref.com/cpp-zh/cpp/language/typedef.html)，也包括[别名声明](https://www.apiref.com/cpp-zh/cpp/language/type_alias.html)：[[deprecated]] typedef S* PS;、using PS [[deprecated]] = S*;，
- 变量，包括[静态数据成员](https://www.apiref.com/cpp-zh/cpp/language/static.html)：[[deprecated]] int x;，
- [非静态数据成员](https://www.apiref.com/cpp-zh/cpp/language/data_members.html)：union U { [[deprecated]] int n; };，
- [函数](https://www.apiref.com/cpp-zh/cpp/language/function.html)：[[deprecated]] void f();，
- [命名空间](https://www.apiref.com/cpp-zh/cpp/language/namespace.html)：namespace [[deprecated]] NS { int x; }，
- [枚举](https://www.apiref.com/cpp-zh/cpp/language/enum.html)：enum [[deprecated]] E {};，
- 枚举项：enum { A [[deprecated]], B [[deprecated]] = 42 };，
- [模板特化](https://www.apiref.com/cpp-zh/cpp/language/template_specialization.html)：template<> struct [[deprecated]] X<int> {};。

声明时未弃用的名字可被重声明为 `deprecated`。声明为 `deprecated` 的名字不能通过重声明它而不带此属性变为未弃用。

以修饰函数为例，代码如下：

```C++
[[deprecated("Use fun() instead.")]] void fun1()
{
    std::clog << "call fun2()\n";
}

[[deprecated]] void fun2()
{
    std::clog << "call fun1()\n";
}

void fun()
{
    std::clog << "call fun()\n";
}

int main()
{
    fun1();
    fun2();
    fun();

    return 0;
}
```

编译和输出：

```shell
$ g++ t.cpp 
t.cpp: In function ‘int main()’:
t.cpp:65:10: warning: ‘void fun1()’ is deprecated: Use fun() instead. [-Wdeprecated-declarations]
   65 |     fun1();
      |          ^
t.cpp:48:43: note: declared here
   48 | [[deprecated("Use fun() instead.")]] void fun1()
      |                                           ^~~~
t.cpp:65:10: warning: ‘void fun1()’ is deprecated: Use fun() instead. [-Wdeprecated-declarations]
   65 |     fun1();
      |          ^
t.cpp:48:43: note: declared here
   48 | [[deprecated("Use fun() instead.")]] void fun1()
      |                                           ^~~~
t.cpp:66:10: warning: ‘void fun2()’ is deprecated [-Wdeprecated-declarations]
   66 |     fun2();
      |          ^
t.cpp:53:21: note: declared here
   53 | [[deprecated]] void fun2()
      |                     ^~~~
t.cpp:66:10: warning: ‘void fun2()’ is deprecated [-Wdeprecated-declarations]
   66 |     fun2();
      |          ^
t.cpp:53:21: note: declared here
   53 | [[deprecated]] void fun2()
      |                     ^~~~
$ ./a.out 
call fun2()
call fun1()
call fun()
```

# 杂项

## std::this_thread::sleep_for和直接使用sleep有什么区别

C函数sleep(),usleep()和Sleep()是平台特定的而不是C++标准库的一部分。

而this_thread::sleep_for是平台无关的，在windows和linux上都可以这么写，具体链接的函数交给STL负责就是。

## [likely和unlikely](https://zhuanlan.zhihu.com/p/357434227)

在一些明确的场景下，我们应该比CPU和编译器更了解哪个分支条件更有可能被满足。使用`likely`和`unlikely`，可以将这一先验知识告知编译器和CPU, 提高分支预测的准确率，从而减少CPU流水线分支预测错误带来的性能损失。

在Linux内核代码中，这两个宏的应用比比皆是。定义：

```C++
#define likely(x) __builtin_expect(!!(x), 1) 
#define unlikely(x) __builtin_expect(!!(x), 0)
```

`likely`，用于修饰`if/else if`分支，表示该分支的条件更有可能被满足。而`unlikely`与之相反。以下为示例。`unlikely`修饰`nullptr == buf`分支，表示该分支不太可能被满足。

```C++
#include <cstdio>

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)

int process(char *buf, size_t size)
{
    if (unlikely(nullptr == buf)) { // buf 为空指针的分支不太可能被满足
        error_process();
        return -1;
    } else
    {
        do_process();
    }
    return 0;
}
```

**likely/unlikely的适用条件**

CPU有自带的分支预测器，在大多数场景下效果不错。因此在分支发生概率严重倾斜、追求极致性能的场景下，使用`likely/unlikely`才具有较大意义。

## \__attribute__

更多可以参考[\__attribute__ 机制详解](https://blog.csdn.net/weaiken/article/details/88085360)，下面列举一些遇到的

### \__attribute__((unused))

```C
// 如果定义了一个静态函数，而没有去使用，则会有警告，而使用attribute((unused))可以告诉编译器忽略此告警：
__attribute__((unused)) static void f(void)
{
    printf("call f()\n");
}

// 同样的也可以用于修饰变量，下面的两个语句是同样的意思，告诉编译器，变量iter可能不被使用，忽略此告警。
int __attribute__((unused)) iter = 0;
__attribute__((unused)) int iter = 0;
```

### \__attribute__ ((__packed__))

不想要字节对齐的时候，可以在结构体声明当中，加上\__attribute__ ((__packed__))关键字，让结构体按照紧凑排列的方式，占用内存。

```C++
#include <stdio.h>
#include <iostream>
 
using namespace std;
 
struct test1 {
    char c;
    int i;
};
 
struct __attribute__ ((__packed__)) test2 {
    char c;
    int i;
};
 
int main()
{
    cout << "size of test1:" << sizeof(struct test1) << endl;
    cout << "size of test2:" << sizeof(struct test2) << endl;
}
/*
运行结果：
size of test1:8
size of test2:5
*/
```

显而易见，test1结构体里面没有加关键字，它采用了4字节对齐的方式，即使是一个char变量，也占用了4字节内存，int占用4字节，共占用了8字节内存，这在64位机器当中将会更大。
而test2结构体，在加上关键字之后，结构体内的变量采用内存紧凑的方式排列，char类型占用1字节，int占用4字节，总共占用了5个字节的内存。

### [\__**attribute**__((aligned(n)))](https://www.cnblogs.com/kendoziyu/p/16551501.html)

`n`的有效参数为**2的幂值**，32位最大为232,64位为 264，这个时候编译器会将让`n`与默认的对齐字节数进行比较，取较大值为对齐字节数，与`#pragma pack(n)`恰好相反。

它的作用是让整个结构体变量整体进行n字节对齐（注意是结构体变量**整体**n字节对齐，而不是结构体内各数据成员也要n字节对齐。

### \_\_attribute\_\_((constructor))

`__attribute__((constructor))` 是GCC和Clang编译器提供的一个函数属性（function attribute）。它用于将一个函数标记为在程序启动时自动执行的构造函数（constructor）。

当使用 `__attribute__((constructor))` 标记一个函数时，该函数会在程序运行之前的初始化阶段自动执行。这意味着该函数会在 `main()` 函数之前被调用，而且只会被调用一次。

理解 `__attribute__((constructor))` 可以从以下几个方面来思考：

1. 构造函数的执行时机：通过将函数标记为构造函数，可以确保其在程序启动时自动执行。这对于需要在程序开始之前进行某些初始化操作的场景非常有用。

2. 自动执行特性：使用 `__attribute__((constructor))` 标记函数后，不需要显式地在代码中调用该函数。编译器会负责在合适的时机自动调用它，无需手动干预。

3. 特定编译器的支持：`__attribute__((constructor))` 是GCC和Clang编译器提供的扩展，因此这个特性在使用其他编译器时可能不可用或具有不同的语法。

4. 单例构造函数：可以使用 `__attribute__((constructor))` 来实现单例模式中的构造函数，确保只有一个实例被创建并在程序启动时自动初始化。

综上所述，`__attribute__((constructor))` 是一个编译器提供的函数属性，用于将函数标记为在程序启动时自动执行的构造函数。它可以帮助我们在程序开始之前进行一些必要的初始化操作，并减少手动调用的复杂性。

下面是一个简单的示例，演示了如何使用 `__attribute__((constructor))` 来创建一个在程序启动时自动执行的构造函数：

```c
#include <stdio.h>

void my_constructor() __attribute__((constructor));

void my_constructor()
{
    printf("Constructor called\n");
}

int main()
{
    printf("Main function\n");
    return 0;
}
```

在上述示例中，我们定义了一个名为 `my_constructor` 的函数，并使用 `__attribute__((constructor))` 将其标记为构造函数。当程序启动时，这个构造函数会自动执行。

在 `my_constructor` 函数中，我们简单地输出一条信息 "Constructor called"。然后，在 `main` 函数中，我们再次输出一条信息 "Main function"。

编译并运行上述代码，你将看到以下输出：

```
Constructor called
Main function
```

可以观察到，在 `main` 函数之前，构造函数 `my_constructor` 被自动调用，输出了 "Constructor called"。这证明了 `my_constructor` 是在程序启动时被自动执行的。

请注意，每个带有 `__attribute__((constructor))` 标记的构造函数只会被调用一次，且按照它们在源文件中的定义顺序进行调用。在示例中，只有一个构造函数 `my_constructor`，因此它仅被调用一次。

## \#\#\_\_VA\_ARGS\_\_

```C++
// __VA_ARGS__
// C 语言中 VA_ARGS 是一个可变参数的宏，是新的 C99 规范中新增的，需要配合 define 使用，总体来说就是将左边宏中 … 的内容原样抄写在右边 VA_ARGS 所在的位置
#define myprintf(...) printf( __VA_ARGS__)
int main()
{
    myprintf("123123456\n"); // 打印 123123456
    return 0;
}

// __VA_ARGS__宏输出可变参数
#define myprintf(fm, ...) printf(fm,__VA_ARGS__) 
int main()
{
    //输出可变参数
    myprintf("0123456789, %d%s\r\n", 1, "sd");  // OK，打印 0123456789,1sd
    //myprintf("987654321");    // 输出字符串常量报错，从这里可以看到这种写法只支持可变参数，不支持字符串常量
    return 0;
}

// ##VA_ARGS
// 如果可变参数被忽略或为空，## 操作将使预处理器（preprocessor）去除掉它前面的那个逗号.
// 如果你在宏调用时，确实提供了一些可变参数，GNU CPP 也会工作正常，它会把这些可变参数放到逗号的后面。
#define myprintf(fm, ...) printf(fm,##__VA_ARGS__) 
int main()
{
    // 输出可变参数，可以看出，使用 ##VA_ARGS 完美兼容可变参数和字符串常量输出
    myprintf("0123456789,%d%s\r\n",1,"sd"); // OK，打印 0123456789,1sd
    myprintf("987654321\r\n");    // 输出字符串常量正常，打印 987654321
    return 0;
}
```

## \#error

`#error` 是一种预编译器指示字，用于生成一个编译错误消息 。

用法：`#error [message]`，message为用户自定义的错误提示信息，可缺省。

`#error` 编译指示字用于自定义程序员特有的编译错误消息。类似的，`#warning` 用于生成编译警告消息。`#error` 可用于提示编译条件是否满足。编译过程中的任何错误意味着无法生成最终的可执行程序。

```C++
// t.c 注意是以.c作为后缀而不是cpp，不然使用gcc与g++编译都是一个效果。
// gcc和g++有点区别，后缀名为.c和.cpp的文件，g++都会当成C++，而gcc会把.c的当成c源程序，把.cpp当做cpp源程序

#define SIZE 103
#if SIZE < 0 || SIZE > 100
#warning SIZE should be between 1 and 100.
#endif

#ifndef __cplusplus
#error Not compiled with g++!
#endif

int main()
{
    return 0;
}

/*
$ gcc t.c
t.c:82:2: warning: #warning SIZE should be between 1 and 100. [-Wcpp]
   82 | #warning SIZE should be between 1 and 100.
      |  ^~~~~~~
t.c:86:2: error: #error Not compiled with g++!
   86 | #error Not compiled with g++!
      |  ^~~~~


    $ g++ t.c
t.c:82:2: warning: #warning SIZE should be between 1 and 100. [-Wcpp]
   82 | #warning SIZE should be between 1 and 100.
   */
```

## C/C++ 内置宏

参考[C/C++ 宏定义 __FILE__、__LINE__、__func__、__TIME__ 等](C/C++ 宏定义 __FILE__、__LINE__、__func__、__TIME__ 等)

