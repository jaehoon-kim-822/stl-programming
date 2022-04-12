#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

// 입력 과 출력

// 출력: *p=, ++
// 입력: =*p, ++
// --------------------- 이하 multiple passes 지원.
// 전진형: =*p, ++
// 양방향: =*p, ++, --
// 임의접근: =*p,++, --, +, -, [] 연속된 메모리와 유사(deque 같은 것들은 완전 연속 메모리는 아니지만, +/- 연산 지원).

// linked list가 + 연산을 지원하지 않는 이유는 p + 3과 **p 세번이 실제로 동일 연산이기 때문이다.
int main()
{
    std::forward_list<int> s1 = {1, 2, 3};
    std::list<int> s2 = {1, 2, 3};
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // find는 1, 2 번째 인자가 반복자.
    // => 최소 요구조건을 5가지 카테고리에서 골라보자: 입력 반복자
    auto p = std::find(std::begin(v), std::end(v), 5);

    // 최소 요구조건: 양방향 반복자.
    std::reverse(std::begin(v), std::end(v));

    // 최소 요구조건: 임의접근 반복자
    std::sort(std::begin(v), std::end(v));

    // std:reverse(std::begin(s1), std::end(s1)); // ERROR: reverse는 양방향 반복자를 요구하는데, s1(forward list)의 iterator는 입력 반복자.
    // std::sort(std::begin(s2), std::end(s2)); // ERROR. sotr(quick)은 양방향 반복자를 요구. double list는 "-"연산을 만족할 수 없음.

    // 결론: STL 의 모든 알고리즘은 "자신이 요구하는 반복자의 종류"가 정해져 있음. 반드시 요구조건에 만족하는 반복자를 보내야 함.
    // std::sort에 std::list 반복자를 보내면 안됨.
    // 단, quick 말고 다른 알고리즘을 사용하거나, list의 멤버함수(sort) 사용. 해당 함수는 quick이 아닌 알고리즘으로 구성되어 있음.

    // v.sort() 는 없다. vector는 멤버함수로 sort로 제공하지 않는다. std::sort를 사용하면 된다. 호환성이 좋다보니, 멤버함수가 별로 없는 컨테이너.
}