#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// 알고리즘 기본
// 1. STL에서 알고리즘은 멤버함수가 아닌 일반 함수 템플릿을 의미한다.
// 2. 헤더: algorithm, numeric, memory
// 3. Parameter UI: (first iterator, last iterator, additional...)
int main()
{
    std::vector<int> v = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1};

    auto p = std::find(v.begin(), v.end(), 3);
    // auto p = std::find(v, 3);
    // (container, additional...) 로 사용하는 것(전체 범위 일 때 반복자 대신 컨테이너)은
    // c++98 때 기술적인 이유로 지원 불가하였으나, c++20부터 지원 가능

    return 0;
}
