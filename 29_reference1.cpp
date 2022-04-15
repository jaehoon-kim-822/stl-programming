#include <iostream>
#include <functional>

// std::reference_wrapper 만들기.

template <typename T>
struct reference_wrapper
{
    T &ptr;

public:
    reference_wrapper(T &obj) : ptr(&obj) {}
    operator=(const reference_wrapper<int> &) {}
    operator T &() { return *ptr; }
};

int main()
{
    int n1 = 10;
    int n2 = 20;

    int &r1 = n1;
    int &r2 = n2;
    r1 = r2;

    std::cout << n1 << std::endl; // 20. r2가 참조하는 n2의 값으로, r1가 참조하는 n1를 변경.
    std::cout << n2 << std::endl; // 20. r2가 참조하는 n2의 값.
    std::cout << r1 << std::endl; // 20. r1가 참조하는 n1의 값.
    std::cout << r2 << std::endl; // 20.

    std::reference_wrapper<int> r3(n1);
    std::reference_wrapper<int> r4(n2);
    r3 = r4;

    std::cout << n1 << std::endl; // 10. r3이 r3의 참조 대상인 n2를 참조하게 됨.
    std::cout << n2 << std::endl; // 20.
    std::cout << r3 << std::endl; // 20.
    std::cout << r4 << std::endl; // 20.

    reference_wrapper<int> r5(n1);
    reference_wrapper<int> r6(n2);
    r5 = r6; // 동일 타입이므로 대입 연산자. 컴파일러 자동 생성.

    std::cout << n1 << std::endl; // 10. r5이 r6의 참조 대상인 n2를 참조하게 됨.
    std::cout << n2 << std::endl; // 20.
    std::cout << r5 << std::endl; // 20.
    std::cout << r6 << std::endl; // 20.

    int &r7 = n1;
    reference_wrapper<int> r8(n2);
    r7 = r8;

    std::cout << n1 << std::endl; // 10. r5이 r6의 참조 대상인 n2를 참조하게 됨.
    std::cout << n2 << std::endl; // 20.
    std::cout << r7 << std::endl; // 20.
    std::cout << r8 << std::endl; // 20.
}
