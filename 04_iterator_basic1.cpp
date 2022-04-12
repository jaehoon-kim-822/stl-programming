#include <iostream>
#include <list>

int main()
{
    int x[5] = {1, 2, 3, 4, 5};
    int *p = x;
    *p;
    ++p;

    std::list<int> s = {1, 2, 3, 4, 5};
    std::list<int>::iterator p2 = s.begin();
    *p2;
    ++p2;
}
