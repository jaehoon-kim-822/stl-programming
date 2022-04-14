#include <iostream>
#include "show.h"
#include <set>

int main()
{
    std::set<int> s;                     // 내림차순
    std::set<int, std::greater<int>> s2; // 오름차순

    s.insert(20);
    s.insert(30);
    s.insert(15);
    s.insert(5);
    s.insert(40);

    auto p = s.begin();
    while (p != s.end())
    {
        std::cout << *p << std::endl;
        ++p;
    }

    std::pair<std::set<int>::iterator, bool> ret = s.insert(15); // Fail, 중복요소를 허용하지 않음.

    // 요소는 삽입(insert, emplace)로만 추가 가능. push_front, push_back은 불가. -> 입력 순서에 따른 앞, 뒤가 있는 구조(정렬된 형태)는 아님.
    s.push_front(37); // ERROR;

    // 반복자는 읽기 가능. 삽입하면서 정렬하는 구조이기 때문에 특정 요소를 변경할 순 없음.
    auto p1 = s.begin();
    *p1 = 100; // ERROR

    // 자료구조의 특성에 맞는 함수 사용 필요.
    // tree 구조에 선형 검색은 효율이 좋지 않음.
    auto ret1 = std::find(s.begin(), s.end(), 15);
    // tree 구조에는 이진 탐색이 좋은 효율. 멤버함수로 제공.
    auto ret2 = s.find(15);
}
