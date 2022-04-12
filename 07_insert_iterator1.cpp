#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> s = {1, 2, 3};
    std::vector<int> v = {1, 2, 3};

    // 삽입 반복자 -> 컨테이너에 요소를 추가할 때 사용하는 반복자.

    // 1. 삽입 반복자에 클래스 이름 직접 사용.
    std::back_insert_iterator<std::list<int>> p1(s);
    std::back_insert_iterator<std::vector<int>> p2(v);

    // 2. 삽입 반복자 객체를 만드는 "도움 함수". Object generator와 같은 접근.
    auto p3 = std::back_inserter(s);
    auto p4 = std::back_inserter(v);

    p3 = 100; // s.push_back(100);

    // 3. c++ 17 부터는 아래처럼 단순하게 사용해도 됨.
    std::back_insert_iterator p5(s);
    std::back_insert_iterator p6(v);
}
