#include <iostream>

struct Plus
{
    int operator()(int a, int b)
    {
        return a + b;
    }
};

int main()
{
    Plus p; // 함수 객체, 구조체 타입의 객체 p, 함수가 아님.

    int n = p(1, 2); // p.operator()(1, 2) 와 동일

    // a + b; // a와 b가 primitive type이 아닌 경우 재정의된 연산자를 찾는다. a.operator+(b)
    // a - b; // a.operator-(b)
    // a(); // 함수라면 점프, 함수 객체라면 a.operator()(), -> 괄호가 두개인 이유: (연산자 이름)(호출부)
    // a(1,2); // a.operator()(1, 2)
}
