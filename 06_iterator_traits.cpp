#include <iostream>
#include <list>

int sum(int *first, int *last)
{
    int s = 0;

    while (first != last)
    {
        s = s + *first;
        ++first;
    }
    return s;
}

int main()
{
    int s[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = sum(s, s + 10);

    std::cout << n << std::endl; // 55
}