#include <iostream>

#define showfunc std::cout << __PRETTY_FUNCTION__ << std::endl;

template <class T>
class SmartPtr
{
private:
    T *mPtr;
    size_t *mRef;

public:
    SmartPtr(T *p = 0);
    SmartPtr(const SmartPtr &src); // 加上 explicit 可以拒绝隐式拷贝构造
    SmartPtr &operator=(const SmartPtr &rhs);
    T *operator->() const;
    T &operator*() const;
    ~SmartPtr();

private:
    void decRef(); //只会被其它成员函数所调用

public: // for debug
    int get_ref_count() const;
};

template <class T>
SmartPtr<T>::SmartPtr(T *p)
    : mPtr(p),            // mPtr 指向 p 所指向的内存
      mRef(new size_t(1)) // 引用计数初始化为 1
{
    showfunc;
}

template <class T>
SmartPtr<T>::SmartPtr(const SmartPtr &src)
{
    showfunc;
    mPtr = src.mPtr;
    mRef = src.mRef;
    ++*mRef;
}

template <class T>
SmartPtr<T> &SmartPtr<T>::operator=(const SmartPtr<T> &rhs)
{
    showfunc;
    ++*rhs.mRef;
    decRef();
    mPtr = rhs.mPtr;
    mRef = rhs.mRef;
    return *this;
}

template <class T>
T *SmartPtr<T>::operator->() const
{
    showfunc;
    if (mPtr)
    {
        return mPtr;
    }
    throw std::runtime_error("dereference of nullptr pointer");
}

template <class T>
T &SmartPtr<T>::operator*() const
{
    showfunc;
    if (mPtr)
    {
        return *mPtr;
    }
    throw std::runtime_error("dereference of nullptr pointer");
}

template <class T>
SmartPtr<T>::~SmartPtr()
{
    showfunc;
    decRef();
}

template <class T>
void SmartPtr<T>::decRef() //只会被其它成员函数所调用
{
    std::cout << "after call decRef(): *mPtr = " << *mPtr << ", *mRef = " << *mRef - 1 << std::endl;
    if (0 == --*mRef) // 引用计数先自减，为 0 后，释放内存
    {
        delete mPtr;
        delete mRef;
        std::cout << "real delete" << std::endl;
    }
}

template <class T>
int SmartPtr<T>::get_ref_count() const
{
    return *mRef;
}

int main()
{
    SmartPtr<int> p1(new int(999));
    SmartPtr<int> p2(new int(888));
    SmartPtr<int> p3(p1);
    p2 = p3;               // 拷贝赋值运算符
    SmartPtr<int> p4 = p2; // 隐式拷贝构造
}

/*
SmartPtr<T>::SmartPtr(T*) [with T = int]
SmartPtr<T>::SmartPtr(T*) [with T = int]
SmartPtr<T>::SmartPtr(const SmartPtr<T>&) [with T = int]
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T>&) [with T = int]
after call decRef(): *mPtr = 888, *mRef = 0
real delete
SmartPtr<T>::SmartPtr(const SmartPtr<T>&) [with T = int]
SmartPtr<T>::~SmartPtr() [with T = int]
after call decRef(): *mPtr = 999, *mRef = 3
SmartPtr<T>::~SmartPtr() [with T = int]
after call decRef(): *mPtr = 999, *mRef = 2
SmartPtr<T>::~SmartPtr() [with T = int]
after call decRef(): *mPtr = 999, *mRef = 1
SmartPtr<T>::~SmartPtr() [with T = int]
after call decRef(): *mPtr = 999, *mRef = 0
real delete
*/