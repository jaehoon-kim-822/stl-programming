#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

bool foo(int n) { return n % 3 == 0; }

// 조건자(Predicates): bool을 반환하는 함수/함수객체
int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto ret1 = std::find(v1.begin(), v1.end(), 3); // 3을 찾아라.
    auto ret1 = std::find_if(v1.begin(), v1.end(), foo); // 일반 함수
    auto ret1 = std::find_if(v1.begin(), v1.end(), // 함수 객체
                             [](int n)
                             { return n % 3 == 0; });
    
}
