## STL

STL 主要由两部分组成：一是容器，二是操作容器的泛型算法。

容器一是包括 vector, list这两种顺序性容器，在顺序性容器身上主要进行迭代操作；二是包括 map 和 set 这两种关联容器，关联容器可以让我们快速查找容器的元素值。

### 所有容器的共同操作(包括string 类)

- == 和 != 返回 true 或者 false，两个容器是否相等
- = 赋值，将一个容器赋给另一个容器
- size()  返回当前的容器的元素数量
- empty()  判断容器是否为空，这个操作比 size() == 0 更有利率
- max_size() 容器所能容纳的最大元素数量
- clear() 删除所有元素
- begin() ，rbegin()
- end(), rend()
- insert(it, val) 将单一或者某一个范围的元素插入容器内
- erase() 将容器内的单一或者某一个范围内的元素删除
- swap()

【ESC 76】

### 序列容器

可序群集，每个元素位置取决于插入时机和地点，和元素值无关。如果以追加方式置入元素，那么他们的排列次序将和置入次序一致。

- vector: 以一块连续性内存来存放数据，适合随机访问，不适合插入/删除（在末尾插入/删除效率很高，在中间插入/删除就需要移动元素，不提供在首部插入的操作，因为效率低）
- list: 以**双向链接**而非连续内存来存储内容，适合插入/删除而不适合随机访问。
- deque: (双向队列)以连续内存存储数据，但是只能对最前端/末端的元素进行插入/删除操作

**容器配接器：**

- stack: 栈
- queue: 队列
- priority queue: 优先队列

<img src="sources\qe_vec.png" style="zoom: 100%;" />

#### vector

- vector<int> vec;  产生空的容器
- vector<int> vec(1024): 创建一个vector,元素个数为1024，对int 和double这种算术类型，不给初值，默认就是 0.
- vector<int> vec(1024, 42):创建一个vector，元素个数为1024,且值均为42
- vector<int> vec(begin,end):复制[begin,end)区间内另一个数组的元素到vector中，begin和end为指针或者迭代器
- vector<int> vec = {1, 2, 3, 4, 5}; // 像数组一样初始化，甚至可以去掉等于号。
- vec.push_back()
- vec.pop_back()
- vec.insert(it, val)
- size()  返回当前的容器的元素数量
- empty()  判断容器是否为空，这个操作比 size() == 0 更有利率
- max_size() 容器所能容纳的最大元素数量
- capacity() 重新分配空间前所能容纳的元素最大数量，看 reserve 预留多少
- reserve() 预留多少个元素

```C++
int main(int argc, char* argv[]) {
	vector<string> sen;
	sen.reserve(100);// 预留 100 个string空间，如果不预留，那么 capacity() 的输出就和 size() 一样
	vector<string>::iterator it = sen.begin();
	sen.push_back("hello");
	sen.push_back("world");
	sen.push_back("!");
	sen.insert(it, "ok");

	cout << sen.size() << endl;;		// 4
	cout << sen.max_size() << endl;		// 153391689
	cout << sen.capacity() << endl;		// 100

	it = sen.begin();	// 注意，insert() 会使插入的位置之后的所有 iterator 失效，故重新赋值
	vector<string>::iterator finish = sen.end();
	for (; it != finish; ++it)			// ok hello world !
		cout << *it << " ";				
	getchar();
}
```

```C++
vector<vector<char> >vec(row, vector<char>(col,'#'));//二维数组初始化
```



#### list

- insert(pos, elem)
- push_back(elem)
- pop_back()
- push_front()
- pop_front()

- remove(val) 移除所有值为 val 的元素
- remove_if(op) 移除所有造成op(elem)结果为 true 的元素
- erase(pos)
- erase(beg, end)
- clear()

#### deque

与 vector 接口几乎一样，deque 适合在两端操作，vector 没有在首部插入/删除的方法。要注意，在中间插入元素会导致 references、pointers、iterators 失效（两端没关系）

#### queue

- bool empty() const
- size_type size() const
- T& front() 返回指向队首元素的引用
- T& back() 返回指向队尾元素的引用
- void push(const T& x) 在队尾插入x
- void pop() 删除队首元素

#### stack

- bool empty() const
- size_type size() const
- T& top() 返回指向栈顶元素的引用
- void push(const T& x) 在栈顶插入x
- void pop() 删除栈顶元素

### 关联容器

已序群集，元素位置取决于特定的排序准则，如果置入元素，那么它们的位置取决于元素值，而与置入的次序无关。

自动排序造成一个重要限制：你不能直接改变元素值（只读），因为这样会打乱原本正确的顺序。因此，要改变元素值，必须先删除旧元素，再插入新元素。

- set: 内部元素有序，且只出现一次
- multiset: 与 set 相同，但允许重复的元素
- map: 键值对，每个键只出现一次
- multimap: 与 map 相同，

#### set

Set 由一群 key 组合而成，对于任何 key 值，set 只能存一份。

C++ 中，set 元素默认按照 less-than 顺序排列，这点跟 python 不一样，python里的 set 是无序的。

```C++
int ia[] = {3, 8, 8, 5, 3, 1, 5, 1};
vector<int> vec(ia, ia+8);
set<int> iset(vec.begin(), vec.end());
set<int>::iterator it = iset.begin();
for (; it != iset.end(); ++it)
    cout << *it << ' ';
//输出 1 3 5 8
```

- insert()  插入元素
- set_intersection()
- set_union()
- set_difference()
- set_symmetric_difference()

#### multiset

#### map

```C++
#include<iostream>
#include <map>
#include <string>
map<string, int> words;

words["good"] = 1;  //键 good 的值是 1
//如果一个key不在words钟，其默认值就为0
words["bad"];  // 0
//比如你想知道 words 中是否有 "python",第一种方法可以直接把 key当索引使用，
//但缺点是，若本无这个键，这样做就会添加这个键，虽然默认值为 0
if (words["python"]) {
    do something;  //如果 words 中有 "python"
}
//第二种做法是用map自带的find()函数。
map<string, int>::iterator it;
it = words.find("Python");
if (it != words.end() {
    do something;
    std::cout << it->second;
    //it->first 是 key，it->second 是 value
}
//第三种做法是利用map的count()函数
if (words.count("python")) {
    do something;
}
```

#### multimap

#### unordered_map 

#### unordered_multimap

### 算法

#### sort

```C++
#include <algorithm>
/* 函数sort(first, last, comp)；
first : 待排序数组起始地址；
last : 待排序数组结束地址；
comp : 排序方式，该参数是可省参数，如果省略则以升序方式排序；
*/
int vec[] = { 5, 1, 9, 4, 6, 7, 2, 0, 1 };
sort(vec, vec + 9); //就地改变，未使用 comp，默认按升序排列 
```

```C++
 bool comp(int a, int b) {
     return a > b;  //自己写排序规则，大的放在前面
 }
int vec[] = { 5, 1, 9, 4, 6, 7, 2, 0, 1 };
sort(vec, vec + 9, comp); //使用 comp，按自己的规则降序排列
```

#### STL方法

- 更多【ESC 78-92】
- [C/C++STL常用容器用法总结常用容器](https://blog.csdn.net/weixin_41162823/article/details/79759081)
- [STL·语雀](https://www.yuque.com/huihut/interview/stl_document)
- [C++/boost数据结构](https://zhuanlan.zhihu.com/p/73000084)

