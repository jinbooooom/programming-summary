#include <stdio.h>
#include <chrono>
#include <future>
#include <coroutine>

using namespace std::chrono_literals;

/**
 * C++20 中，用户应手动启用 std::future<T> 作为协程类型，不然会报错：
 * error: unable to find the promise type for this coroutine
   54 |     auto fut = co_await std::async(foo); // 挂起点
*/
template <>
struct std::coroutine_traits<std::future<int>>
{
    struct promise_type : std::promise<int>
    {
        std::future<int> get_return_object() { return this->get_future(); }
        std::suspend_never initial_suspend() noexcept { return {}; }
        std::suspend_never final_suspend() noexcept { return {}; }
        void return_value(int value) { this->set_value(value); }
        void unhandled_exception()
        {
            this->set_exception(std::current_exception());
        }
    };
};

auto operator co_await(std::future<int> future)
{
    struct awaiter : std::future<int>
    {
        bool await_ready() { return false; } // suspend always
        void await_suspend(std::coroutine_handle<> handle)
        {
            std::thread([this, handle]()
                        {
        this->wait();
        handle.resume(); })
                .detach();
        }
        int await_resume() { return this->get(); }
    };
    return awaiter{std::move(future)};
}

int foo()
{
    printf("call foo()\n"); // 4
    std::this_thread::sleep_for(3s);
    printf("after call foo()\n"); // 6
    return 42;
}

std::future<int> bar()
{
    printf("call bar()\n");  // 2
    printf("before foo()\n"); // 3
    auto fut = co_await std::async(foo); // 挂起点
    printf("after foo()\n"); // 7
    co_return fut;
}

int main()
{
    printf("before bar()\n");  // 1
    auto futfut = bar();
    printf("after bar()\n"); // 5  (这里，打印 4 和 5 的顺序是可以交换的)
    futfut.wait();
    printf("result = %d\n", futfut.get());

    return 0;
}

/***
 * 
jinbo@fang:~/gitme/programming-summary/concurrency-cpp/src$ g++ coroutine.cpp -std=c++2a -pthread
jinbo@fang:~/gitme/programming-summary/concurrency-cpp/src$ ./a.out 
before bar()
call bar()
before foo()
call foo()
after bar()
after call foo()
after foo()
result = 42
*/