#include "show.h"
#include <set>

// 사용자 정의타입을 사용.
// set은 크기 비교 가능해야 함.
// 방법1: 연산자 재정의. <, <=, >, >=, ==, !=
// 방법2: Predicator
struct Point
{
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}

    inline bool operator<(const Point &pt) const
    {
        return x < pt.x;
    }
};

struct PointCompare
{
    inline bool operator()(const Point &p1, const Point &p2) const
    {
        return p1.x < p2.x;
    }
};

int main()
{
    std::set<Point> s; // 기본 조건자가 less이므로 "<"연산 필요.
    std::set<Point, PointCompare> s;

    s.insert(Point(5, 5)); // 임시객체
    s.insert({4, 4});      // 임시객체
    s.emplace(3, 2);       // 이런 형태를 권장 함. 임시객체의 생성자 호출이 없음.
    s.emplace(2, 1);
    s.emplace(1, 5);

    Point pt(3, 0);
    auto ret = s.find(pt);
    // ==, != 연산이 재정의 되지 않았는데 에러 없음. 그러나 잘못된 것을 찾음(3, 2)
    // set은 삽입 시 정렬을 하는데 아래와 같은 방식이다. 그런 이유로 별도의 == 연산이 없어도 동일한 대상으로 판단할 수 있다.
    // 크기도 작지도 않다 =: Equivalency. 즉 y값이 달라도 같다고 취급될 수 있다.
    // 이진 탐색
    // if (root < elem)
    //     move left child
    // else if (elem < root)
    //     move right child
    // else
    //     set here

    // Equality. 선형 탐색은 "==" 으로 검색.
    auto ret2 = std::find(s.begin(), s.end(), pt); // ERROR

    // 정리
    // std::set::find: equivalency. 크지도 작지도 않은 동등함.
    // std::find: Equality. 동일함.
}
