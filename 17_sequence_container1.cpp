// 선형 컨테이너 다섯가지의 메모리 구조와 반복자의 종류를 알아두자.
// C++98 에서 3개
#include <vector> // 연속된 메모리, 임의접근 반복자, 메모리:000000000
#include <deque>  // 연속된 메모리와 유사, 임의접근 반복자, 메모리: 000-0000-00-000
#include <list>   // 떨어진 메모리, 양방향 반복자, 메모리: 0-0-0-0-0-0-0

// C++11 추가된 2개
#include <forward_list> // 전진형 반복자, 싱글 리스트, 메모리: 0-0-0-0-0-0-0
#include <array>        // 임의접근 반복자, 메모리:000000000

#include "show.h"

int main()
{
    std::vector<int> c = {1, 2, 3};
    // std::list<int> c = {1, 2, 3};

    // 선형 컨테이너는 비슷한 사용법을 갖고 있다.
    c.push_back(5);
    c.pop_back();

    // 컨테이너의 메모리 구조에 따른 사용법 차이도 있다.
    // vector는 연속된 메모리 구조이기 때문에 아래와 같은 동작은 매우 비효율적이다.
    c.push_front(5); // vector 라면 error.
    c.pop_front(); // vector 라면 error.

    // list는 [] 연산에 대한 차이.
    c[10] = 10; // vector, deque만 가능.

    // 모든 순회 요소는 range-for 또는 반복자 가능.
    for (auto e : c)
    {

    }

    auto p1 = c.begin(); // std::begin(c)
    while (p1 != c.end())
    {
        ++p1;
    }

    // 전방 삽입은 필요없고, []가 필요, 삽입 삭제는 적다.: vector
    // 전방 삽입이 필요하고. []가 필요, 삽입 삭제는 적다.: deque
    // []는 필요 없고, 삽입삭제가 많다.: list
}
