#include <iostream>

// 스마트 포인터
// 개념: 임의 객체가 다른 타입의 포인터 역할을 하는 것
// 원리:
// 장점: primitive pointer가 아닌 객체이기 때문에 생성/복사/대입/소멸 등의 순간에 대한 응용을 할 수 있다.
//  대표적으로 소멸자에서 할당된 객체를 함께 정리할 수 있다.
class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
    ~Car() { std::cout << "~Car" << std::endl; }
};

class Ptr
{
    Car *obj;

public:
    Ptr(Car *p = 0) : obj(p) {}
    ~Ptr() { delete obj; }

    Car *operator->() { return obj; }
    Car &operator*() { return *obj; }
};

int main()
{
    // Ptr의 멤버변수로 Car의 포인터가 있긴 하나, 객체 자체를 Car의 포인터처럼 사용: 스마트 포인터
    Ptr p = new Car; // Ptr p(new Car);

    p->Go(); // p.operator->()Go() => (p.operator->())->Go()

    std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(Car *) << std::endl;

    // Ptr p가 local object이기 때문에 함수 종료시 소멸된다. 이 때, 할당된 객체 Car의 소멸자만 호출해주면, 안전하게 메모리 사용을 할 수 있다.

    (*p).Go();
}
