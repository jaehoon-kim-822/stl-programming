#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

// Legacy handling
void foo(int *arr, int sz) {}

int main()
{
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    foo(x, 10);

    // foo를 변경하지 않고, foo 에 v를 전달하자.
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    foo(&v[0], v.size());    // index access도 나름대로의 방법.
    foo(v.data(), v.size()); // data() 할당된 메모리의 주소를 반환.
}
