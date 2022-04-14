#include <iostream>
#include <functional>
using namespace std::placeholders;

class Machine
{
public:
    void mf1(int a) {}
    void mf2(int a, int b) {}
};

void f1(int a) { printf("f1 : %d\n", a); }
void f2(int a, int b) { printf("f2 : %d, %d\n", a, b); }
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d); }

int main()
{
    void (*fp)(int) = &f1;
    fp(10); // f1(10)
    
    // 함수는 동일 signature로만 사용할 수 있는 한계가 있다.
    fp = &f1; // ERROR
    fp = &Machine::mf1; // ERROR, static function이거나 객체가 있어야 함.

    // STL에는 함수 포인터 보다 편리한 std::function<>이 있다.
    // 사용법: std::function<함수모양>
    std::function<void(int)> f;
    // 장점1: 인자의 수가 달라도 std::bind를 사용해서 확장할 수 있다.
    // 장점2: 클래스 멤버 함수도 사용할 수 있다.
    // 장점3: 람다 표현식도 사용할 수 있다.
    f = &f1;
    f(10); // f1(10)

    f = std::bind(&f2, 7, _1);
    f(10); // f2(7, 10)

    // f = Machine::mf1; // ERROR, 객체가 없음.
    Machine m;
    f = std::bind(&Machine::mf1, &m, _1); // Call by pointer
    f(10);                                // m.mf1(10)

    f = std::bind(&Machine::mf1, m, _1); // Call by reference
    f(10);                               // m.mf1(10)

    f = std::bind(&Machine::mf1, Machine(), _1); // Call by reference, temperary object
    f(10);                                       // m.mf1(10)

    f = std::bind(&Machine::mf2, &m, _1, 9);
    f(10); // m.mf2(10, 9)

    f = [](int a) {};
    f(3);
}
