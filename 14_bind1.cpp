#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders; // _1, _2, _3 ... 등이 정의 됨.

// 4항 함수
void foo(int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1, 2, 3, 4); // 4항 함수..

    // std::bind // M항 함수/함수객체를 N항 함수로 변경하는 도구. 단, M > N
    auto f = std::bind(foo, 1, 2, 3, 4); // foo를 인자 1, 2, 3, 4로 호출하는 새로운 함수를 만들어 줘. 4항에서 0항으로 변경됨.

    f(); // foo(1,2,3,4) 동일

    std::bind(foo, 5, 6, _1, 3)(2); // 4항을 1항으로. 세 번째 인자를 첫 번째 인자로. 2를 넘김.

    std::bind(foo, 9, _2, 6, _1)(7, 4); // 4항을 2항으로. 두 번째 인자를 두 번째 인자로. 네 번째 인자를 첫 번째 인자로. 7과 4를 넘김.
}
