### 1.到底什么是Python？你可以在回答中与其他技术进行对比
下面是一些关键点：
- Python是一种解释型语言。这就是说，与C语言和C的衍生语言不同，Python代码在运行之前不需要编译。其他解释型语言还包括PHP和Ruby。Python是动态类型语言，指的是你在声明变量时，不需要说明变量的类型。你可以直接编写类似x=111和x="I'm a string"这样的代码，程序不会报错。Python非常适合面向对象的编程（OOP），因为它支持通过组合（composition）与继承（inheritance）的方式定义类（class）。
- Python中没有访问修饰符（access specifier，类似C++中的public和private），但以\__XX（双横线）结尾的函数或者变量相当于private。这么设计的依据是“大家都是成年人了”，Python本身没有任何机制阻止你干坏事，一切全靠自觉。
- 在Python语言中，函数是第一类对象（first-class objects）。这指的是它们可以被指定给变量，函数既能返回函数类型，也可以接受函数作为输入。类（class）也是第一类对象。Python代码编写快，但是运行速度比编译语言通常要慢。好在Python允许加入基于C语言编写的扩展，因此我们能够优化代码，消除瓶颈，这点通常是可以实现的。Numpy就是一个很好的例子，它的运行速度真的非常快，因为很多算术运算其实并不是通过Python实现的。
- Python用途非常广泛——网络应用，自动化，科学建模，大数据应用，等等。它也常被用作“胶水语言”，帮助其他语言和组件改善运行状况。Python让困难的事情变得容易，因此程序员可以专注于算法和数据结构的设计，而不用处理底层的细节。  
如果你应聘的是一个Python开发岗位，你就应该知道这是门什么样的语言，以及它为什么这么酷。以及它哪里不好。

### 2.什么是PEP8？
PEP8是一个编程规范，内容是一些关于如何让你的程序更具可读性的建议。  
其主要内容包括代码编排、文档编排、空格的使用、注释、文档描述、命名规范、编码建议等。

### 3.什么是pickling和unpickling？
Pickle模块读入任何Python对象，将它们转换成字符串，然后使用dump函数将其转储到一个文件中，这个过程叫做pickling。反之从存储的字符串文件中提取原始Python对象的过程，叫做unpickling。

### 4.Python是如何被解释的？
Python是一种解释性语言，它的源代码可以直接运行。Python解释器会将源代码转换成中间语言，之后再翻译成机器码再执行。

### 5.Python是怎样管理内存的？
- Python的内存管理是由私有heap空间管理的。所有的Python对象和数据结构都在一个私有heap中。程序员没有访问该heap的权限，只有解释器才能对它进行操作。
- Python的heap空间分配内存是由Python的内存管理模块进行的，其核心API会提供一些访问该模块的方法供程序员使用。
- Python有自带的垃圾回收系统，它回收并释放没有被使用的内存，让它们能够被其他程序使用。

### 6.流重定向
```python
# stream_redirection.py
import sys
import os
# use command:python stream_redirection.py > saveit.txt
print(sys.platform)
print(os.getcwd())
print('-' * 30)
print('hello world')
```
在终端使用命令行:
```shell
python stream_redirection.py > saveit.txt
```
就会把print()里的内容打印到文本saveit.txt  

Linux 允许将命令执行结果重定向到一个文件，将本应显示在终端上的内容 输出//追加到指定文件中：
- \> 表示输出，会覆盖文件原有的内容
- \>> 表示追加，会将内容追加到已有文件的末尾


### 7.什么是Python装饰器？
Python装饰器是Python中的特有变动，可以使修改函数变得更容易。

### 8.数组和元组之间的区别是什么？
数组和元组之间的区别：数组内容是可以被修改的，而元组内容是只读的。另外，元组可以被哈希，比如作为字典的关键字。

### 9.参数按值传递和引用传递是怎样实现的？
Python中的一切都是类，所有的变量都是一个对象的引用。引用的值是由函数确定的，因此无法被改变。但是如果一个对象是可以被修改的，你可以改动对象。

