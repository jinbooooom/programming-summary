#include "unistd.h"
#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

class O
{
public:
    O()
    {
        mValue = -2;
        printf("call O(), mValue = %d\n", mValue);
    }

    O(int v) : mValue(v)
    {
        printf("call O(int), mValue = %d\n", mValue);
    };
    ~O()
    {
        printf("call ~O(), mValue = %d\n", mValue);
    };

    int mValue;
};

int main()
{
    const int n = 4;
    std::vector<std::thread> works(n);
    thread_local O o(-1);
    printf("main: %p\n", &o);

    auto work = [&](int idx) {
        // thread_local O o(idx); // 【1】
        printf("thread %d: &o = %p, o.mValue = %d\n", idx, &o, o.mValue);
        sleep(1);
    };

    for (int i = 0; i < n; ++i) {
        works[i] = std::move(std::thread{work, i});
    }

    for (int i = 0; i < n; ++i) {
        works[i].join();
    }

    printf("exit\n");
}

/**
call O(int), mValue = -1
main: 0x7ff0648ce730
thread 0: &o = 0x7ff0648cd6f0, o.mValue = 0
thread 1: &o = 0x7ff0640cc6f0, o.mValue = 0
thread 2: &o = 0x7ff0638cb6f0, o.mValue = 0
thread 3: &o = 0x7ff0630ca6f0, o.mValue = 0
exit
call ~O(), mValue = -1

O 被构造一次，但在每个线程中的地址却是不同的，除了在 main 中的构造，在子线程中不会构造，只是分配独立的储存空间。
放开注释【1】，在子线程中也构造了对象，且在线程结束时释放而不是 main 结束时。

call O(int), mValue = -1
main: 0x7f39eb7b8760
call O(int), mValue = 0
call O(int), mValue = 1
thread 0: &o = 0x7f39eb7b76f0, o.mValue = 0
thread 1: &o = 0x7f39eafb66f0, o.mValue = 1
call O(int), mValue = 2
thread 2: &o = 0x7f39ea7b56f0, o.mValue = 2
call O(int), mValue = 3
thread 3: &o = 0x7f39e9fb46f0, o.mValue = 3
call ~O(), mValue = 0
call ~O(), mValue = 1
call ~O(), mValue = 2
call ~O(), mValue = 3
exit
call ~O(), mValue = -1
 */