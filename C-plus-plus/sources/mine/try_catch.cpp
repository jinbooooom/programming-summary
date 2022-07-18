// 参考 http://c.biancheng.net/cpp/biancheng/view/3026.html

#include <iostream>
#include <string>
#include <exception>
using namespace std;

void func()
{
    throw "Unknown Exception"; //抛出异常
    cout << "[1]This statement will not be executed." << endl;
}

int main()
{
    try
    {
        func();
        cout << "[2]This statement will not be executed." << endl;
    }
    catch (const char *&e)
    {
        cout << e << endl;
        // throw; // 如果放开该处注释，【3】处也不会打印。如果注释掉该语句，catch 执行完后，会执行 catch 外的内容，则【3】处可以打印。
    }

    cout << "executed." << endl; // 【3】
    return 0;
}
