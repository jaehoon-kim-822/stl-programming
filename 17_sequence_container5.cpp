#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "show.h"

// 컨테이너를 보관하는 컨테이너

int main()
{
    std::vector<int> v1(10, 0);
    v1[0] = 10;

    std::vector<std::vector<int>> v2(10, std::vector<int>(10));
    v2[0][0] = 10;

    std::vector<std::list<int>> v3(10);
}