#include <iostream>
#include <list>

// for iterator
template <typename T>
struct iterator_traits
{
    using value_type = typename T::value_type;
};

// for primitive type
template <typename T>
struct iterator_traits<T *>
{
    using value_type = T;
};

template <typename T>
typename iterator_traits<T>::value_type sum(T first, T last)
{
    typename iterator_traits<T>::value_type s = 0;

    while (first != last)
    {
        s = s + *first;
        ++first;
    }
    return s;
}

int main()
{
    std::list<int> s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n1 = sum(std::begin(s), std::end(s));
    int n2 = sum(x, x + 10);

    std::cout << n1 << std::endl; // 55
    std::cout << n2 << std::endl; // 55
}