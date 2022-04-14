#include <iostream>

void fn(int n) { std::cout << "int" << std::endl; }
void fn(void *n) { std::cout << "void *" << std::endl; }
void goo(char *p) {}

// 문제1: c++ 다형성에 의해서 void *의 인자에 0을 못보냄.
// 문제2: c++ 포인터 형번환에 의해서 char *에 void * 타입이 형변환 되지 않음.

struct nullptr_sample // nullptr keyword since C++11
{
    // operator void *() { return 0; } // 변환자 재정의
    // operator char *() { return 0; }
    template <typename T>
    operator T *() const { return 0; }
} nullptrs;

int main()
{
    fn(0);
    fn((void *)0); // c++ 다형성
    goo(0);
    goo((void *)0); // error. 형변환
#ifdef __cplusplus
#define NULL 0
#else
#define NULL (void *)0
#endif
    fn(NULL);  // fn(void *n)이 아니라 fn(int n)으로 호출 됨.
    goo(NULL); // NULL이 (void *)0 이면 형변환 문제로 error. NULL이 0이면 ok.

    int n = 0;
    goo(n); // error. literal 0일 때만, 포인터로 변환 됨.

    fn(nullptrs);
    goo(nullptrs);
}
