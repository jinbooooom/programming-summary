## 说明

《Java核心技术》 原书第11版笔记总结，该笔记已假设你有C++基础。
文件夹解释：

- JavaCore：原书代码
- mine：自己修改的原书代码，用于测试心中想法

**主要记载**

- 与C++不同的地方
- 一些容易犯错的地方

【i66】表示该总结出自JavaCore 卷一的66页，同理：

【ii66】表示该总结出自JavaCore 卷二的66页。

有时我也懒得写具体是哪一页，如果该知识点也不是特别的发人深省。

## 基础知识

### 编译JAVA代码

```shell
javac test.java
# 生成test.class
# 运行
java test
```

## Java的基本程序设计结构

【v1ch03】

### 基础部分与 C++的不同之处

- 源代码的文件名必须与公共类名形同

- java中的数据类型与平台无关（解决了跨平台移植问题），int始终占4位，也没有无符号类型【i30，31】
- main函数必须静态，public static void main() {}
- Java中boolean类型和整型不能相互转换【i34】
- Java不区分变量的声明与定义
- 对于局部变量如果可以通过变量的初始值推断出它的类型，就可以不用再声明类型，如：

```java
var greeting = "hello"; // greeting is string
```

- 使用final定义常量，有cosnt关键字，但并没有使用

- 前缀++与后缀++与C++一样理解

- String类没有提供修改字符串中某个字符的方法。即String对象是不可变的如上面的greeting，你不能通过它修改“hello”，但你可以让greeting引用另一个字符串“help”。理解，string类大致类似char *指针。

  不可变字符串有另一个优点：编译器可以让字符串共享，类似于Python中的数字一样，变量是对它的引用。可以理解为将各种字符串放在公共的储存池中，字符串变量指向储存池中的位置，复制一个字符串变量，原始的字符串与复制的字符串共享相同的字符。毕竟Java设计者认为共享带来的高效率远远胜过与提取子串、拼接字符串所带来的低效率。

- 不要用==判断两个字符串是否相等，它判断的是指针地址，而不是字面量。应用"hello".equals(greeting);

  在C++中string类重载了==运算符以便检查字符串内容的相等性。

  Java的字符串外观看起来就像C++中的数字，但检测相等性时又像指针。

  String API 【i49-51】

- C++中可以在嵌套的块中重定义一个变量。用来屏蔽外层的定义。在Java中编译不通过。

  所以如果在for循环中定义了一个变量，如i，那么该变量就不能在循环体之外被使用。【i63，70】

```java
public static void main(string[] args)
{
   int n;
   {
      int k;
      int n; // 编译错误，不能在内层块中重定义 n，C++可以
   } // k 的作用域到此为止
}

for (int i = 0; i < 10; i++)
{
   doSomething();
} // i 的作用域到此为止

int i;
for (i = 0; i < 10; i++)
{
   doSomething();
} // i 的作用域仍然在持续
```

- switch语句中，case可以是字符串字面量，而C++不可以对std::string case。
- Java提供一个带标签的break语句，用于跳出多重嵌套的循环语句。C++不支持。事实上可以将标签语句应用到任何语句上，如跳出if或者跳出块。【i75】

```java
public static void main(string[] args)
{
   int n;
   read_data: //break的标签必须放在希望跳出的最外层循环之前，且必须紧跟一个冒号
   while (...)
   {
      ...
      for (...)
      {
         ...
         if (n < 0)
            break read_data; //直接跳出最外层的while循环，而不是for
      }
   } 
}
```

- 带标签的continue语句跳到与标签匹配的循环首部

- 关于数组

```java
int[] a = new int[100]; // Java
int* a = new int[100]; // C++

int[] luckyNumbers = smallPrimes;
luckyNumbers[5] = 12; // now samllPrimes[5] is also 12.浅拷贝

// 拷贝值
int[] copiedLuckyNumbers = Arrays.copyOf(luckyNumbers, luckyNumbers.length)
// 设置新数组的大小为之前2倍大，额外的元素用0填充
int[] copiedLuckyNumbers = Arrays.copyOf(luckyNumbers, 2 * luckyNumbers.length)

```

Java中实际上没有多维数组，只有一维数组。多维数组被解释为数组的数组。

```java
// 对于二维数组可以交换它们的行，例如
double[][] arr = {赋值};
double[] tmp = arr[i];
arr[i] = arr[i + 1];
arr[i + 1] = tmp;
```

你也可以创造不规则数组，即每一行的长度不一样【i89】