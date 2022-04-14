#include <tuple>
#include <iostream>

int main()
{
    // pair : C++98. 서로 다른 타입의 객체 2개 보관
    std::pair<int, double> p1(3, 3.4);

    std::pair<int, std::pair<int, double>> p2(3, std::pair<int, double>(1, 3.4));

    std::cout << p2.first << std::endl;         // 3
    std::cout << p2.second.first << std::endl;  // 1
    std::cout << p2.second.second << std::endl; // 3.4

    // tuple since C++11
    std::tuple<> t0;
    std::tuple<int, double> t2(1, 3.4);
    std::tuple<int, double, char, short> t4(1, 3.4, 'A', 3);

    // 요소 접근은 std::get
    std::get<0>(t4) = 30;
    std::cout << std::get<0>(t4) << std::endl; // 30
}