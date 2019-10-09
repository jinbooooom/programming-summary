# C-plus-plus
阅读完 C++ primer plus + Essential C++，整理的一些知识点。

[CPP 78] 指 C++ primer plus 中文版第 78 页

[ESC 15] 指 Essential C++ 中文版第 15 页

## 详细目录

### [C++编程基础](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#c%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80)

- [Hello, world!](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#hello-world)

  - [main 函数前面的数据类型 int 与 void](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#main-%E5%87%BD%E6%95%B0%E5%89%8D%E9%9D%A2%E7%9A%84%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B-int-%E4%B8%8E-void)
  
  - ["\n" 与 endl 的区别](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#n-%E4%B8%8E-endl-%E7%9A%84%E5%8C%BA%E5%88%AB)
  
  - [头文件里的 " " 与 < >]()
  - [命名空间 std](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E5%91%BD%E5%90%8D%E7%A9%BA%E9%97%B4-std)
  - [system("pause")](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#systempause)
  - [cout 与 printf()](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#cout-%E4%B8%8E-printf)
  - [main函数与命令行参数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#main%E5%87%BD%E6%95%B0%E4%B8%8E%E5%91%BD%E4%BB%A4%E8%A1%8C%E5%8F%82%E6%95%B0)
  - [编译](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E7%BC%96%E8%AF%91)
- [iostream cin cout cerr clog](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#-iostream)
- [初始化](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E5%88%9D%E5%A7%8B%E5%8C%96)
- [逗号表达式](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E9%80%97%E5%8F%B7%E8%A1%A8%E8%BE%BE%E5%BC%8F)
- [指针](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E6%8C%87%E9%92%88)
  - [数组指针与指针数组](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E6%95%B0%E7%BB%84%E6%8C%87%E9%92%88%E4%B8%8E%E6%8C%87%E9%92%88%E6%95%B0%E7%BB%84)
  - [指针函数与函数指针](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E6%8C%87%E9%92%88%E5%87%BD%E6%95%B0)
  - [函数指针数组](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E5%87%BD%E6%95%B0%E6%8C%87%E9%92%88%E6%95%B0%E7%BB%84)
  - [指针与数组的区别](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E6%8C%87%E9%92%88%E4%B8%8E%E6%95%B0%E7%BB%84%E7%9A%84%E5%8C%BA%E5%88%AB)
  - [指针与引用的区别](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E6%8C%87%E9%92%88%E4%B8%8E%E5%BC%95%E7%94%A8%E7%9A%84%E5%8C%BA%E5%88%AB)
  - [指针的一些细节](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#%E6%8C%87%E9%92%88%E7%9A%84%E4%B8%80%E4%BA%9B%E7%BB%86%E8%8A%82)
    - [\*&p和&\*p](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#p%E5%92%8Cp)
    - [p+(或-)n](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#p%E6%88%96-n)
    - [\*p++， (\*p)++，++\*p，\*++p](https://github.com/jinbooooom/C-plus-plus/blob/master/ch1-Basic%20C%2B%2B%20Programming.md#p-ppp)

### [面向过程编程](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E9%9D%A2%E5%90%91%E8%BF%87%E7%A8%8B%E7%9A%84%E7%BC%96%E7%A8%8B%E9%A3%8E%E6%A0%BC)

- [指针(pointer)与引用(reference)](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E6%8C%87%E9%92%88pointer%E4%B8%8E%E5%BC%95%E7%94%A8reference)
  - [引用作为函数参数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E5%BC%95%E7%94%A8%E4%BD%9C%E4%B8%BA%E5%87%BD%E6%95%B0%E5%8F%82%E6%95%B0)
  - [常引用作为函数参数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E5%B8%B8%E5%BC%95%E7%94%A8%E4%BD%9C%E4%B8%BA%E5%87%BD%E6%95%B0%E5%8F%82%E6%95%B0)
  - [函数返回引用与返回值](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E5%87%BD%E6%95%B0%E8%BF%94%E5%9B%9E%E5%BC%95%E7%94%A8%E4%B8%8E%E8%BF%94%E5%9B%9E%E5%80%BC)

- [作用域与生存周期](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E4%BD%9C%E7%94%A8%E5%9F%9F%E4%B8%8E%E7%94%9F%E5%AD%98%E5%91%A8%E6%9C%9F)
  - [内存分配](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E5%86%85%E5%AD%98%E5%88%86%E9%85%8D)
  - [局部变量和全局变量](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E5%B1%80%E9%83%A8%E5%8F%98%E9%87%8F%E5%92%8C%E5%85%A8%E5%B1%80%E5%8F%98%E9%87%8F)
  - [静态存储与动态存储](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E9%9D%99%E6%80%81%E5%AD%98%E5%82%A8%E4%B8%8E%E5%8A%A8%E6%80%81%E5%AD%98%E5%82%A8)
  - [C++变量保存在堆还是栈？](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#c%E5%8F%98%E9%87%8F%E4%BF%9D%E5%AD%98%E5%9C%A8%E5%A0%86%E8%BF%98%E6%98%AF%E6%A0%88)

- [new 与 delete](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#new-%E4%B8%8E-delete)
  - [new/delete 与 malloc/free 关系](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#newdelete-%E4%B8%8E-mallocfree-%E5%85%B3%E7%B3%BB)

- [头文件](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E5%A4%B4%E6%96%87%E4%BB%B6)
  - [#ifndef/#define/#endif作用](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#ifndefdefineendif%E4%BD%9C%E7%94%A8)

- [typedef 声明](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#typedef-%E5%A3%B0%E6%98%8E)
- [枚举类型](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E6%9E%9A%E4%B8%BE%E7%B1%BB%E5%9E%8B)

- [C结构体、C++结构体、C++类的区别](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#c%E7%BB%93%E6%9E%84%E4%BD%93c%E7%BB%93%E6%9E%84%E4%BD%93c%E7%B1%BB%E7%9A%84%E5%8C%BA%E5%88%AB)
- [结构体与联合体（共用体）的区别](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E7%BB%93%E6%9E%84%E4%BD%93%E4%B8%8E%E8%81%94%E5%90%88%E4%BD%93%E5%85%B1%E7%94%A8%E4%BD%93%E7%9A%84%E5%8C%BA%E5%88%AB)

### [面向对象编程](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E7%BB%93%E6%9E%84%E4%BD%93%E4%B8%8E%E8%81%94%E5%90%88%E4%BD%93%E5%85%B1%E7%94%A8%E4%BD%93%E7%9A%84%E5%8C%BA%E5%88%AB)

- [类访问修饰](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E7%B1%BB%E8%AE%BF%E9%97%AE%E4%BF%AE%E9%A5%B0%E7%AC%A6)
- [封装](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E5%B0%81%E8%A3%85)
- [继承](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E7%BB%A7%E6%89%BF)
- [多态](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E5%A4%9A%E6%80%81)
  - [重载与重写](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E9%87%8D%E8%BD%BD%E4%B8%8E%E9%87%8D%E5%86%99)

- [构造函数与析构函数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E6%9E%84%E9%80%A0%E5%87%BD%E6%95%B0%E4%B8%8E%E6%9E%90%E6%9E%84%E5%87%BD%E6%95%B0)
- [拷贝（复制）构造函数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E6%8B%B7%E8%B4%9D%E5%A4%8D%E5%88%B6%E6%9E%84%E9%80%A0%E5%87%BD%E6%95%B0)
  - [必须定义拷贝构造函数的情况](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E5%BF%85%E9%A1%BB%E5%AE%9A%E4%B9%89%E6%8B%B7%E8%B4%9D%E6%9E%84%E9%80%A0%E5%87%BD%E6%95%B0%E7%9A%84%E6%83%85%E5%86%B5)
  - [什么情况使用拷贝构造函数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E4%BB%80%E4%B9%88%E6%83%85%E5%86%B5%E4%BD%BF%E7%94%A8%E6%8B%B7%E8%B4%9D%E6%9E%84%E9%80%A0%E5%87%BD%E6%95%B0)

- [初始化列表](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8)
  - [使用初始化列表的原因](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E4%BD%BF%E7%94%A8%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8%E7%9A%84%E5%8E%9F%E5%9B%A0)
  - [必须使用初始化列表的情况](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E5%BF%85%E9%A1%BB%E4%BD%BF%E7%94%A8%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8%E7%9A%84%E6%83%85%E5%86%B5)
  - [初始化顺序](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E5%88%9D%E5%A7%8B%E5%8C%96%E9%A1%BA%E5%BA%8F)

- [友元函数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E5%8F%8B%E5%85%83%E5%87%BD%E6%95%B0)

- [内联函数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E5%86%85%E8%81%94%E5%87%BD%E6%95%B0)

- [const](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#const)
  - [函数返回引用](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E5%87%BD%E6%95%B0%E8%BF%94%E5%9B%9E%E5%BC%95%E7%94%A8)
  - [const总结](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#const%E6%80%BB%E7%BB%93)
  - [const与指针](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#const%E4%B8%8E%E6%8C%87%E9%92%88)
  - [const 与 #define](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#const-%E4%B8%8E-define)

- [存储类](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E5%AD%98%E5%82%A8%E7%B1%BB)
  - [auto](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#auto)
  - [static](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#static)
  - [extern](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#extern)

- [this指针](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#this%E6%8C%87%E9%92%88)

- [虚函数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E8%99%9A%E5%87%BD%E6%95%B0)

  - [虚函数是否可以内联](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E8%99%9A%E5%87%BD%E6%95%B0%E6%98%AF%E5%90%A6%E5%8F%AF%E4%BB%A5%E5%86%85%E8%81%94)

- [虚析构函数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E8%99%9A%E6%9E%90%E6%9E%84%E5%87%BD%E6%95%B0)
- [静态联编和动态联编](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E9%9D%99%E6%80%81%E8%81%94%E7%BC%96%E5%92%8C%E5%8A%A8%E6%80%81%E8%81%94%E7%BC%96)
- [有关虚函数的注意事项](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E6%9C%89%E5%85%B3%E8%99%9A%E5%87%BD%E6%95%B0%E7%9A%84%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9)
- [纯虚函数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E7%BA%AF%E8%99%9A%E5%87%BD%E6%95%B0)
- [虚函数、纯虚函数](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E8%99%9A%E5%87%BD%E6%95%B0%E7%BA%AF%E8%99%9A%E5%87%BD%E6%95%B0)
- [类型安全](https://github.com/jinbooooom/C-plus-plus/blob/master/ch3-Object-Oriented%20Programming.md#%E7%B1%BB%E5%9E%8B%E5%AE%89%E5%85%A8)

### [泛型编程](https://github.com/jinbooooom/C-plus-plus/blob/master/ch4-Generic%20Programming.md#%E6%B3%9B%E5%9E%8B%E7%BC%96%E7%A8%8B%E9%A3%8E%E6%A0%BC)

- [用实例理解泛型编程](https://github.com/jinbooooom/C-plus-plus/blob/master/ch4-Generic%20Programming.md#%E7%94%A8%E5%AE%9E%E4%BE%8B%E7%90%86%E8%A7%A3%E6%B3%9B%E5%9E%8B%E7%BC%96%E7%A8%8B)

### [STL](https://github.com/jinbooooom/C-plus-plus/blob/master/ch5-STL.md#stl)

- [所有容器的共同操作(包括string 类)](https://github.com/jinbooooom/C-plus-plus/blob/master/ch5-STL.md#%E6%89%80%E6%9C%89%E5%AE%B9%E5%99%A8%E7%9A%84%E5%85%B1%E5%90%8C%E6%93%8D%E4%BD%9C%E5%8C%85%E6%8B%ACstring-%E7%B1%BB)
- [使用顺序性容器](https://github.com/jinbooooom/C-plus-plus/blob/master/ch5-STL.md#%E4%BD%BF%E7%94%A8%E9%A1%BA%E5%BA%8F%E6%80%A7%E5%AE%B9%E5%99%A8)
  - [vector](https://github.com/jinbooooom/C-plus-plus/blob/master/ch5-STL.md#vector)
  - [map](https://github.com/jinbooooom/C-plus-plus/blob/master/ch5-STL.md#map)
  - [set](https://github.com/jinbooooom/C-plus-plus/blob/master/ch5-STL.md#set)
  - [更多 STL 方法，自己查找](https://github.com/jinbooooom/C-plus-plus/blob/master/ch5-STL.md#stl%E6%96%B9%E6%B3%95)