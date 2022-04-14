#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
    // 배열과 vector
    // 배열: 크게 변경 못함.
    // vector: 크기 변경 가능(동적 배열)
    std::vector<int> v(5);
    v.resize(10); // 크기 변경

    // 1. 생성
    std::vector<int> v1;        // 0
    std::vector<int> v2(10);    // 크기 10, 모든 요소를 0으로 초기화
    std::vector<int> v3(10, 3); // 크기 10, 모든 요소를 3으로 초기화
    std::vector<int> v4(v3);    // v3과 동일한 vector
    std::vector<int> v5{10, 3}; // v5 = {10, 3}, 첫 번째 요소는 10, 두 번째 요소는 3
    std::vector<int> v6 = {1, 2, 3};

    // 2. 삽입 - 세 가지: 앞, 뒤, 임의
    v.push_back(10);
    // v.push_front(10); // vector는 제한 됨.
    auto p = v.begin();
    ++p;
    v.insert(p, 20);

    // 3 제거 - pop_front(), pop_back(), erase() - 임의

    // 4. 접근
    int n1 = v[0];    // list는 제한 됨.
    int n2 = v.at(0); // list는 제한 됨.
    int n3 = v.front();
    int n4 = v.back();

    // 5. 요소 변경
    std::vector<int> v8 = {1, 2, 3, 4};
    std::vector<int> v9 = {1, 2, 3, 4, 5, 6};
    v8.assign(v9.begin(), v9.end());
    v8.clear(); // 모든 요소 제거.

    // 6. 기타
    bool b = v.empty(); // begin == end
    int n5 = v.size();
}