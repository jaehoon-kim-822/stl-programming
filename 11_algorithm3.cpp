#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8};
    // s.reverse(); // 1. 멤버 함수가 있네?
    // std::reverse(s.begin(), s.end()); // 2. 알고리즘도 써보자. 
    // 멤버 함수는 연결 관계를 뒤집는다.
    // 알고리즘은 값(int)을 swap. 값의 크기가 크다면? 
    // 멤버 함수와 알고리즘은 메커니즘이 다르다. 
    show(s); // 8,7,6,5,4,3,2,1
    return 0;
}
