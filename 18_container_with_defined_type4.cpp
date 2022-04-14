#include <vector>
#include <algorithm>
#include "show.h"

class Shape
{
    // dynamic_cast를 사용하려면, 기반클래스에 가상소멸자가 필수.
public:
    virtual ~Shape() {}
};

class Point : public Shape
{
};

class Rect : public Shape
{
public:
    void draw() const {}
};

int main()
{
    std::vector<Shape *> v2;
    v2.push_back(new Point);
    v2.push_back(new Rect);
    // v2.push_back(new int); // error
    Shape *p = v2[0];

    // 파생클래스의 고유 멤버(함수)에 접근하려면, 타입을 알 수 있어야 한다.

    // 이미 확실하게 아는 경우
    Rect *p1 = static_cast<Rect *>(v2[1]);

    // 확실하게 알기 어려운 경우
    Rect *p2 = dynamic_cast<Rect *>(v2[1]);
    // v2[1]가 Rect를 가리키는지 검사 함. 성능 저하가 있음.
    // 가리키는 대상이 Rect면 정상적인 주소.
    // 가리키는 대상이 Rect가 아니면 0.
    if (0 != p2)
    {
        p2->draw();
    }
}
