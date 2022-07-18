#include <thread>
#include <iostream>
#include <chrono>

void do_something(int &i)
{
    ++i;
}

struct func
{
    int &i;

    func(int &i_) : i(i_) {}

    void operator()()
    {
        for (unsigned j = 0; j < 1000000; ++j)
        {
            std::cout << j << " ";
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            do_something(i);
        }
    }
};

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    // 不等待线程结束，oops 执行完，就释放了局部变量 some_local_state， my_func.i 为空悬引用
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    my_thread.detach(); 
}

int main()
{
    oops(); // main 函数退出了，它所拥有的线程当然也会退出。
}
