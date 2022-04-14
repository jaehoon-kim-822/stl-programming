#include <iostream>
#include <algorithm>
#include "show.h"

class ClosureType
{
public:
    inline auto operator()(int a, int b) const
    {
        return a < b;
    }
};

class ClosureType2
{
public:
    inline auto operator()(int a, int b) const
    {
        return a < b;
    }
};

int main()
{
    // 모든 람다 표현식은 서로 다른 타입.
    auto f = [](int a, int b)
    { return a + b; };
    auto g = [](int a, int b)
    { return a + b; };

    // 클래스이름은 컴파일러가 임의로 결정.
    std::cout << typeid(f).name() << std::endl;
    std::cout << typeid(g).name() << std::endl;

    auto h = ClosureType(); // ClosureType의 지역 변수로 봐야 함. 임시 객체가 생성(new) 된다고 생각하면 안됨.
    bool b1 = (f == g);     // ERROR. 서로 다른 타입이라 비교 할 수 없음.
    bool b2 = (&f == &g);   // ERROR. 다른 타입에 다른 객체.
}
