#include <iostream>
#include <algorithm>
#include <functional>
#include "show.h"

int main()
{
    int x[10];
    // 컴파일 타임에 sort()는 세 개가 생성 된다.
    std::sort(x, x + 1, [](int a, int b)
              { return a < b; });
    std::sort(x, x + 1, [](int a, int b)
              { return a < b; });
    std::sort(x, x + 1, [](int a, int b)
              { return a < b; });

    // 동일한 람다 표현식을 여러번 사용한다면, "auto 변수"에 담아 놓고 사용하는게 좋다.
    auto cmp = [](int a, int b)
    { return a < b; }; // 여기서만 한 번 코드가 생성 된다.
    std::sort(x, x + 1, cmp);
    std::sort(x, x + 1, cmp);
    std::sort(x, x + 1, cmp);
}
