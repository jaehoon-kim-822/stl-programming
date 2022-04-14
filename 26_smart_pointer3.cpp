#include <iostream>
#include <memory>

void *operator new(size_t sz)
{
    std::cout << "new : " << sz << std::endl;
    return malloc(sz);
}

struct Point
{
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b) {}
};

void foo(std::shared_ptr<int> sp, int n) {}

int goo() { return 10; }

int main()
{
    // Memory의 변경 순서
    // new Point에 대한 메모리 할당. 8B = sizeof(Point)
    // share_ptr의 관리객체(reference count 등)에 대한 메모리 할당. 24B(MSVC, G++)
    std::shared_ptr<Point> sp1(new Point(1, 2));                // 타입객체와 관리객체가 다른 공간. 32B(8B + 24B)
    std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2); // 타입객체와 관리객체가 같은 공간. 메모리 파편화를 줄이고, 메모리를 절약. 24B(8B + 16B). 관리객체에서 포인터 크기 절약

    foo(std::shared_ptr<int>(new int), goo());
    //       (1)                 (2)   (3)
    // 1 -> 3 -> exception: new int 를 반환 못함. 메모리 누수.
    // 자원할당과 자원관리객체의 생성은 반드시 한번에 수행되어야 함.

    foo(std::make_shared<int>(0), goo()); // (1)과 (2)가 한번에 수행 됨.

    // 삭제자 변경
    std::shared_ptr<int> sp1(new int);
    std::shared_ptr<int> sp2((int *)malloc(sizeof(int)), foo); // shared_ptr은 delete로 메모리 반환한다. 그래서 deallocator를 전달해줘야 함.
    std::shared_ptr<int> sp3((int *)malloc(sizeof(int)), free);
    std::shared_ptr<int> sp4((int *)malloc(sizeof(int)), [](int *p)
                             { free(p); });

    // delete[]를 해야하는데, shared_ptr은 delete를 함.
    std::shared_ptr<int> sp5(new int[10], [](int *p)
                             { delete[] p; });
    std::shared_ptr<int[]> sp6(int[10]); // Since C++17

    std::shared_ptr<Point> sp1(new Point(1, 2));
    std::shared_ptr<Point> sp2 = std::make_shared<Point>(1, 2);                              // 권장하는 예시
    std::shared_ptr<Point> sp3 = std::allocate_shared<Point>(std::allocator<Point>(), 1, 2); // make_shared는 메모리 할당/반환에 대한 정책을 변경할 수 없음. 그럴 때 allocate_shared 를 사용함.

    std::shared_ptr<FILE> fp(fopen("a.txt", "wt"), fclose);
    fprintf(fp.get(), "hello");

    // 1. 자원 누구. free 하지 않는 것.
    // C++의 소멸자, 스마트포인터의 자동삭제 기능 등.
    int *p1 = (int *)malloc(20);

    // 2. 중복 반환
    // 스마트포인터의 참조계수로 해결.
    int *p2 = p1;
    free(p1);
    free(p2);

    // 3. Dangling pointer - 포인터가 가리키는 곳이 이미 삭제 된 경우.
    int *p3 = (int *)malloc(4);
    free(p3); // 메모리는 반환되지만, p3가 0을 가리키진 않음. 스마트포인터는 reset으로 정리 됨.

    if (p3 != 0)
        *p3 = 10;
}

