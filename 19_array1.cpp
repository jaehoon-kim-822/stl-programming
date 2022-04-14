#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"
#include <array> // Since C++11

template <typename T, std::size_t N>
class array
{
    T buf[N];

public:
    inline int size() const { return N; }
    inline bool empty() const { return N != 0; }

    using value_type = T;
    using iterator = T *;
    using reference = T &;

    iterator begin() { return buf; }
    iterator end() { return buf + N; }
};

int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};                // 모든 요소가 stack
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};       // 모든 요소가 heap
    array<int, 10> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};      // 모든 요소가 stack,
    std::array<int, 10> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 모든 요소가 stack. STL interface

    auto p = arr2.begin();

    for (auto e : arr2)
    {
        std::cout << e << std::endl;
    }

    arr2.push_back(1); // error. 크기가 변하지 않기 때문에 없음.
    arr2.resize(9);    // error. 못바꿈.

    // primitive type array와 동일 함.
    // STL interface로 응용 할 수 있음.
    // 메모리가 stack에 할당할 됨.
}
