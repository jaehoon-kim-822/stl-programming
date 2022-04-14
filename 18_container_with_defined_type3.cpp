#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

class Point
{
public:
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b) {}
    ~Point() {}

    void dump() const { std::cout << x << ", " << y << std::endl; }
};

int main()
{
    std::vector<Point> v;

    v.emplace_back(1, 2); // Point(1,2)
    v.emplace_back(2, 3);
    v.emplace_back(3, 2);
    v.emplace_back(0, 1);

    std::sort(std::begin(v), std::end(v)); // error
    // 1. Predicates 전달
    std::sort(std::begin(v), std::end(v), [](const Point &p1, const Point &p2)
              { return p1.x > p2.x; }); // Predictor

    // 2. Point 타입에 비교 연산을 위한 재정의를 한다. operator<(const Point& p), operator>(const Point& p)
}
