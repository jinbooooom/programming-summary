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