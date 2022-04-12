#include <iostream>
#include <list>
#include <filesystem>

int main()
{
    std::filesystem::directory_iterator p("C:\\windows");

    std::cout << *p << std::endl;
    ++p;
    std::cout << *p << std::endl;
}