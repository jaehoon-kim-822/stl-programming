#include <forward_list> // Single list since c++11
#include <list>         // Double list since c++98

int main()
{
    std::forward_list<int> s1 = {1, 2, 3};

    std::list<int> s2 = {1, 2, 3};

    auto p1 = begin(s1);
    auto p2 = begin(s2);

    ++p1;
    // --p1; // single 이라서 역방향 지원이 안됨.
    ++p2;
    --p2;
}