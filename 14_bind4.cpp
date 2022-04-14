#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

// callback 방법
void f1() { std::cout << "f1" << std::endl; }

struct FOO
{
    void operator()()
    {
        std::cout << "FOO operator()" << std::endl;
    }
};

// void callback_ntimes(int n, void (*f)())
void callback_ntimes(int n, std::function<void()> f)
{
    for (int i = 0; i < n; i++)
        f();
}

int main()
{
    FOO f2;
    callback_ntimes(3, f1);
    callback_ntimes(3, f2);
    callback_ntimes(3, FOO());
    callback_ntimes(3, []()
                    { std::cout << "ramda" << std::endl; });
}