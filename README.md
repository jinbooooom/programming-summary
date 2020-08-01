## 个人编程语言学习时的笔记整理，主要用来查漏补缺
关于学习方法论，可以阅读[这篇文章](https://github.com/jinbooooom/life)。

其实看的书也不少，也做过一些小工具。但没有及时记录下来，然后几个月也不用，很多就忘了。  

我打算用**提问的方式**去记录一些知识点，这样每次阅读笔记的时候，看着目录，想想这个知识点我能不能回答。  

我会持续整理的，觉得对你有用可以先 star 收藏。

用 markdown 书写，建议使用 [Typora](https://www.typora.io/) 打开阅读。

## 主要包含：
- [C/C++ 学习笔记](https://github.com/jinbooooom/Programming-language-QA#cc)
- [python 问答](https://github.com/jinbooooom/Programming-language-QA#python-%E9%97%AE%E7%AD%94)
- Java 学习笔记(等待阅读完 Java 核心技术卷 I 和卷 II )

## 详细目录
### [C/C++](C-plus-plus/C-plus-plus.md)

### [C++编程基础](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#c%E7%BC%96%E7%A8%8B%E5%9F%BA%E7%A1%80)

- [Hello, world!](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#hello-world)

    - [main 函数前面的数据类型 int 与 void](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#main-%E5%87%BD%E6%95%B0%E5%89%8D%E9%9D%A2%E7%9A%84%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B-int-%E4%B8%8E-void)

    - [main 函数执行完后执行其他语句](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#main-%E5%87%BD%E6%95%B0%E6%89%A7%E8%A1%8C%E5%AE%8C%E5%90%8E%E6%89%A7%E8%A1%8C%E5%85%B6%E4%BB%96%E8%AF%AD%E5%8F%A5)

    - ["\n" 与 endl 的区别](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#n-%E4%B8%8E-endl-%E7%9A%84%E5%8C%BA%E5%88%AB)

    - [头文件里的 " " 与 < >](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%A4%B4%E6%96%87%E4%BB%B6%E9%87%8C%E7%9A%84---%E4%B8%8E--)

    - [命名空间 std](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%91%BD%E5%90%8D%E7%A9%BA%E9%97%B4-std)

    - [system("pause")](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#systempause)

    - [cout 与 printf()](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#cout-%E4%B8%8E-printf)

    - [main函数与命令行参数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#main%E5%87%BD%E6%95%B0%E4%B8%8E%E5%91%BD%E4%BB%A4%E8%A1%8C%E5%8F%82%E6%95%B0)

    - [预处理、编译与链接](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E9%A2%84%E5%A4%84%E7%90%86%E7%BC%96%E8%AF%91%E4%B8%8E%E9%93%BE%E6%8E%A5)

    - [静态链接与动态链接](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E9%9D%99%E6%80%81%E9%93%BE%E6%8E%A5%E5%92%8C%E5%8A%A8%E6%80%81%E9%93%BE%E6%8E%A5)

- [iostream cin cout cerr clog](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#iostream)

- [初始化](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%88%9D%E5%A7%8B%E5%8C%96)
  
- [逗号表达式](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E9%A2%84%E5%A4%84%E7%90%86%E7%BC%96%E8%AF%91%E4%B8%8E%E9%93%BE%E6%8E%A5)
  
- [指针](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E9%A2%84%E5%A4%84%E7%90%86%E7%BC%96%E8%AF%91%E4%B8%8E%E9%93%BE%E6%8E%A5)
  
  - [指针与数组名的区别](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%8C%87%E9%92%88%E4%B8%8E%E6%95%B0%E7%BB%84%E5%90%8D%E7%9A%84%E5%8C%BA%E5%88%AB)
  
  - [数组指针与指针数组](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%95%B0%E7%BB%84%E6%8C%87%E9%92%88%E4%B8%8E%E6%8C%87%E9%92%88%E6%95%B0%E7%BB%84)
    - [指针函数与函数指针](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%8C%87%E9%92%88%E5%87%BD%E6%95%B0%E4%B8%8E%E5%87%BD%E6%95%B0%E6%8C%87%E9%92%88)
    - [复杂指针声明](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%A4%8D%E6%9D%82%E6%8C%87%E9%92%88%E5%A3%B0%E6%98%8E)
  
- [指针与引用](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%8C%87%E9%92%88pointer%E4%B8%8E%E5%BC%95%E7%94%A8reference)
    - [引用作为函数参数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%BC%95%E7%94%A8%E4%BD%9C%E4%B8%BA%E5%87%BD%E6%95%B0%E5%8F%82%E6%95%B0)
    - [常引用作为函数参数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%B8%B8%E5%BC%95%E7%94%A8%E4%BD%9C%E4%B8%BA%E5%87%BD%E6%95%B0%E5%8F%82%E6%95%B0)
    - [函数返回引用与返回值](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%87%BD%E6%95%B0%E8%BF%94%E5%9B%9E%E5%BC%95%E7%94%A8%E4%B8%8E%E8%BF%94%E5%9B%9E%E5%80%BC)
  
- [指针运算](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%8C%87%E9%92%88%E8%BF%90%E7%AE%97)
    - [\*&p和&\*p](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#p%E5%92%8Cp)
    - [p+(或)-n](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#p%E6%88%96-n)
    - [\*p++，\*(p++)， (\*p)++，\*++p，++\*p](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#pp-ppp)
  
- [i++ 与 ++i 的效率](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#i-%E4%B8%8E-i-%E7%9A%84%E6%95%88%E7%8E%87)
  - [sizeof](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#sizeof)
    - [sizeof 计算普通变量与指针所占空间的大小](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#sizeof-%E8%AE%A1%E7%AE%97%E6%99%AE%E9%80%9A%E5%8F%98%E9%87%8F%E4%B8%8E%E6%8C%87%E9%92%88%E6%89%80%E5%8D%A0%E7%A9%BA%E9%97%B4%E7%9A%84%E5%A4%A7%E5%B0%8F)
    - [sizeof 计算空类的大小](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#sizeof-%E8%AE%A1%E7%AE%97%E7%A9%BA%E7%B1%BB%E7%9A%84%E5%A4%A7%E5%B0%8F)
    - [sizeof 计算类对象与结构体、联合体所占空间的大小](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#sizeof-%E8%AE%A1%E7%AE%97%E7%B1%BB%E5%AF%B9%E8%B1%A1%E4%B8%8E%E7%BB%93%E6%9E%84%E4%BD%93%E8%81%94%E5%90%88%E4%BD%93%E6%89%80%E5%8D%A0%E7%A9%BA%E9%97%B4%E7%9A%84%E5%A4%A7%E5%B0%8F)
    - [sizeof 与 strlen 区别](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#sizeof-%E4%B8%8E-strlen-%E5%8C%BA%E5%88%AB)
  - [strcpy 与memcpy区别](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#strcpy-%E4%B8%8E-memcpy-%E5%8C%BA%E5%88%AB)
  
- [作用域与生存周期](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E4%BD%9C%E7%94%A8%E5%9F%9F%E4%B8%8E%E7%94%9F%E5%AD%98%E5%91%A8%E6%9C%9F)
  
    - [花括号作用域](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E8%8A%B1%E6%8B%AC%E5%8F%B7%E4%BD%9C%E7%94%A8%E5%9F%9F)
    
    - [内存分配](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%86%85%E5%AD%98%E5%88%86%E9%85%8D)
  - [局部变量和全局变量](https://github.com/jinbooooom/C-plus-plus/blob/master/ch2-Procedural%20programming.md#%E5%B1%80%E9%83%A8%E5%8F%98%E9%87%8F%E5%92%8C%E5%85%A8%E5%B1%80%E5%8F%98%E9%87%8F)
    - [静态存储与动态存储](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%B1%80%E9%83%A8%E5%8F%98%E9%87%8F%E5%92%8C%E5%85%A8%E5%B1%80%E5%8F%98%E9%87%8F)
    - [C++变量保存在堆还是栈？](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#c%E5%8F%98%E9%87%8F%E4%BF%9D%E5%AD%98%E5%9C%A8%E5%A0%86%E8%BF%98%E6%98%AF%E6%A0%88)
    - [堆与栈的效率](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%A0%86%E4%B8%8E%E6%A0%88%E7%9A%84%E6%95%88%E7%8E%87)
    
  - [new 与 delete](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#new-%E4%B8%8E-delete)
    
  - [new/delete 与 malloc/free 关系](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#newdelete-%E4%B8%8E-mallocfree-%E5%85%B3%E7%B3%BB)
    
  - [头文件](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%A4%B4%E6%96%87%E4%BB%B6)
    
  - [#ifndef/#define/#endif作用](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#ifndefdefineendif%E4%BD%9C%E7%94%A8)
    - [extern "C"](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#extern-c)
    
  - [typedef 声明](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#typedef-%E5%A3%B0%E6%98%8E)
  
- [枚举类型](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%9E%9A%E4%B8%BE%E7%B1%BB%E5%9E%8B)
  
- [C结构体、C++结构体、C++类的区别](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#c%E7%BB%93%E6%9E%84%E4%BD%93c%E7%BB%93%E6%9E%84%E4%BD%93c%E7%B1%BB%E7%9A%84%E5%8C%BA%E5%88%AB)
  
- [结构体与联合体（共用体）的区别](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E7%BB%93%E6%9E%84%E4%BD%93%E4%B8%8E%E8%81%94%E5%90%88%E4%BD%93%E5%85%B1%E7%94%A8%E4%BD%93%E7%9A%84%E5%8C%BA%E5%88%AB)
  
### [类 & 对象](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E7%B1%BB--%E5%AF%B9%E8%B1%A1)

- [类访问修饰](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E7%B1%BB%E8%AE%BF%E9%97%AE%E4%BF%AE%E9%A5%B0%E7%AC%A6)
  
- [封装继承多态](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%B0%81%E8%A3%85%E7%BB%A7%E6%89%BF%E5%A4%9A%E6%80%81)
  
- [构造函数与析构函数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%9E%84%E9%80%A0%E5%87%BD%E6%95%B0%E4%B8%8E%E6%9E%90%E6%9E%84%E5%87%BD%E6%95%B0)
  
- [拷贝（复制）构造函数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%8B%B7%E8%B4%9D%E5%A4%8D%E5%88%B6%E6%9E%84%E9%80%A0%E5%87%BD%E6%95%B0)
  
  - [什么情况使用拷贝构造函数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E4%BB%80%E4%B9%88%E6%83%85%E5%86%B5%E4%BD%BF%E7%94%A8%E6%8B%B7%E8%B4%9D%E6%9E%84%E9%80%A0%E5%87%BD%E6%95%B0)
    - [浅复制与深复制](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%B5%85%E5%A4%8D%E5%88%B6%E4%B8%8E%E6%B7%B1%E5%A4%8D%E5%88%B6)
  
- [初始化列表](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8)
  
    - [使用初始化列表的原因](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E4%BD%BF%E7%94%A8%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8%E7%9A%84%E5%8E%9F%E5%9B%A0)
    - [必须使用初始化列表的情况](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%BF%85%E9%A1%BB%E4%BD%BF%E7%94%A8%E5%88%9D%E5%A7%8B%E5%8C%96%E5%88%97%E8%A1%A8%E7%9A%84%E6%83%85%E5%86%B5)
  - [初始化顺序](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%88%9D%E5%A7%8B%E5%8C%96%E9%A1%BA%E5%BA%8F)
    
  - [友元函数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%8F%8B%E5%85%83%E5%87%BD%E6%95%B0)
  
- [内联函数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%86%85%E8%81%94%E5%87%BD%E6%95%B0)
  
- [volatile](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#volatile)
  
- [explicit](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#explicit)
  
- [const](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#const)
  
    - [函数返回引用](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%87%BD%E6%95%B0%E8%BF%94%E5%9B%9E%E5%BC%95%E7%94%A8)
    - [const作用](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#const%E4%BD%9C%E7%94%A8)
    - [const修饰指针](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#const%E4%BF%AE%E9%A5%B0%E6%8C%87%E9%92%88)
  - [const 与 #define](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#const-%E4%B8%8E-define)
    
  - [存储类](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%AD%98%E5%82%A8%E7%B1%BB)
    
    - [auto](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#auto)
    - [static 作用](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#static%E4%BD%9C%E7%94%A8)
    - [静态数据成员与全局变量相比的优势](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E9%9D%99%E6%80%81%E6%95%B0%E6%8D%AE%E6%88%90%E5%91%98%E4%B8%8E%E5%85%A8%E5%B1%80%E5%8F%98%E9%87%8F%E7%9B%B8%E6%AF%94%E7%9A%84%E4%BC%98%E5%8A%BF)
    - [extern](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#extern)
    
  - [类型转换运算符](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#extern)
  
- [this指针](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#this%E6%8C%87%E9%92%88)
  
- [虚函数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E8%99%9A%E5%87%BD%E6%95%B0)
  
  - [虚函数是怎么实现的](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E8%99%9A%E5%87%BD%E6%95%B0%E6%98%AF%E6%80%8E%E4%B9%88%E5%AE%9E%E7%8E%B0%E7%9A%84)
    - [虚函数是否可以内联](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E8%99%9A%E5%87%BD%E6%95%B0%E6%98%AF%E5%90%A6%E5%8F%AF%E4%BB%A5%E5%86%85%E8%81%94)
    - [虚析构函数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E8%99%9A%E6%9E%90%E6%9E%84%E5%87%BD%E6%95%B0)
  
  - [静态联编和动态联编](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E9%9D%99%E6%80%81%E8%81%94%E7%BC%96%E5%92%8C%E5%8A%A8%E6%80%81%E8%81%94%E7%BC%96)
  
  - [有关虚函数的注意事项](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%9C%89%E5%85%B3%E8%99%9A%E5%87%BD%E6%95%B0%E7%9A%84%E6%B3%A8%E6%84%8F%E4%BA%8B%E9%A1%B9)
  
  - [纯虚函数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E7%BA%AF%E8%99%9A%E5%87%BD%E6%95%B0)
  
  - [虚函数、纯虚函数](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E8%99%9A%E5%87%BD%E6%95%B0%E7%BA%AF%E8%99%9A%E5%87%BD%E6%95%B0)
  
- [多重继承](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E5%A4%9A%E9%87%8D%E7%BB%A7%E6%89%BF)
  
- [类型安全](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E7%B1%BB%E5%9E%8B%E5%AE%89%E5%85%A8)
  
### [STL](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#stl)

- [vector 扩容原理](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#vector%E6%89%A9%E5%AE%B9%E5%8E%9F%E7%90%86)
  - [map 与 hash_map](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#map-%E4%B8%8E-hash_map-%E5%8C%BA%E5%88%AB)
    - [map 底层为什么用红黑树而不是平衡二叉树（AVL）](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#map-%E5%BA%95%E5%B1%82%E4%B8%BA%E4%BB%80%E4%B9%88%E7%94%A8%E7%BA%A2%E9%BB%91%E6%A0%91%E8%80%8C%E4%B8%8D%E6%98%AF%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91avl)
    - [map 和 unordered_map 的性能对比 ](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#map-%E5%92%8C-unordered_map-%E7%9A%84%E6%80%A7%E8%83%BD%E5%AF%B9%E6%AF%94)
  
- [STL中的 remove 和 erase 区别](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#stl%E4%B8%AD%E7%9A%84-remove-%E5%92%8C-erase-%E5%8C%BA%E5%88%AB)
  
- [智能指针](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%99%BA%E8%83%BD%E6%8C%87%E9%92%88)
    - [智能指针的内存泄露以及解决办法](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E6%99%BA%E8%83%BD%E6%8C%87%E9%92%88%E7%9A%84%E5%86%85%E5%AD%98%E6%B3%84%E9%9C%B2%E4%BB%A5%E5%8F%8A%E8%A7%A3%E5%86%B3%E6%96%B9%E6%B3%95)
    - [为什么摒弃 auto_ptr](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/C-plus-plus.md#%E4%B8%BA%E4%BB%80%E4%B9%88%E6%91%92%E5%BC%83-auto_ptr)

### [泛型编程](https://github.com/jinbooooom/C-plus-plus/blob/master/ch4-Generic%20Programming.md#%E6%B3%9B%E5%9E%8B%E7%BC%96%E7%A8%8B%E9%A3%8E%E6%A0%BC)

- [用实例理解泛型编程](https://github.com/jinbooooom/Programming-language-QA/blob/master/C-plus-plus/Generic-programming.md)



### [Python 问答](Python/python.md)

- [1.到底什么是Python？你可以在回答中与其他技术进行对比](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#1%E5%88%B0%E5%BA%95%E4%BB%80%E4%B9%88%E6%98%AFpython%E4%BD%A0%E5%8F%AF%E4%BB%A5%E5%9C%A8%E5%9B%9E%E7%AD%94%E4%B8%AD%E4%B8%8E%E5%85%B6%E4%BB%96%E6%8A%80%E6%9C%AF%E8%BF%9B%E8%A1%8C%E5%AF%B9%E6%AF%94)
- [2.什么是PEP8？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#2%E4%BB%80%E4%B9%88%E6%98%AFpep8)
- [3.什么是pickling和unpickling？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#3%E4%BB%80%E4%B9%88%E6%98%AFpickling%E5%92%8Cunpickling)
- [4.说说python程序运行过程？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#4%E8%AF%B4%E8%AF%B4python%E7%A8%8B%E5%BA%8F%E8%BF%90%E8%A1%8C%E8%BF%87%E7%A8%8B)
- [5.Python是怎样管理内存的？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#5python%E6%98%AF%E6%80%8E%E6%A0%B7%E7%AE%A1%E7%90%86%E5%86%85%E5%AD%98%E7%9A%84)
- [6.流重定向](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#6%E6%B5%81%E9%87%8D%E5%AE%9A%E5%90%91)
- [7.python为什么不能像C++一样快?如果要追求速度该怎么做？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#7python%E4%B8%BA%E4%BB%80%E4%B9%88%E4%B8%8D%E8%83%BD%E5%83%8Fc%E4%B8%80%E6%A0%B7%E5%BF%AB%E5%A6%82%E6%9E%9C%E8%A6%81%E8%BF%BD%E6%B1%82%E9%80%9F%E5%BA%A6%E8%AF%A5%E6%80%8E%E4%B9%88%E5%81%9A)
- [8.数组和元组之间的区别是什么？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#8%E6%95%B0%E7%BB%84%E5%92%8C%E5%85%83%E7%BB%84%E4%B9%8B%E9%97%B4%E7%9A%84%E5%8C%BA%E5%88%AB%E6%98%AF%E4%BB%80%E4%B9%88)
- [9.谈谈你对python中变量、对象和引用的理解](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#9%E8%B0%88%E8%B0%88%E4%BD%A0%E5%AF%B9python%E4%B8%AD%E5%8F%98%E9%87%8F%E5%AF%B9%E8%B1%A1%E5%92%8C%E5%BC%95%E7%94%A8%E7%9A%84%E7%90%86%E8%A7%A3)
- [10.python中的冻结二进制文件你了解多少？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#10python%E4%B8%AD%E7%9A%84%E5%86%BB%E7%BB%93%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%96%87%E4%BB%B6%E4%BD%A0%E4%BA%86%E8%A7%A3%E5%A4%9A%E5%B0%91)
- [11.Python都有哪些自带的数据类型？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#11python%E9%83%BD%E6%9C%89%E5%93%AA%E4%BA%9B%E8%87%AA%E5%B8%A6%E7%9A%84%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B)
- [12.什么是Python的命名空间？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#12%E4%BB%80%E4%B9%88%E6%98%AFpython%E7%9A%84%E5%91%BD%E5%90%8D%E7%A9%BA%E9%97%B4)
- [13.Python中的pass是什么？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#13python%E4%B8%AD%E7%9A%84pass%E6%98%AF%E4%BB%80%E4%B9%88)
- [14.在Python中什么是slicing？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#14%E5%9C%A8python%E4%B8%AD%E4%BB%80%E4%B9%88%E6%98%AFslicing)
- [15.Python中的docstring是什么？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#15python%E4%B8%AD%E7%9A%84docstring%E6%98%AF%E4%BB%80%E4%B9%88)
- [16.如何在Python中拷贝一个对象？这些拷贝之间有什么区别？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#16%E5%A6%82%E4%BD%95%E5%9C%A8python%E4%B8%AD%E6%8B%B7%E8%B4%9D%E4%B8%80%E4%B8%AA%E5%AF%B9%E8%B1%A1%E8%BF%99%E4%BA%9B%E6%8B%B7%E8%B4%9D%E4%B9%8B%E9%97%B4%E6%9C%89%E4%BB%80%E4%B9%88%E5%8C%BA%E5%88%AB)
- [17.Python中的负索引是什么？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#17python%E4%B8%AD%E7%9A%84%E8%B4%9F%E7%B4%A2%E5%BC%95%E6%98%AF%E4%BB%80%E4%B9%88)
- [18.如何将一个数字转换成一个字符串？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#18%E5%A6%82%E4%BD%95%E5%B0%86%E4%B8%80%E4%B8%AA%E6%95%B0%E5%AD%97%E8%BD%AC%E6%8D%A2%E6%88%90%E4%B8%80%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2)
- [19.Python中的模块和包是什么？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#19python%E4%B8%AD%E7%9A%84%E6%A8%A1%E5%9D%97%E5%92%8C%E5%8C%85%E6%98%AF%E4%BB%80%E4%B9%88)
- [20.函数中\*args，\**kwargs这两个参数是什么意思？我们为什么要使用它们？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#20%E5%87%BD%E6%95%B0%E4%B8%ADargskwargs%E8%BF%99%E4%B8%A4%E4%B8%AA%E5%8F%82%E6%95%B0%E6%98%AF%E4%BB%80%E4%B9%88%E6%84%8F%E6%80%9D%E6%88%91%E4%BB%AC%E4%B8%BA%E4%BB%80%E4%B9%88%E8%A6%81%E4%BD%BF%E7%94%A8%E5%AE%83%E4%BB%AC)
- [21.谈一谈Python的装饰器（decorator）](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#21%E8%B0%88%E4%B8%80%E8%B0%88python%E7%9A%84%E8%A3%85%E9%A5%B0%E5%99%A8decorator)
- [22.简要描述Python的垃圾回收机制（garbage collection）](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#22%E7%AE%80%E8%A6%81%E6%8F%8F%E8%BF%B0python%E7%9A%84%E5%9E%83%E5%9C%BE%E5%9B%9E%E6%94%B6%E6%9C%BA%E5%88%B6garbage-collection)
- [23.说明os,sys模块不同，并列举常用的模块方法？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#23%E8%AF%B4%E6%98%8Eossys%E6%A8%A1%E5%9D%97%E4%B8%8D%E5%90%8C%E5%B9%B6%E5%88%97%E4%B8%BE%E5%B8%B8%E7%94%A8%E7%9A%84%E6%A8%A1%E5%9D%97%E6%96%B9%E6%B3%95)
- [24.什么是lambda表达式？它有什么好处？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#24%E4%BB%80%E4%B9%88%E6%98%AFlambda%E8%A1%A8%E8%BE%BE%E5%BC%8F%E5%AE%83%E6%9C%89%E4%BB%80%E4%B9%88%E5%A5%BD%E5%A4%84)
- [25.表达式与语句有什么区别？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#25%E8%A1%A8%E8%BE%BE%E5%BC%8F%E4%B8%8E%E8%AF%AD%E5%8F%A5%E6%9C%89%E4%BB%80%E4%B9%88%E5%8C%BA%E5%88%AB)
- [26.\__new\__和\__init\__的区别。](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#26__new__%E5%92%8C__init__%E7%9A%84%E5%8C%BA%E5%88%AB)
- [27.Python中单下划线和双下划线分别是什么？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#27python%E4%B8%AD%E5%8D%95%E4%B8%8B%E5%88%92%E7%BA%BF%E5%92%8C%E5%8F%8C%E4%B8%8B%E5%88%92%E7%BA%BF%E5%88%86%E5%88%AB%E6%98%AF%E4%BB%80%E4%B9%88)
- [28.说一说Python自省。](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#28%E8%AF%B4%E4%B8%80%E8%AF%B4python%E8%87%AA%E7%9C%81)
- [29.如何在一个函数内部修改全局变量](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#29%E5%A6%82%E4%BD%95%E5%9C%A8%E4%B8%80%E4%B8%AA%E5%87%BD%E6%95%B0%E5%86%85%E9%83%A8%E4%BF%AE%E6%94%B9%E5%85%A8%E5%B1%80%E5%8F%98%E9%87%8F)
- [30.列出你知道的python标准库](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#30%E5%88%97%E5%87%BA%E4%BD%A0%E7%9F%A5%E9%81%93%E7%9A%84python%E6%A0%87%E5%87%86%E5%BA%93)
- [31.如何删除字典的键以及如何合并两个字典](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#31%E5%A6%82%E4%BD%95%E5%88%A0%E9%99%A4%E5%AD%97%E5%85%B8%E7%9A%84%E9%94%AE%E4%BB%A5%E5%8F%8A%E5%A6%82%E4%BD%95%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E5%AD%97%E5%85%B8)
- [32.python2和python3的range(100)的区别](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#32python2%E5%92%8Cpython3%E7%9A%84range100%E7%9A%84%E5%8C%BA%E5%88%AB)
- [33.简述with方法打开处理文件帮我我们做了什么？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#33%E7%AE%80%E8%BF%B0with%E6%96%B9%E6%B3%95%E6%89%93%E5%BC%80%E5%A4%84%E7%90%86%E6%96%87%E4%BB%B6%E5%B8%AE%E6%88%91%E6%88%91%E4%BB%AC%E5%81%9A%E4%BA%86%E4%BB%80%E4%B9%88)
- [34.列表[1,2,3,4,5],请使用map()函数输出[1,4,9,16,25]，并使用列表推导式提取出大于10的数，最终输出[16,25]](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#34%E5%88%97%E8%A1%A812345%E8%AF%B7%E4%BD%BF%E7%94%A8map%E5%87%BD%E6%95%B0%E8%BE%93%E5%87%BA1491625%E5%B9%B6%E4%BD%BF%E7%94%A8%E5%88%97%E8%A1%A8%E6%8E%A8%E5%AF%BC%E5%BC%8F%E6%8F%90%E5%8F%96%E5%87%BA%E5%A4%A7%E4%BA%8E10%E7%9A%84%E6%95%B0%E6%9C%80%E7%BB%88%E8%BE%93%E5%87%BA1625)
- [35.python中生成随机整数、随机小数、0-1之间小数方法](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#35python%E4%B8%AD%E7%94%9F%E6%88%90%E9%9A%8F%E6%9C%BA%E6%95%B4%E6%95%B0%E9%9A%8F%E6%9C%BA%E5%B0%8F%E6%95%B00-1%E4%B9%8B%E9%97%B4%E5%B0%8F%E6%95%B0%E6%96%B9%E6%B3%95)
- [36.python中的断言](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#36python%E4%B8%AD%E7%9A%84%E6%96%AD%E8%A8%80)
- [37.python2和python3区别？至少5个](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#37python2%E5%92%8Cpython3%E5%8C%BA%E5%88%AB%E8%87%B3%E5%B0%915%E4%B8%AA)
- [38.列出python中可变数据类型和不可变数据类型，并简述原理](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#38%E5%88%97%E5%87%BApython%E4%B8%AD%E5%8F%AF%E5%8F%98%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B%E5%92%8C%E4%B8%8D%E5%8F%AF%E5%8F%98%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B%E5%B9%B6%E7%AE%80%E8%BF%B0%E5%8E%9F%E7%90%86)
- [39.字典根据键从小到大排序](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#39%E5%AD%97%E5%85%B8%E6%A0%B9%E6%8D%AE%E9%94%AE%E4%BB%8E%E5%B0%8F%E5%88%B0%E5%A4%A7%E6%8E%92%E5%BA%8F)
- [40.过滤掉列表 a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]中的所有偶数](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#40%E8%BF%87%E6%BB%A4%E6%8E%89%E5%88%97%E8%A1%A8-a--1-2-3-4-5-6-7-8-9-10%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E5%81%B6%E6%95%B0)
- [41.正则表达式匹配中，（.\*）和（.\*?）匹配区别？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#41%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F%E5%8C%B9%E9%85%8D%E4%B8%AD%E5%92%8C%E5%8C%B9%E9%85%8D%E5%8C%BA%E5%88%AB)
- [42.\[\[1,2\],\[3,4\],\[5,6\]],一行代码展开该列表，得出\[1,2,3,4,5,6]](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#42123456%E4%B8%80%E8%A1%8C%E4%BB%A3%E7%A0%81%E5%B1%95%E5%BC%80%E8%AF%A5%E5%88%97%E8%A1%A8%E5%BE%97%E5%87%BA123456)
- [43.举例说明zip()函数用法](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#43%E4%B8%BE%E4%BE%8B%E8%AF%B4%E6%98%8Ezip%E5%87%BD%E6%95%B0%E7%94%A8%E6%B3%95)
- [44.提高python运行效率的方法](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#44%E6%8F%90%E9%AB%98python%E8%BF%90%E8%A1%8C%E6%95%88%E7%8E%87%E7%9A%84%E6%96%B9%E6%B3%95)
- [45.如何四舍五入？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#45%E5%A6%82%E4%BD%95%E5%9B%9B%E8%88%8D%E4%BA%94%E5%85%A5)
- [46.简述多线程、多进程](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#46%E7%AE%80%E8%BF%B0%E5%A4%9A%E7%BA%BF%E7%A8%8B%E5%A4%9A%E8%BF%9B%E7%A8%8B)
- [47.简述any()和all()方法](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#47%E7%AE%80%E8%BF%B0any%E5%92%8Call%E6%96%B9%E6%B3%95)
- [48.python中什么元素为假？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#48python%E4%B8%AD%E4%BB%80%E4%B9%88%E5%85%83%E7%B4%A0%E4%B8%BA%E5%81%87)
- [49.IOError、AttributeError、ImportError、IndentationError、IndexError、KeyError、SyntaxError、NameError分别代表什么异常?](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#49ioerrorattributeerrorimporterrorindentationerrorindexerrorkeyerrorsyntaxerrornameerror%E5%88%86%E5%88%AB%E4%BB%A3%E8%A1%A8%E4%BB%80%E4%B9%88%E5%BC%82%E5%B8%B8)
- [50.sort()和sorted()有什么区别？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#50sort%E5%92%8Csorted%E6%9C%89%E4%BB%80%E4%B9%88%E5%8C%BA%E5%88%AB)
- [51.lambda函数配合sorted()进行复杂排序](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#51lambda%E5%87%BD%E6%95%B0%E9%85%8D%E5%90%88sorted%E8%BF%9B%E8%A1%8C%E5%A4%8D%E6%9D%82%E6%8E%92%E5%BA%8F)
- [52.用两种方法去空格](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#52%E7%94%A8%E4%B8%A4%E7%A7%8D%E6%96%B9%E6%B3%95%E5%8E%BB%E7%A9%BA%E6%A0%BC)
- [53.简述python引用计数机制](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#53%E7%AE%80%E8%BF%B0python%E5%BC%95%E7%94%A8%E8%AE%A1%E6%95%B0%E6%9C%BA%E5%88%B6)
- [54.Python传参数是传值还是传址？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#54python%E4%BC%A0%E5%8F%82%E6%95%B0%E6%98%AF%E4%BC%A0%E5%80%BC%E8%BF%98%E6%98%AF%E4%BC%A0%E5%9D%80)
- [55.Python多线程（multi-threading）。这是个好主意吗？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#55python%E5%A4%9A%E7%BA%BF%E7%A8%8Bmulti-threading%E8%BF%99%E6%98%AF%E4%B8%AA%E5%A5%BD%E4%B8%BB%E6%84%8F%E5%90%97)
- [56.异常模块中try except else finally的区别](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#56%E5%BC%82%E5%B8%B8%E6%A8%A1%E5%9D%97%E4%B8%ADtry-except-else-finally%E7%9A%84%E5%8C%BA%E5%88%AB)
- [57.is与==有什么区别?](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#57is%E4%B8%8E%E6%9C%89%E4%BB%80%E4%B9%88%E5%8C%BA%E5%88%AB)
- [58.python除法‘/’ 与 ‘//’](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#58python%E9%99%A4%E6%B3%95-%E4%B8%8E-)
- [59.集合有哪些运算?](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#59%E9%9B%86%E5%90%88%E6%9C%89%E5%93%AA%E4%BA%9B%E8%BF%90%E7%AE%97)
- [60.列出字符串常用操作](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#60%E5%88%97%E5%87%BA%E5%AD%97%E7%AC%A6%E4%B8%B2%E5%B8%B8%E7%94%A8%E6%93%8D%E4%BD%9C)
- [61.列出列表的常用操作](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#61%E5%88%97%E5%87%BA%E5%88%97%E8%A1%A8%E7%9A%84%E5%B8%B8%E7%94%A8%E6%93%8D%E4%BD%9C)
- [62.两个等长列表如何构造字典？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#61%E5%88%97%E5%87%BA%E5%88%97%E8%A1%A8%E7%9A%84%E5%B8%B8%E7%94%A8%E6%93%8D%E4%BD%9C)
- [63.只有一个列表如何用enumerate构造字典?](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#63%E5%8F%AA%E6%9C%89%E4%B8%80%E4%B8%AA%E5%88%97%E8%A1%A8%E5%A6%82%E4%BD%95%E7%94%A8enumerate%E6%9E%84%E9%80%A0%E5%AD%97%E5%85%B8)
- [64.迭代器和可迭代对象分别是什么，它们之间有什么区别？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#64%E8%BF%AD%E4%BB%A3%E5%99%A8%E5%92%8C%E5%8F%AF%E8%BF%AD%E4%BB%A3%E5%AF%B9%E8%B1%A1%E5%88%86%E5%88%AB%E6%98%AF%E4%BB%80%E4%B9%88%E5%AE%83%E4%BB%AC%E4%B9%8B%E9%97%B4%E6%9C%89%E4%BB%80%E4%B9%88%E5%8C%BA%E5%88%AB)
- [65.单遍迭代器与多遍迭代器有什么区别？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#65%E5%8D%95%E9%81%8D%E8%BF%AD%E4%BB%A3%E5%99%A8%E4%B8%8E%E5%A4%9A%E9%81%8D%E8%BF%AD%E4%BB%A3%E5%99%A8%E6%9C%89%E4%BB%80%E4%B9%88%E5%8C%BA%E5%88%AB)
- [66.什么是多态？](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#66%E4%BB%80%E4%B9%88%E6%98%AF%E5%A4%9A%E6%80%81)
- [67.如何理解闭包?](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#67%E5%A6%82%E4%BD%95%E7%90%86%E8%A7%A3%E9%97%AD%E5%8C%85)
- [68.谈谈类中的访问限制](https://github.com/jinbooooom/Programming-language-QA/blob/master/Python/python.md#68%E8%B0%88%E8%B0%88%E7%B1%BB%E4%B8%AD%E7%9A%84%E8%AE%BF%E9%97%AE%E9%99%90%E5%88%B6)
- [69.装饰器实例](https://github.com/jinbooooom/Programming-language-QA/tree/master/Learning%20python/8.%20%E8%A3%85%E9%A5%B0%E5%99%A8#%E8%A3%85%E9%A5%B0%E5%99%A8)











