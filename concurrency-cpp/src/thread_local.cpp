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
    O(int v = 0) : mValue(v)
    {
        printf("call O(), mValue = %d\n", mValue);
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

    auto work = [&](int v) {
        o.mValue = v;
        printf("thread %d: %p\n", o.mValue, &o);
        sleep(1);
    };

    for (int i = 0; i < n; ++i) {
        works[i] = std::move(std::thread{work, i});
    }

    for (int i = 0; i < n; ++i) {
        works[i].join();
    }
}

/**
call O(), mValue = -1
main: 0x7fca46387730
thread 0: 0x7fca463866f0
thread 1: 0x7fca45b856f0
thread 2: 0x7fca453846f0
thread 3: 0x7fca44b836f0
call ~O(), mValue = -1

O 被构造一次，但在每个线程中的地址却是不同的
 */