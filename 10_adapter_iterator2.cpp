#include <iostream>
#include <list>
#include <algorithm>

int main()
{
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 3, 9, 10};

    // reverse iterator 생성
    // 1. iterator로 reverse iterator를 만든다.
    auto p1 = s.begin();
    std::reverse_iterator<std::list<int>::iterator> ri1(p1);

    // 2. make_reverse_iterator 함수 사용.
    auto rend = std::make_reverse_iterator(s.begin());
    auto rbegin = std::make_reverse_iterator(s.end());

    // 3. 컨테이너에서 직접 꺼낸다. - 가장 일반적으로 사용 됨.
    auto rp1 = s.rbegin();
    auto rp1 = s.rend();

    std::list<int> s1 = {1, 2, 3, 4, 5, 6, 7, 3, 9, 10};

    std::list<int> s2;

    std::copy(s1.rbegin(), s1.rend(), std::back_inserter(s2));
}
