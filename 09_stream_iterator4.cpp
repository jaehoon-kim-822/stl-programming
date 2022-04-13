#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <fstream>

int main()
{
    std::ifstream fin("1_stream4.cpp");
    std::istream_iterator<char> p(fin);

    std::cout << *p << std::endl;
    ++p; // 유효함.
    std::cout << *p << std::endl;
}