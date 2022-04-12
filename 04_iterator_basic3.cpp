#include <iostream>
#include <list>
#include <vector>
#include <ranges>

int main()
{
    std::list<int> s = { 1,2,3,4,5 };
    std::vector<int> v = { 1,2,3,4,5 };
    int a[5] = {1, 2, 3, 4, 5};

    // 반복자를 꺼내는 법
    // 1. c++11 이전 스타일 -> container 변경 시, 변경이 전파 됨.
    std::list<int>::iterator p1 = s.begin();
    std::vector<int>::iterator p2 = v.begin();

    // 2. c++11 이후, auto
    auto p1 = s.begin();
    auto p2 = v.begin();

    // 3. c++11 이후, 유연성을 위해서 아래와 같은 스타일을 지향.
    // STL 이외에도 pritimive pointer type도 지원.
    auto p1 = std::begin(s);
    auto p2 = std::begin(v);
    auto p3 = std::begin(a);
}
