#include <iostream>

template <typename T>
T square(T a)
{
    return a * a;
}

template<typename T, typename U>
std::pair<T, U> make_pair(const T& a, const U& b)
{
    return std::pair<T, U>(a, b);
};

int main()
{
    // 두 번째 표현이 더 쉬워 보임.
    square<int>(3); // Default
    square(3); // Since C++14

    std::pair<int, double> p1(3, 3.4);
    // std::pair p1(3, 3.4); 불가

    auto p2 = make_pair(3, 3.4);
    auto p3 = std::make_pair(3, 3.4);
}
