#include <memory>
#include <iostream>

// int* Alloc()
// std::shared_ptr<int> Alloc() // caller가 반드시 shared_ptr로만 받아야 함.
std::unique_ptr<int> Alloc() // caller가 shared_ptr, unique_ptr을 선택가능.
{
    // return new int;
    // return std::unique_ptr<int>;
    return std::unique_ptr<int>(new int);
}

int main()
{
    // shared_ptr 자원 공유.
    // unique_ptr 자원 독점.

    // 관리객체가 없어서 가볍고 빠르다.
    std::unique_ptr<int> up1(new int);
    std::unique_ptr<int> up2 = up1; // error

    std::cout << sizeof(up1) << std::endl;
    std::cout << sizeof(sizeof(int *)) << std::endl;

    std::unique_ptr<int> up2 = std::move(up1); // 자원의 복사가 아니라 이동. 여기서부터 up1은 유효하지 않음.

    std::shared_ptr<int> sp3 = Alloc();
    std::unique_ptr<int> up3 = Alloc();
}