### 10.字典推导式和列表推导式是什么？
它们是可以轻松创建字典和列表的语法结构。

### 11.Python都有哪些自带的数据结构？
Python自带的数据结构分为可变的和不可变的。可变的有：数组、集合、字典；不可变的有：字符串、元组、数。

### 12.什么是Python的命名空间？
在Python中，所有的名字都存在于一个空间中，它们在该空间中存在和被操作————这就是命名空间。  
它就好像一个盒子，每一个变量名字都对应着一个对象。当查询变量的时候，会从该盒子里面寻找相应的对象。  
命名空间是一个字典的实现，键为变量名，值是变量对应的值。各个命名空间是独立没有关系的，一个命名空间中不能有重名，但是不同的命名空间可以重名而没有任何影响。  
https://www.cnblogs.com/apollo1616/articles/9785371.html

### 13.Python中的pass是什么？
Pass是一个在Python中不会被执行的语句。在复杂语句中，如果一个地方需要暂时被留白，它常常被用于占位符。

### 14.在Python中什么是slicing？
Slicing是一种在有序的对象类型中（数组，元组，字符串）节选某一段的语法。

### 15.Python中的docstring是什么？
Python中文档字符串被称为docstring，它在Python中的作用是为函数、模块和类注释生成文档。

### 16.如何在Python中拷贝一个对象？这些拷贝之间有什么区别？
- 赋值（=），就是创建了对象的一个新的引用，不会开辟新的内存空间。
- 浅拷贝：创建一个新的对象，其内容是原对象的引用。
	浅拷贝有三种形式：切片操作，工厂函数，copy模块中的copy函数。
    如： lst = [1,2,3,[4,5]]
    - 切片操作：lst1 = lst[:] 或者 lst1 = [each for each in lst]
    - 工厂函数：lst1 = list(lst)
    - copy函数：lst1 = copy.copy(lst)
	浅拷贝之所以称为浅拷贝，因为它仅仅只拷贝了一层，在lst中有一个嵌套的list[4,5]，如果我们修改了它，情况就不一样了。
- 深拷贝：创建一个新的对象，并且递归的复制多层嵌套里的对象，深拷贝出来的对象是一个全新的对象，不再与原来的对象有任何关联。（copy模块的deep.deepcopy()函数）
```python
# “=”赋值可变数据类型与不可变数据类型
>>> a = 3
>>> b = a  # 指针 b 与 a 指向同一片内存地址：常量 3 所在的内存地址
>>> a = 7  # 指针 a 现在改变指向，指向 7 所在的内存地址
>>> b
3

>>> a = [1, 2]
>>> b = a  # 指针 b 与 a 指向同一片内存地址：可变类型列表 [1, 2] 所在的内存地址
>>> id(a)
140461052988872
>>> id(b)
140461052988872
>>> a = 1  # 指针 a 现在改变指向，指向常量 1 所在的内存地址
>>> b
[1, 2]

>>> a = [1, 2]
>>> b = a  # 指针 b 与 a 指向同一片内存地址：可变类型列表 [1, 2] 所在的内存地址
>>> a.append(3)
>>> b  # 虽然指针 b 指向的地址没有改变，但指向的地址里的数据改变了，
[1, 2, 3]
```

