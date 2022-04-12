class Test
{
public:
    enum
    {
        value = 1
    };
    typedef int DWORD;
};
int p = 0;

template <typename T>
void foo(T a)
{
    // "*" 연산자의 의미
    Test::value *p; // 곱하기, 좌측항이 값.
    Test::DWORD *p; // 포인터 변수 선언, 좌측항이 타입.

    // typename을 사용할 때는 컴파일러가 정확히 유추할 수 없기 때문에 "값"으로 해석한다.
    T::value *p; // OK
    // T::DWORD *p; // ERROR
    typename T::DWORD *p; // OK

    // 결론: 템플릿 인자에 의존해서 이름을 참조할 때, 값이 아닌 타입이라면, 반드시 typename을 적어야 한다.
}

int main()
{
    Test t;
    foo(t);
}