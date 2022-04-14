#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> v2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // inplace와 value
    auto p1 = std::remove(v1.begin(), v1.end(), 3);

    // inplace와 predictor
    auto p1 = std::remove_if(v1.begin(), v1.end(), [](int n)
                             { return n % 2 == 0; });
    // copy와 value
    auto p1 = std::remove_copy(v1.begin(), v1.end(),
                               v2.begin(), 3); // remove 결과를 v2로 copy,
    auto p1 = std::remove_copy(v1.begin(), v1.end(),
                               std::back_inserter(v2), 3); // remove 결과를 v2로 insert
    // remove와 copy는 동시에 처리하면 2배의 성능 향상.
    // sort_copy는 없다. sort와 copy의 수행시간 차이 크기 때문.

    // copy와 predictor
    auto p1 = std::remove_copy_if(v1.begin(), v1.end(),
                               v2.begin(),
                               [](int n)
                               { return n % 2 == 0; });
    show(v1);
    show(v2);
}