```python
# copy.copy() 与 copy.deepcopy()
>>> import copy  # copy 浅拷贝，没有拷贝子对象，所以原始数据改变，子对象会改变
>>> a=[1,2,3,4,['a','b']]
>>> c=copy.copy(a)
>>> a.append(5)
>>> a
[1, 2, 3, 4, ['a', 'b'], 5]

>>> c
[1, 2, 3, 4, ['a', 'b']]

>>> a[4].append('c')
>>> a
[1, 2, 3, 4, ['a', 'b', 'c'], 5]

>>> c
[1, 2, 3, 4, ['a', 'b', 'c']]
```
综上所述，浅copy和深copy:  
copy浅拷贝（copy.copy()），没有拷贝子对象，所以原始数据改变，子对象会改变;  
深copy(copy.deepcopy())，递归的复制它所包含的对象，所以原始对象的改变不会造成深拷贝里任何子元素的改变;  
它们的相同之处是，父对象都没有改变.  
[Python里面如何拷贝一个对象·时间带着假象流淌](https://www.cnblogs.com/ConnorShip/p/10009573.html)
[Python中的赋值(复制)、浅拷贝、深拷贝之间的区别·碧水幽幽泉](https://www.cnblogs.com/huangbiquan/p/7795152.html)

### 17.Python中的负索引是什么？
Python中的序列索引可以是正也可以是负。如果是正索引，0是序列中的第一个索引，1是第二个索引。  
如果是负索引，（-1）是最后一个索引而（-2）是倒数第二个索引。

### 18.如何将一个数字转换成一个字符串？
你可以使用自带函数str()将一个数字转换为字符串。如果你想要八进制或者十六进制数，可以用oct()或hex()。

### 19.Python中的模块和包是什么？
在Python中，模块是搭建程序的一种方式。每一个Python代码文件都是一个模块，并可以引用其他的模块，比如对象和属性。  
一个包含许多Python代码的文件夹是一个包。一个包可以包含模块和子文件夹。

### 20.函数中\*args，\**kwargs这两个参数是什么意思？我们为什么要使用它们？
如果不确定往一个函数中传入多少参数，或者我们希望以元组（tuple）或者列表（list）的形式传参数的时候，我们可以使用\*args（单星号）。如果我们不知道往函数中传递多少个关键词参数或者想传入字典的值作为关键词参数的时候我们可以使用\**kwargs（双星号），args、kwargs两个标识符是约定俗成的用法。

另一种答法：当函数的参数前面有一个星号\*号的时候表示这是一个可变的位置参数，两个星号\**表示这个是一个可变的关键词参数。星号\*把序列或者集合解包（unpack）成位置参数，两个星号\**把字典解包成关键词参数。 

### 21.谈一谈Python的装饰器（decorator）
装饰器本质上是一个Python函数，它可以让其它函数在不作任何变动的情况下增加额外功能，装饰器的返回值也是一个函数对象。它经常用于有切面需求的场景。比如：插入日志、性能测试、事务处理、缓存、权限校验等。有了装饰器我们就可以抽离出大量的与函数功能无关的雷同代码进行重用。  
[BAT面试题39：Python中的装饰器用过吗？](https://cloud.tencent.com/developer/article/1465332)

### 22.简要描述Python的垃圾回收机制（garbage collection）
Python中的垃圾回收是以引用计数为主，标记-清除和分代收集为辅。
- 引用计数：Python在内存中存储每个对象的引用计数，如果计数变成0，该对象就会消失，分配给该对象的内存就会释放出来。 
- 标记-清除：一些容器对象，比如list、dict、tuple，instance等可能会出现引用循环，对于这些循环，垃圾回收器会定时回收这些循环（对象之间通过引用（指针）连在一起，构成一个有向图，对象构成这个有向图的节点，而引用关系构成这个有向图的边）。
- 分代收集：Python把内存根据对象存活时间划分为三代，对象创建之后，垃圾回收器会分配它们所属的代。每个对象都会被分配一个代，而被分配更年轻的代是被优先处理的，因此越晚创建的对象越容易被回收。  
[Python垃圾回收机制--完美讲解!](https://www.jianshu.com/p/1e375fb40506)

### 23.说明os,sys模块不同，并列举常用的模块方法？
os模块负责程序与操作系统的交互，提供了访问操作系统底层的接口。  
sys模块负责程序与Python解释器的交互，提供了一系列的函数和变量用户操作Python运行时的环境。  
[os和sys模块一些常用的方法:](https://www.cnblogs.com/pycode/p/sysos.html)

### 24.什么是lambda表达式？它有什么好处？
简单来说，lambda表达式通常是当你需要使用一个函数，但是又不想去命名一个函数的时候使用，也就是通常所说的匿名函数。  
lambda表达式一般的形式是：关键词lambda后面紧接一个或多个参数，紧接一个冒号“：”，紧接一个表达式。lambda表达式是一个表达式不是一个语句。  
```python
L = {'add':(lambda x,y:x+y),
     'pow':(lambda x,y:x**y)}
print(L['add'](2,3))  # 5
print(L['pow'](2,3))  # 8
```
### 25.[表达式与语句有什么区别？](https://blog.csdn.net/qq_37566910/article/details/84563438)  
Python代码由表达式和语句组成，并由Python解释器负责执行。  
它们的主要区别是“表达式”是一个值，它的结果一定是一个Python对象。当Python解释器计算它时结果可以是任何对象。例如42，1+2，int(‘123’)，range(10)等。  
结果不是对象的代码则成为‘语句’。它们表示的是一个动作而不是生成或者返回一个值。常见的Python语句有print，if/else，def等

### 26.\__new\__和\__init\__的区别。
\__init\__为初始化方法，创建对象后，就立刻被默认调用了，可接收参数。  
\__new\__方法是真正的构造函数。\__new\__是实例创建之前被调用，它的任务是创建并返回该实例。  
\__init\__有一个参数self，就是\__new\__返回的实例，\__init\__在\__new\__的基础上可以完成一些其它初始化的动作，\__init\__不需要返回值\__init\__是实例创建之后被调用的，然后设置对象属性的初始值。  
总结：\__new\__方法在\__init\__方法之前被调用，并且\__new\__方法的返回值将传递给\__init_\_方法作为第一个参数，最后\__init\__给这个实例设置一些参数。  
[Python中的__new__及其用法](https://my.oschina.net/kinegratii/blog/334968)

### 27.Python中单下划线和双下划线分别是什么？
- \__name\__：一种约定，Python内部的名字，用来与用户自定义的名字区分开，防止冲突  
- \_name：一种约定，用来指定变量私有  
- \__name：解释器用\_classname\__name来代替这个名字用以区别和其他类相同的命名
[python中的下划线](https://segmentfault.com/a/1190000002611411)

### 28.说一说Python自省。
自省就是面向对象的语言所写的程序在运行时，所能知道对象的类型。简单一句话就是运行时能够获得对象的类型。比如：type()、dir()、getattr()、hasattr()、isinstance()   
[Python自省（反射）指南](https://kb.cnblogs.com/page/87128/)

### 29.如何在一个函数内部修改全局变量
比如：
```python
a = 5
def foo():
	a = 3
foo()
print(a)  # 5
```
输出 5  
```python
a = 5
def foo():
	"""
	利用global在函数内部声明该变量，修改其为全局变量
	"""
	global a
	a = 3
foo()
print(a)  # 3
```
输出 3  

### 30.列出你知道的python标准库
os, sys, re, math, datetime, string, random等

### 31.如何删除字典的键以及如何合并两个字典
```python
>>> d = {'name':'Lux','age':18}
>>> d
{'age': 18, 'name': 'Lux'}
>>> del d['age']
>>> d
{'name': 'Lux'}
>>> d2 = {'game':'LOL'}
>>> d.update(d2)
>>> d2
{'game': 'LOL'}
>>> d
{'game': 'LOL', 'name': 'Lux'}
```

### 32.python2和python3的range(100)的区别
python2返回列表，python3返回迭代器，节约内存.

### 33.简述with方法打开处理文件帮我我们做了什么？
```python
f = open("./t.txt", "w+")
try:
	f.write("hello world")
except:
	pass
finally:
	f.close()
```
打开文件在进行读写的时候可能会出现一些异常状况，如果按照常规的f.open  
写法，我们需要try,except,finally，做异常判断，并且文件最终不管遇到什么情况，都要执行finally f.close()关闭文件，with方法帮我们实现了finally中f.close

### 34.列表[1,2,3,4,5],请使用map()函数输出[1,4,9,16,25]，并使用列表推导式提取出大于10的数，最终输出[16,25]
```python
arr = [1, 2, 3, 4, 5]
def f(x):
	return x**2
res = list(map(f, arr))
print(res)  # [1, 4, 9, 16, 25]

res = [x**2 for x in arr if x**2 > 10]
print(res)  # [16, 25]
```

### 35.python中生成随机整数、随机小数、0-1之间小数方法
```python
import random
import numpy as np
 
a = random.randint(10,20)
res = np.random.randn(5)
ret = random.random()
print("正整数:"+str(a))
print("5个随机小数:"+str(res))
print("0-1之间的随机小数:"+str(ret))
"""
正整数:14
5个随机小数:[ 2.28309587 -0.17086874 -1.51438665  1.13570107 -0.09369251]
0-1之间的随机小数:0.6803547742221879
"""
```
[python random](https://www.runoob.com/python/func-number-random.html)  
[python--随机函数（random,uniform,randint,randrange,shuffle,sample）](https://www.cnblogs.com/chamie/p/4917820.html)

### 36.python中的断言
assert（）方法，断言成功，则程序继续执行，断言失败，则程序报错。
```python
a = 3
assert(a > 1)
print("successfully")
b = 4
assert(b > 5)
print("failed")
"""
successfully
Traceback (most recent call last):
  File "t.py", line 5, in <module>
    assert(b > 5)
AssertionError
""""
```

### 37.python2和python3区别？至少5个
- 1、Python3 使用 print 必须要以小括号包裹打印内容，比如 print('hi')，Python2 既可以使用带小括号的方式，也可以使用一个空格来分隔打印内容，比 如 print 'hi'
- 2、python2 range(1,10)返回列表，python3中返回迭代器，节约内存
- 3、python2 中使用 ascii 编码，python中使用utf-8编码
- 4、python2 中 unicode表示字符串序列，str表示字节序列，python3中str表示字符串序列，byte表示字节序列
- 5、python2中为正常显示中文，引入coding声明，python3中不需要
- 6、python2中是raw_input()函数，python3中是input()函数

### 38.列出python中可变数据类型和不可变数据类型，并简述原理
不可变数据类型：数值型、字符串型string和元组tuple  
不允许变量的值发生变化，如果改变了变量的值，相当于是新建了一个对象，而对于相同的值的对象，在内存中则只有一个对象（一个地址），如下面代码中用id()方法可以打印对象的id  
```python
>>> a = 3
>>> b = 3
>>> id(3)
94437307314304
>>> id(b)
94437307314304
```
可变数据类型：列表list和字典dict；
允许变量的值发生变化，即如果对变量进行append、+=等这种操作后，只是改变了变量的值，而不会新建一个对象，变量引用的对象的地址也不会变化。对于相同的值的不同对象，在内存中地址不同，即每个对象都有自己的地址，相当于内存中对于同值的对象保存了多份，这里不存在引用计数，是实实在在的对象。
```python
>>> a = [1,2]
>>> b = [1,2]
>>> a == b
True
>>> a is b
False
>>> id(a)
139733341882056
>>> id(b)
139733368805448
```

### 39.字典根据键从小到大排序
```python
y = {1:3, 2:2, 3:1}
by_key =  sorted(y.items(),key = lambda item:item[0])
by_value = sorted(y.items(),key = lambda item:item[1])
print by_key   # 结果为[(1, 3), (2, 2), (3, 1)]，即按照键名排列
print by_value # 结果为[(3, 1), (2, 2), (1, 3)]，即按照键值排列
```
[python之对字典按照键的大小进行排序！](https://blog.csdn.net/leokingszx/article/details/81154681)

### 40.过滤掉列表 a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]中的所有偶数
```python
a = [1,2,3,4,5,6,7,8,9,10]
print([x for x in a if x & 1])

def foo(a):
	return a & 1
new_a = list(filter(foo, a))
print(new_a)
```

### 41.正则表达式匹配中，（.*）和（.*?）匹配区别？
- （.*）是贪婪匹配，会把满足正则的尽可能多的往后匹配
- （.*?）是非贪婪匹配，会把满足正则的尽可能少匹配


### 42.[[1,2],[3,4],[5,6]],一行代码展开该列表，得出[1,2,3,4,5,6]
```python
>>> a = [[1,2],[3,4],[5,6]]
>>> new_a = [i for x in a for i in x]
>>> new_a
[1, 2, 3, 4, 5, 6]
```

### 42.异常模块中try except else finally的区别
- try..except..else没有捕获到异常，执行else语句
- try..except..finally不管是否捕获到异常，都执行finally语句

### 43.举例说明zip()函数用法
zip()函数在运算时，会以一个或多个序列（可迭代对象）做为参数，返回一个元组的列表。同时将这些序列中并排的元素配对。  
zip()参数可以接受任何类型的序列，同时也可以有两个以上的参数;当传入参数的长度不同时，zip能自动以最短序列长度为准进行截取，获得元组。
```python
>>> a = [1,2]
>>> b = ['a','b']
>>> list(zip(a, b))  # a,b长度相同，构建元素是元组的列表
[(1, 'a'), (2, 'b')]
>>> x = "abcdef"
>>> y = "12345"
>>> dict(zip(x, y))  # x,y长度不同，构建字典
{'d': '4', 'b': '2', 'e': '5', 'c': '3', 'a': '1'}
>>> 
```

### 44.提高python运行效率的方法
- 1、使用生成器，因为可以节约大量内存
- 2、循环代码优化，避免过多重复代码的执行
- 3、核心模块用Cython PyPy等，提高效率
- 4、多进程、多线程、协程
- 5、多个if elif条件判断，可以把最有可能先发生的条件放到前面写，这样可以减少程序判断的次数，提高效率

### 45.如何四舍五入？
```python
>>> a = 123.45678
>>> round(a, 2)
123.46
>>> round(a, 1)
123.5
>>> round(a, 0)
123.0
>>> round(a, -1)
120.0
>>> round(a, -2)
100.0
>>> round(a, -3)
0.0

>>> a = 987.876
>>> round(a, -3)
1000.0
>>> round(a, -2)
1000.0
>>> round(a, -1)
990.0
>>> round(a, 0)
988.0
>>> round(a, 1)
987.9
>>> round(a, 2)
987.88
```
### 46.简述多线程、多进程
进程：
- 1、操作系统进行资源分配和调度的基本单位，多个进程之间相互独立
- 2、稳定性好，如果一个进程崩溃，不影响其他进程，但是进程消耗资源大，开启的进程数量有限制
线程：
- 1、CPU进行资源分配和调度的基本单位，线程是进程的一部分，是比进程更小的能独立运行的基本单位，一个进程下的多个线程可以共享该进程的所有资源
- 2、如果IO操作密集，则可以多线程运行效率高，缺点是如果一个线程崩溃，都会造成进程的崩溃
应用：
IO密集的用多线程，在用户输入，sleep 时候，可以切换到其他线程执行，减少等待的时间
CPU密集的用多进程，因为假如IO操作少，用多线程的话，因为线程共享一个全局解释器锁，当前运行的线程会霸占GIL，其他线程没有GIL，就不能充分利用多核CPU的优势

### 47.简述any()和all()方法
都返回 bool 值。  
any():只要迭代器中有一个元素为真就为真  
all():迭代器中所有的判断项返回都是真，结果才为真  

### 48.python中什么元素为假？
0，空字符串''，空列表[]、空字典{}、空元组()、空集合set()、None, False

### 49.IOError、AttributeError、ImportError、IndentationError、IndexError、KeyError、SyntaxError、NameError分别代表什么异常?
- IOError：输入输出异常
- AttributeError：试图访问一个对象没有的属性
- ImportError：无法引入模块或包，基本是路径问题
- IndentationError：语法错误，代码没有正确的对齐
- IndexError：下标索引超出序列边界
- KeyError:试图访问你字典里不存在的键
- SyntaxError:Python代码逻辑语法出错，不能执行
- NameError:使用一个还未赋予对象的变量

### 50.sort()和sorted()有什么区别？
- sort() 只是 list 的方法，而 sorted() 可以接受任何的可迭代对象
- 若 L 为列表，L.sort() 无返回值，就地更改列表
- sorted(L) 返回一个新的排好序的列表，原列表无变化

### 51.lambda函数配合sorted()进行复杂排序
```python
# 对元素是元组的集合排序
>>> a = {('a',3),('c',2),('b',1)}
>>> sorted(a, key=lambda x:x[0])
[('a', 3), ('b', 1), ('c', 2)]
>>> sorted(a, key=lambda _:_[1])
[('b', 1), ('c', 2), ('a', 3)]
```

```python
# 多条件排序
>>> a = [-5,8,0,5,4,-4,20,-2,-8,2,-20]
>>> sorted(a, key=lambda x:(x<5,abs(x)))
[5, 8, 20, 0, -2, 2, 4, -4, -5, -8, -20]
>>> sorted(a, key=lambda x:(abs(x),x<5))
[0, -2, 2, 4, -4, 5, -5, 8, -8, 20, -20]
```
首先，要知道sorted 内部实现使用了归并排序，而归并排序是稳定的排序，就是说当元素比不出大小时，其相对位置是不变的。  
那么，利用稳定排序的特性，key函数有几个返回值就排序几次，先排序次要条件，后排序主要条件(条件从前到后重要程度依次降低)，用主要条件覆盖次要条件，主要条件相同时，又不会改变之前排好的次要条件的相对位置，就实现了多条件排序。  
给我们的直观效果是，主要条件排不出先后顺序的元素，就按照次要条件排序。  
```
>>> 1<6>4>0  # 而这是按照链式法则比较大小,6大于4小于1,4大于0小于6,整个表达式为 True
True
>>> (1<6)>(4>0)  # True > True? 返回False
False
>>> (1<6)>(4>9)
True
>>> True > False
True
```
[python sorted函数多条件排序是怎么回事](https://www.cnblogs.com/pyonwu/p/10695148.html)

### 52.用两种方法去空格
```python
>>> s = "hello world ha ha"
>>> res = s.replace(" ","")
>>> res
'helloworldhaha'

>>> s
'hello world ha ha'

>>> res = s.split(" ")
>>> res = "".join(res)
>>> res
'helloworldhaha'

### 53.简述python引用计数机制
python垃圾回收主要以引用计数为主，标记-清除和分代清除为辅的机制，其中标记-清除和分代回收主要是为了处理循环引用的难题。  
引用计数算法  
当有1个变量保存了对象的引用时，此对象的引用计数就会加1，当使用del删除变量指向的对象时，如果对象的引用计数不为1，比如3，那么此时只会让这个引用计数减1，即变为2，当再次调用del时，变为1，如果再调用1次del，此时会真的把对象进行删除。
```

### 54.Python传参数是传值还是传址？
python中函数参数是引用传递（注意不是值传递）。  
对于不可变类型（数值型、字符串、元组），因变量不能修改，所以运算不会影响到变量自身；  
而对于可变类型（列表字典）来说，函数体运算可能会更改传入的参数变量。  
```python
def foo(L):
	L.append([1,2])

arr = [3,4]
print(arr)  # [3, 4]
foo(arr)
print(arr)  # [3, 4, [1, 2]]
```

### 55.Python多线程（multi-threading）。这是个好主意吗？
Python并不支持真正意义上的多线程，Python提供了多线程包。Python中有一个叫Global Interpreter Lock（GIL）的东西，它能确保你的代码中永远只有一个线程在执行。经过GIL的处理，会增加执行的开销。这就意味着如果你先要提高代码执行效率，使用threading不是一个明智的选择，当然如果你的代码是IO密集型，多线程可以明显提高效率，相反如果你的代码是CPU密集型的这种情况下多线程大部分是鸡肋。  
[详解Python中的多线程编程](https://www.jb51.net/article/63784.htm)  
[CPU-bound(计算密集型) 和I/O bound(I/O密集型)](https://blog.csdn.net/q_l_s/article/details/51538039)  

## 推荐/参考链接
- [Python工程师面试必备25条Python知识点](https://zhuanlan.zhihu.com/p/32818342)
- [常见面试题整理--Python概念篇](https://zhuanlan.zhihu.com/p/23526961)
- [110道Python面试题（真题）](https://zhuanlan.zhihu.com/p/54430650)














