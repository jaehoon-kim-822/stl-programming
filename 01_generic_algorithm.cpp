#include <iostream>

template <typename T>
T *find(T *first, T *last, T c)
{
    while (first != last && *first != c)
        ++first;
    return first == last ? nullptr : first;
}

int main()
{
    double x[10] = {1, 2, 3, 4, 5};

    double *p = find(x, x + 5, 5.0);

    if (p == nullptr)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found : " << *p << std::endl;
}