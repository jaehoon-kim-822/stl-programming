#include <vector>
#include "show.h"

class Point
{
    int x, y;

public:
    Point(int a, int b) : x(a), y(b) {}
};

int main()
{
    // 10개의 객체가 생성됨.
    // 기본 생성자가 없음.
    std::vector<Point> v(10);

    Point pt(0, 0);
    std::vector<Point> v1(10, pt);                                   // Sample object를 제공하면, 복사 생성함.
    std::vector<Point> v2(10, Point(0, 0));                          // Temporary object로 제공, 복사 생성.
    std::vector<Point> v3(10, {0, 0});                               // Since C++11, {}로 초기화 가능, 복사 생성.
    std::vector<Point> v4 = {Point(0, 0), Point(0, 1), Point(0, 2)}; // 요소별 초기화.
    std::vector<Point> v5 = {{0, 0}, {0, 1}, {0, 2}};                // Since C++11.
    std::vector<Point> v6{{0, 1}, {0, 2}, {0, 2}};                   // Since C++11.
    std::vector<Point> v7(10, {0, 0});
    v7.resize(15);         // 기본 생성자가 없어서 에러
    v7.resize(15, {0, 0}); // Sample object를 제공
    v7.resize(7);          // 크기가 줄어도 에러.
    v7.resize(7, {0, 0});  // Sample object를 제공

    std::vector<std::vector<int>> m1(10);
    std::vector<std::vector<int>> m2(10, 10); // 에러. 두 번째 항은 객체가 와야 함.
    std::vector<std::vector<int>> m3(10, {10});
    std::vector<std::vector<int>> m4(10, std::vector<int>(10));
    std::vector<std::vector<int>> m5(10, std::vector<int>(10, 3));

    m1[2][0] = 10; // 런타임에러. m1의 세 번째 요소인 vector<int>는 아직 요소가 없다.
    m3[2][0] = 10; // 가능. 요소가 1개(값 10)인 vector<int>가 10개 초기화 된 것. m3[2][1]은 에러.

    std::cout << m3[2][0] << std::endl; // 10
    std::cout << m5[2][0] << std::endl; // 3

    // 기본 생성자를 만드는 것이 좋다.
    // 기본 생성자가 없는 기존의 타입을 사용할 때는 위와 같이 샘플 객체를 제공한다.
}
