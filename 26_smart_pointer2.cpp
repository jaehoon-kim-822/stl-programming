#include <iostream>
// C++11의 스마트포인터를 사용하려면 필요한 헤더
#include <memory>

class Car
{
public:
    void Go() { std::cout << "Go" << std::endl; }
};

int main()
{
    // 핵심 1.
    std::shared_ptr<int> p1(new int);
    std::shared_ptr<int> p2 = new int; // 이건 안됨.

    // 핵심 2. 스마트 포인터의 크기
    std::cout << sizeof(p1) << std::endl;    // 64bit arch에서는 16B(primitive pointer의 두 배). reference count pointer 까지.
    std::cout << sizeof(int *) << std::endl; // 64bit arch에서는 8B

    // 핵심 3. -> 와 . 연산자
    std::shared_ptr<Car> sp1(new Car);
    std::shared_ptr<Car> sp2 = sp1;

    sp2->Go();       // Car의 함수
    sp2.use_count(); // shared_ptr의 함수. 참조계수

    Car *p = sp2.get(); // 스마트포인터가 가리키는 대상에 대한 포인터

    // 모두 같은 수행방식. reference count도 줄어든다. use_count()로 확인 가능.
    sp2.reset();
    sp2 = 0;
    sp2 = nullptr;
}
