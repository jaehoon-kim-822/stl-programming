#include <iostream> // 표준 입출력 스트림
#include <fstream>  // 파일 스트림
#include <sstream>  // 메모리(스트링)스트림
#include <string>
#include <iomanip>

int main()
{
    std::cout << "hello"; // 화면 출력

    std::ofstream fout("a.txt");
    fout << "hello"; // 파일 출력

    std::ostringstream sout; // 메모리(string) 출력 스트림.
    sout << "hello";         // sout 내부의 문자열에 출력
    std::string s = sout.str();
    std::cout << s << std::endl;

    int n = 3;
    double d = 3.333;
    // C-Style
    char s[32];
    sprintf(s, "n = %d, d = %lf", n, d);
    snprintf(s, 32, "n = %d, d = %lf", n, d);
    std::cout << s << std::endl;

    // C++ Style(STL)
    std::ostringstream sout;
    sout << "n = " << n << ", ";
    sout << "n = " << std::setprecision(10) << d; // 소수점 이하 자리수 지정.

    std::string s1 = sout.str();
    std::cout << s1 << std::endl;

    std::istringstream iss("to be or not to be");
    std::string s;
    while (iss >> s) // 한 단어씩 읽기. like be std::cin >> s
        std::cout << s << std::endl;
}
