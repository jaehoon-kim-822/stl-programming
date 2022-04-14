#include <iostream>
#include <vector>
#include "show.h"

class Point
{
    int x, y;

public:
    Point(int a = 0, int b = 0) : x(a), y(b)
    {
        std::cout << "Point()" << std::endl;
    }
    ~Point() { std::cout << "~Point()" << std::endl; }
    Point(const Point &p)
    {
        std::cout << "Point(const Point&)" << std::endl;
    }
};

int main()
{
    std::vector<Point> v;

    // 객체를 생성 후 전달.
    // 실행결과: pt의 생성자 -> v에 추가된 Point의 복사 생성자 -> end of function -> pt의 소멸자 -> v에 추가된 Point의 소멸자
    Point pt(1, 2);
    v.push_back(pt);

    // 임시 객체를 전달.
    // 실행결과: 임시 객체의 생성자 -> v에 추가된 Point의 복사 생성자 -> pt의 소멸자 -> end of function -> v에 추가된 Point의 소멸자
    v.push_back(Point(1, 2));

    // v의 Point 복사의 생성자(1, 2) -> end of function -> v에 추가된 Point의 소멸자
    v.emplace_back(1, 2); // 임시 객체가 아닌, 생성자에 전달할 인자를 제공. 임시 객체의 생성 없음.

    std::cout << "------------------" << std::endl;
}
