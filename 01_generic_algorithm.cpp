#include <iostream>

template <typename T1, typename T2>
T1 find(T1 first, T1 last, T2 value)
{
    while (first != last && *first != value)
        ++first;
    return first == last ? nullptr : first;
}

int main()
{
    double x[10] = {1, 2, 3, 4, 5};

    double *p = find(x, x + 5, 5.0f);

    if (p == nullptr)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found : " << *p << std::endl;
}