#include <iostream>
#include <string>
#include "debug_alloc.h"

// 기존 string은 64bit arch에서 4자 문자열을 할당하면, 포인터는 8B인데 문자열은 공백까지 5B 였음.
// C++11 에서 facebook의 fb_string을 도입.

// std::string은 basic_string class

using debug_string = std::basic_string<char, std::char_traits<char>, debug_alloc<char>>;

template <typename T, // char, or wchar_t(uni-code)
          typename Traits = std::char_traits<T>,
          typename Alloc = std::allocator<T>>
class basic_string
{
    T *buff;
    Alloc ax;

public:
    bool operator==(const basic_string &other)
    {
        // 문자열의 상등 조사도 ㅇ단위 전략으로 교체할 수 있게 설계 됨.
        // compare는 static function 이므로, 단위 전략 구현 시 static function으로 구현해야 함.
        return Traits::compare(buf, other.buff)
    }
};

// 상세 구현은 번거로우니, 상속을 한다. cppreference.com
struct MyTraits : public std::char_traits<char>
{
    static char to_upper(char ch)
    {
        return std::toupper((unsigned char)ch);
    }
    static bool eq(char c1, char c2)
    {
        return to_upper(c1) == to_upper(c2);
    }
    static bool lt(char c1, char c2)
    {
        return to_upper(c1) < to_upper(c2);
    }
    static int compare(const char *s1, const char *s2, std::size_t n)
    {
        while (n-- != 0)
        {
            if (to_upper(*s1) < to_upper(*s2))
                return -1;
            if (to_upper(*s1) > to_upper(*s2))
                return 1;
            ++s1;
            ++s2;
        }
        return 0;
    }
    static const char *find(const char *s, std::size_t n, char a)
    {
        auto const ua(to_upper(a));
        while (n-- != 0)
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};

using string = basic_string<char>;
using wstring = basic_string<wchar_t>;

int main()
{
    // no log -> no allocation -> string size is 5B on g++ and msvc
    debug_string s1 = "abcd";
    std::string s2 = "ABCD";

    // no log -> no allocation -> string size is 16B on g++ and msvc
    debug_string s2 = "012345678901234";

    // no log -> allocate 17B -> string size is 17B on g++
    // no log -> allocate 32B -> string size is 17B on msvc
    debug_string s2 = "0123456789012345";

    bool b = (s1 == s2);

    std::cout << b << std::endl;
}
