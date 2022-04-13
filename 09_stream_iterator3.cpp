#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <fstream>

int main()
{
    // std::ostream_iterator<int> p(std::cout, " ");
    std::istream_iterator<int> p(std::cin);

    int n = *p;
    
    std::cout << n << std::endl;
}