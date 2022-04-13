#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

// 알고리즘은 컨테이너를 알지 못한다.
int main()
{
    std::vector<int> v = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1};

    auto p = std::remove(v.begin(), v.end(), 3);

    show(v); // 1, 2, 1, 2, 1, 2, 1, 2, 3, 1
    // remove는 메모리를 반환하는 것이 아니라, 뒷 부분으로 타겟을 덮는다.
    // remove는 유효한 다음 영역을 가리키는 반복자를 반환한다.
    // 해당 반복자를, 해당 컨테이너의 erase를 사용해서 메모리를 반환할 수 있다.
    // 알고리즘은 컨테이너를 알지 못하기(컨테이너의 구성 방식) 때문에 메모리를 지우거나 할 수는 없다.
    // 이 경우 각 컨테이너의 멤버함수를 사용해야 한다.
    v.erase(p, v.end());

    // erase-remove technique.
    v.erase(std::remove(v.begin(), v.end(), 3), v.end());
    return 0;
}
