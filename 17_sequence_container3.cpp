#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

// capacity 개념
int main()
{
    std::vector<int> v(10, 0);

    v.resize(7); // 어떻게 구현했을까요 ? 기존 메모리를 그대로 두고 요소의 수를 7로 줄인다.
    // 이 때 capacity는 10이다. 이 것은 추후 push_back 과 같은 삽입 때 추가 할당을 지연시키는 효과가 있다.

    std::cout << v.size() << std::endl;     // 7
    std::cout << v.capacity() << std::endl; // 10

    v.push_back(10); // 성능 저하 없는, not expensice operation

    std::cout << v.size() << std::endl;     // 8
    std::cout << v.capacity() << std::endl; // 10

    v.shrink_to_fit(); // size == capacity

    std::cout << v.size() << std::endl;     // 8
    std::cout << v.capacity() << std::endl; // 8

    v.push_back(10); // expensice operation, allocate new memory

    std::cout << v.size() << std::endl;     // 9
    std::cout << v.capacity() << std::endl; // g++: 16(두배 확장), vs: 12(1.5배 확장)

    // 메모리 여유가 있다면, 처음부터 크게 할당하는 것도 좋은 방법.
    // 그러나 방식을 주의하자.
    std::vector<int> v1(100); // 100개 요소에 대한 메모리 할당과 생성자까지 수행 됨.
    v1.resize(0);             // 100개 요소에 대한 소멸자가 수행 됨.

    std::vector<int> v2;
    v2.reserve(100); // 100개 요소에 대한 메모리만 할당해 놓음. 실제 요소가 추가 될 때 생성자가 수행 됨.

    std::vector<int> v1(100); // 이런 경우는 몇 개 입력 되었는지 파악하기 어렵다.
    v1.resize(0); // 이런 경우 capacity를 유지하고, size를 초기화 해줄 목적으로 resize(0)을 하나, 효율적이진 않다.
    
    std::vector<int> v2;
    v2.reserve(100); // 단순히 capacity만 확보한다. size는 그대로다.

    // 11개 항목
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 3, 4, 2, 2, 3};

    // 3을 제거(3개)
    auto p = std::remove(v.begin(), v.end(), 3);
    std::cout << v.size() << std::endl;     // 11, 변화 없음.
    std::cout << v.capacity() << std::endl; // 11, 변화 없음.

    v.erase(p, v.end());
    std::cout << v.size() << std::endl;     // 8
    std::cout << v.capacity() << std::endl; // 11

    v.shrink_to_fit();                      // 또는 v.resize(v.size());
    std::cout << v.size() << std::endl;     // 8
    std::cout << v.capacity() << std::endl; // 8
}
