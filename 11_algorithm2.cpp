#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

// 알고리즘은 컨테이너를 알지 못한다.
// 알고리즘과 동일한 이름의 멤버 함수가 있다면 멤버 함수를 사용하라.
// 1. 멤버 함수를 먼저 확인.
// 2. 멤버 함수가 없다면, 일반 함수 알고리즘.
// 3. 알고리즘이 없거나, 알고리즘에서 해당 컨테이너 반복자를 수행하지 못한다면, 컨테이너의 특징을 살펴보자. (아마도 해당 알고리즘이 이론적으로 수행불가 할 것임.)
int main()
{
    std::vector<int> v = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1};

    auto p1 = std::remove(v.begin(), v.end(), 3);

    show(v); // 1, 2, 1, 2, 1, 2, 1, 2, 3, 1
    // remove는 메모리를 반환하는 것이 아니라, 뒷 부분으로 타겟을 덮는다.
    // remove는 유효한 다음 영역을 가리키는 반복자를 반환한다.
    // 해당 반복자를, 해당 컨테이너의 erase를 사용해서 메모리를 반환할 수 있다.
    // 알고리즘은 컨테이너를 알지 못하기(컨테이너의 구성 방식) 때문에 메모리를 지우거나 할 수는 없다.
    // 이 경우 각 컨테이너의 멤버함수를 사용해야 한다.
    v.erase(p1, v.end());

    // erase-remove technique.
    v.erase(std::remove(v.begin(), v.end(), 3), v.end());

    std::list<int> s = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1};

    // 이런 식의 형태는 좋은 구조라고 보기는 어렵다.
    auto p2 = std::remove(s.begin(), s.end(), 3);
    show(s);
    s.erase(p2, s.end());
    show(s);

    // linked list는 아래와 같은 방식의 효율이 좋지 않기 때문에, remove()를 멤버함수로 제공하고 있다.
    // STL을 잘 사용하려면, 각 자료구조와 알고리즘에 대해서 잘 이해하는게 좋다.
    // 특정 컨테이너에 특정 알고리즘에 해당하는 멤버함수가 있다면, 해당 함수를 사용하는 것이 좋다. 컨테이너 특성을 고려한 것이기 때문이다.
    s.remove(3);
    show(v);

    return 0;
}
