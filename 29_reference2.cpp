#include <iostream>
#include <thread>
#include <functional>
using namespace std::placeholders;

void foo(int a, int &b) { b = 100; }
void f1(int a) { a = 200; }
void f2(int &a) { a = 200; }

// bind 만들기
template <typename F, typename T>
void bind_call(F f, T arg)
{
    f(arg);
}

int main()
{
    int n = 10;
    f2(n);
    std::cout << n << std::endl; // 200

    n = 10;
    bind_call(f2, n);
    std::cout << n << std::endl; // 10

    n = 10;
    bind_call(f2, &n); // bind_call(F f, int *arg). int *는 f(arg)에서 int &로 변환할 수 없어서 에러.
    std::cout << n << std::endl;

    n = 10;
    std::reference_wrapper<int> r(n); // r은 n의 주소 보관. 참조로 변환 가능. (2_ref2.cpp)
    bind_call(f2, r);
    std::cout << n << std::endl; // 200

    n = 10;
    bind_call(f2, std::ref(n));  // std::ref는 std::reference_wrapper의 object generator.
    std::cout << n << std::endl; // 200

    std::function<void(int)> f;

    int n = 0;

    f = std::bind(&foo, _1, n);
    f(0);
    std::cout << n << std::endl; // 0

    f = std::bind(&foo, _1, std::ref(n));
    f(0);
    std::cout << n << std::endl; // 100

    int v = 10;

    std::thread t1(f1, v);
    t1.join();

    std::thread t2(f2, v); // 컴파일 에러. 원본을 손상시킬 수 있기 때문에.
    t2.join();

    std::thread t2(f2, std::ref(v)); // 원본을 변경하길 원하는 경우 이런 방식으로 보내야 함.
    t2.join();
}
