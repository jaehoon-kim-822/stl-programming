#include <vector>
#include <algorithm>
#include "show.h"

inline bool cmp1(int a, int b) { return a < b; }

int main()
{
    std::vector<int> v = {1, 3, 4, 5, 6, 2, 4, 5, 2};

    // STL에서 sort를 사용하는 방법.
    // A. 비교 정책을 전달하지 않는 경우.
    std::sort(v.begin(), v.end()); // 기본 정책: 오름 차순

    // B. 비교 정책을 전달하는 경우. - 일반 함수
    std::sort(v.begin(), v.end(), cmp1); // 그러나 일반 함수는 inline 치환되지 않음.

    // C. 비교 정책을 전달하는 경우 - STL 함수 객체
    // std::less<int> f;
    // std::sort(v.begin(), v.end(), f);
    std::sort(v.begin(), v.end(), std::less<int>()); // 임시 객체 표기법으로 전달.

    // D. C++11 부터는 람다 표현식
    std::sort(v.begin(), v.end(), [](int a, int b)
              { return a < b; });
}
