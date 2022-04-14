#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include "show.h"

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> v2;

    std::partial_sum(v1.begin(), v1.end(), std::back_inserter(v2));
    std::partial_sum(v1.begin(), v1.end(), std::back_inserter(v2), std::multiplies<int>());
    std::adjacent_difference(v1.begin(), v1.end(), std::back_inserter(v2)); // 근접 두 요소의 변화량, 기본 연산은 차.
    std::adjacent_difference(v1.begin(), v1.end(), std::back_inserter(v2), std::plus<int>()); // 근접 두 요소의 합
}
