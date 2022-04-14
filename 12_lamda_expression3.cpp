#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
    int v1 = 10;
    int v2 = 10;
    // 람다 표현식에서 지역변수를 사용하려면 캡쳐해야 함.
    auto f1 = [v1, v2](int a)
    { return a + v1 + v2; };

    // 값으로 캡쳐하면 읽기만 가능
    auto f1 = [v1](int a)
    { v1 = a; }; // ERROR. read only

    // 변경가능하게 하려면 참조 캡쳐 해야 함.
    auto f1 = [&v1](int a)
    { v1 = a; };
