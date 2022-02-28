#include <iostream>
#include <string.h>
#include <string>

// #define mylog printf("%d:%s\n", __LINE__, __PRETTY_FUNCTION__);
#define mylog std::cout << __LINE__ << ":" << __PRETTY_FUNCTION__ << std::endl;

class MyString
{
private:
    char *mStr;

    // 如果手动提供了析构函数,复制构造函数,复制赋值运算符,编译器不自动提供移动构造函数和移动赋值运算符;
    // 如果手动提供了移动构造函数或移动赋值运算符,编译器奖不会自动提供复制构造函数和复制赋值运算符
public:
    MyString();                             // 默认构造函数
    MyString(const char *s);                // 自定义构造函数
    MyString(const MyString &s);            // 拷贝构造函数
    MyString(MyString &&s);                 // 移动构造函数
    MyString &operator=(const MyString &s); // 拷贝赋值运算符
    MyString &operator=(MyString &&s);      // 移动赋值运算符
    ~MyString();                            // 析构函数

public:
    void myprint() const;
};

MyString::MyString() : mStr(nullptr)
{
    mylog;
    mStr = new char('\n');
}

MyString::MyString(const MyString &s)
{
    mylog;
    mStr = (char *)malloc(sizeof(char) * (strlen(s.mStr) + 1));
    strcpy(mStr, s.mStr);
}

MyString::MyString(MyString &&s)
{
    mylog;
    mStr = s.mStr;
    s.mStr = nullptr;
}

MyString &MyString::operator=(const MyString &s)
{
    mylog;
    if (this == &s) // 拷贝赋值运算符用来更新对象，如果是给自己赋值，就应该直接返回*this，不做其它事情了
    {
        return *this;
    }
    if (mStr)
    {
        free(mStr);
        mStr = nullptr;
    }
    mStr = (char *)malloc(sizeof(char) * (strlen(s.mStr) + 1));
    strcpy(mStr, s.mStr);
    return *this;
}

MyString &MyString::operator=(MyString &&s)
{
    mylog;
    if (this == &s)
    {
        return *this;
    }
    if (mStr)
    {
        free(mStr);
        mStr = nullptr;
    }
    mStr = s.mStr;
    s.mStr = nullptr;
    return *this;
}

MyString::MyString(const char *s)
{
    mylog;
    mStr = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(mStr, s);
}

void MyString::myprint() const
{
    if (!mStr)
    {
        std::cout << "is empty" << std::endl;
        return;
    }

    std::cout << mStr << std::endl;
}

MyString::~MyString()
{
    mylog;
    if (mStr)
    {
        free(mStr);
    }
}

int main()
{
    MyString s1 = "this is s1"; // 隐式调用构造函数
    MyString s2(s1);            // 拷贝构造
    s2 = std::move(s1);         // 强制调用移动赋值运算符函数，std::move强制转化为右值，可以理解为同一片堆内容分给了新的对象，旧的对象的指针指向 nullptr
    s1.myprint();               // 被移动，现在为空
    s2.myprint();

    std::cout << "--------" << std::endl;

    MyString s3(std::move(s2)); // 移动构造
    s2.myprint();
    s3.myprint();

    std::cout << "--------" << std::endl;

    s2 = s3; // 拷贝赋值
    s2.myprint();
    s3.myprint();

    return 0;
}