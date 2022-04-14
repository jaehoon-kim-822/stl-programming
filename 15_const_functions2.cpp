// 상수 멤버함수는 선택이 아닌 필수.
// 함수 멤버를 만들 때, 객체 상태를 변경하지 않는 모든 멤버함수(Getter)는 반드시 상수 멤버함수로 선언해야 함.

class Rect
{
    int x, y, w, h;

public:
    Rect(int x, int y, int w, int h) : x{x}, y{y}, w{w}, h{h} {}

    int getArea() const { return w * h; }
};

void foo(const Rect &r) // 사용자 정의타입을 인자로 받을 때는, call by value를 피하자.
{
    int n = r.getArea();
}

int main()
{
    Rect r(1, 2, 3, 4);
    int n = r.getArea(); // ok.
    foo(r);
}