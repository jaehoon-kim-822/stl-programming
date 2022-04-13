#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <fstream>

int main()
{
    std::ifstream fin("1_stream4.cpp");
    std::istream_iterator<char> p1(fin); // 파일의 시작.
    std::istream_iterator<char> p2;      // 파일의 끝, EOF

    std::ostream_iterator<char> p3(std::cout, " ");

    std::copy(p1, p2, p3); // 파일의 모든 내용을 화면에 출력. 공백 무시.

    // 공백 포함
    std::istreambuf_iterator<char> p4(fin); // 파일의 시작.
    std::istreambuf_iterator<char> p5;      // 파일의 끝, EOF

    std::copy(p4, p5, p3); // 파일의 모든 내용을 화면에 출력. 공백 무시.
}