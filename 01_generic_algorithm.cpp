#include <iostream>

// Step 1. C 표준 함수
char *xstrchr(char *s, int c)
{
    while (*s != 0 && *s != c)
        ++s;
    return *s == 0 ? 0 : s;
}

int main()
{
    char s[] = "abcdefgh";

    char *p = xstrchr(s, 'c');

    if (p == 0)
        std::cout << "not found" << std::endl;
    else
        std::cout << "found : " << *p << std::endl;
}