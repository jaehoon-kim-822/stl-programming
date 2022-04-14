#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include "show.h"

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::sort(v1.begin(), v1.end());

    int n = std::accumulate(v1.begin(), v1.end(), 0, [](int a, int b)
                            { return a * b; }); // 초기값이 0이어서.. 결과도 0
    int n = std::accumulate(v1.begin(), v1.end(), 1, [](int a, int b)
                            { return a * b; });

    // C++11 이전에는 람다 표현식을 사용했지만,
    // C++11 이후에는 <functional> 안에 있는 std::plus<>, std::multiples<> 등 함수 객체를 사용.
}
