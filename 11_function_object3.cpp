#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less
{
    inline bool operator()(int a, int b) { return a < b; }
};
struct Greater
{
    inline bool operator()(int a, int b) { return a > b; }
};

int main()
{
    int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

    // C++ 표준 sort는 템플릿

    // 1. 비교 정책으로 일반 함수 사용.
    // 장점: 비교 정책의 수와 관련 없이 sort 함수는 한 개만 생성.
    // 단점: 비교 정책의 함수를 호출하는 추가 연산.
    std::sort(x, x + 10, cmp1);
    std::sort(x, x + 10, cmp2);

    // 2. 비교 정책으로 함수 객체 사용.
    // 장점: 비교 정책의 함수를 inline으로 치환 할 수 있음.
    // 단점: 비교 정책의 수 만큼 sort 함수가 생성 됨.
    Less f1;
    Greater f2;
    std::sort(x, x + 10, f1);
    std::sort(x, x + 10, f2);
}
