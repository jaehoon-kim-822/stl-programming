#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

int main()
{
    // C++ 표준에 modulus 라는 함수 객체가 이미 존재합니다.
    // <functional>
    std::modulus<int> m;
    std::cout << m(10, 3) << std::endl;
    // 3의 배수가 아닌 것을 찾고 싶다.!
    int x[5] = {9, 9, 2, 4, 3};
    // auto p = std::find_if(x, x + 5, m); // ERROR. find_if의 세 번째 인자는 단항함수를 요구한다.
    auto p = std::find_if(x, x + 5, std::bind(m, _1, 3)); // 이항함수를 단항함수로 변경.
    // 요즘엔 람다표현식을 사용한다.
    auto p = std::find_if(x, x + 5, [m](int a)
                          { return m(a, 3); });
}