#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

void foo1(int n)
{
    std::cout << n << std::endl;
}

int foo2(int n1, int n2)
{
    return n1 + n2;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // for_each 알고리즘
    std::for_each(v.begin(), v.end(), foo1);

    std::list<int> s1 = {1, 2, 3, 4, 5};
    std::list<int> s2 = {6, 7, 8, 9, 10};
    std::list<int> s3;

    // transform 알고리즘
    std::transform(s1.begin(), s1.end(),   // 이 구간의 내용을
                   s2.begin(),             // 이 구간의 요소와 함께, 마지막 인자인 함수로 보낸다.
                   std::back_inserter(s3), // 마지막 인자인 함수의 반환 값은 이 곳에 넣어진다.
                   foo2);

    // 람다 표현식 Since c++11
    // 정의된 함수보다 람다 표현식이 빠르게 수행된다.
    std::transform(s1.begin(), s1.end(),
                   s2.begin(),
                   std::back_inserter(s3),
                   [](int a, int b)
                   { return a + b; });

    return 0;
}
