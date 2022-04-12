#include <iostream>
#include <list>

int main()
{
    std::list<int> s1 = {1, 2, 3};

    auto p1 = std::begin(s1); // 첫 번째 요소를 가리키는 반복자
    auto p2 = std::end(s1);   // 마지막 다음 요소를 가리키는 반복자, "Past the end". 따라서 p2를 *(역참조)하면 안됨.

    // [p1, p2)

    *p1 = 10; // OK
    // *p2 = 20; // Error(runtime)

    while (p1 != p2)
    {
        ++p1;
    }

    std::list<int> s3;
    if (s3.empty())
    {
    }

    // begin == end는 empty라는 의미
    if (std::begin(s3) == std::end(s3))
    {
    }
}