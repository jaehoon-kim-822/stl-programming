#include <iostream>
// 사용자 정의타입의 비교연산에 대한 재정의 시 상수 멤버함수를 반드시 해야 함.
// 비교 대상이 상수 객체인 경우, 상수 멤버함수가 아니면 컴파일 에러 발생.

class Point
{
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}

    // 상수 객체로 만들어도 사용할 수 있어야 하므로, 상수 멤버함수로 선언한다.
    // typename T가 primitive가 아닐 수 있으므로, call by reference.
    // call be reference에 대한 read only operation 이므로 const 추가.
    // 인자로 상수를 받을 수가 있으므로, const 추가.
    bool operator==(const Point &pt) const
    {
        return x == pt.x && y == pt.y;
    }
};

int main()
{
    Point p1(1, 2);
    Point p2(1, 2);

    if (p1 == p2)
    {
    }
}
