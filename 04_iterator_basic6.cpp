#include <iostream>
#include <list>
#include <algorithm> // std::copy

int main()
{
    int x[5] = {1, 2, 3, 4, 5};
    int y[5] = {0, 0, 0, 0, 0};

    std::list<int> s2 = {0, 0, 0, 0, 0};

    // x의 모든 요소를 y로 복사한다.
    // 1. for 사용
    for (int i = 0; i < 5; i++)
        y[i] = x[i];

    // 2. range-for
    int i = 0;
    for (auto e : x)
        y[i++] = e;

    // 3. copy 알고리즘 사용.
    std::copy(x, x + 5, y);
    std::copy(std::begin(x), std::end(x), y);

    for (auto e : y)
        std::cout << e << ", ";
}