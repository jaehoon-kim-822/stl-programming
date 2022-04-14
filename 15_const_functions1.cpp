#include <iostream>

class Point
{
public:
    int x, y;

    Point(int a, int b) : x(a), y(b) {}

    void set(int a, int b)
    {
        x = a;
        y = b;
    }

    // 멤버변수의 변경이 있으면 상수 멤버함수가 될 수 없다.
    void constSet(int a, int b) const
    {
        x = a;
        y = b;
    }

    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }

    void constPrint() const noexcept
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int main()
{
    const Point pt(1, 2);

    pt.x = 10;           // ERROR.
    pt.set(10, 20);      // ERROR.
    pt.print();          // ERROR. 함수 선언부로 내부의 값 변경이 있는 것을 판단할 수 없기 때문에 불가.
    pt.constPrint();     // OK. 내부적으로 값의 변경이 없는 상수 멤버함수는 상수객체에서 호출할 수 있음.
}
