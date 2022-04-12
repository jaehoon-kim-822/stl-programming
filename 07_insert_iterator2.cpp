#include <iostream>
#include <algorithm>
#include <list>

int main()
{
    int x[5] = {10, 20, 30, 40, 50};

    std::list<int> s = {1, 2, 3, 4, 5};

    std::copy(x, x + 5, s.begin()); // 덮어쓴다.

    // std::copy(x, x + 5, s.end()); // ERROR(runtime).

    // 컨테이너 끝에 추가하는 방법.
    // 1. for, push back
    for (auto e : x)
        s.push_back(e);

    // 2. 삽입 반복자
    std::back_insert_iterator<std::list<int>> p1(s);
    std::copy(x, x + 5, p1);

    // 3. 삼입 반복자 함수형.
    std::copy(x, x + 5, std::back_inserter(s));

    for (auto &n : s)
        std::cout << n << std::endl;
}
