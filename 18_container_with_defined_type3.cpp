#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

class Point
{
public:
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b)
    {
        std::cout << "Point()" << std::endl;
    }
    ~Point() { std::cout << "~Point()" << std::endl; }

    Point(const Point &p)
    {
        std::cout << "Point(const Point&)" << std::endl;
    }
    void dump() const
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    std::vector<Point> v1;
    std::vector<Point *> v2(5); // Point의 포인터가 5개 있음. 객체 생성이 필요.

    v1.emplace_back(1, 2); // Point(1,2)
    v1.emplace_back(2, 3);
    v1.emplace_back(3, 2);
    v1.emplace_back(0, 1);

    std::vector<Point *> v(5);
    v.push_back(new Point(1, 2));
    v.push_back(new Point(3, 1));
    v.push_back(new Point(4, 2));
    v.push_back(new Point(2, 2));
    // std::sort(std::begin(v), std::end(v)); // error
    // Point 타입에 비교 연산을 위한 재정의를 한다. operator<(const Point& p), operator>(const Point& p)
    std::sort(std::begin(v), std::end(v), [](const Point &p1, const Point &p2)
              { return p1.x > p2.x; });

    for (auto p : v)
        p->dump();

    for (auto p : v)
        delete p;
}
