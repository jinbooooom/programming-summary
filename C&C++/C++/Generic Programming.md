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