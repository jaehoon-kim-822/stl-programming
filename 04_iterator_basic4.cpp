#include <iostream>
#include <list>
#include <vector>

// Iterator invalidate, 반복자 무효화
int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    auto p = std::begin(v);

    std::cout << *p << std::endl;

    v.resize(10); // vector는 연속된 data set으로 구성되므로, resize를 할 경우 새로운 공간(memory)를 할당받게 됨.

    // resize 전 iterator 이므로, 이 시점에는 해당 주소가 반환되어 있다.
    std::cout << *p << std::endl;

    // 이런 것을 반복자의 무효화(iterator invalidate) 라고 한다.
}
