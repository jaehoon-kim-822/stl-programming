#include <iostream>
#include <vector>
#include <list>

template <typename T>
void print_first_element(std::vector<T> &v)
{
    T n = v.front();
    std::cout << n << std::endl;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_first_element(v);

    std::vector<double> dv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_first_element(dv);
}
