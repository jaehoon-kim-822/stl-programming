#include <iostream>
#include <bitset>
// 0 ~ 9 사이의 난수를 반환하는 함수
// 0 ~ 9 사이의 중복되지 않은 난수를 반환하는 함수. 상태가 필요함. 함수에는 상태가 없음.
// 일반 함수는 상태를 가질 수 없지만, 함수 객체는 상태(데이터)를 가질 수 있다.

template <int COUNT, int BASE>
class URandom
{
    std::bitset<COUNT> bs;
    bool recycle;

public:
    URandom(bool b = false) : recycle(b)
    {
        bs.set();
    }

    int operator()()
    {
        int value = -1;
        if (false == bs.none())
        {
            while (false == bs.test(value = rand() % COUNT))
            {
            }
            bs.reset(value);
        }
        else if (true == recycle)
        {
            bs.set();
        }
        return BASE + value;
    }

    reset() { bs.set(); }
    int remain() { return bs.count(); }
};

URandom<100, 100> urand(true); // 100 ~ 199의 유일 난수.

int main()
{
    for (int i = 0; i < 10; i++)
        std::cout << urand() << std::endl;
}
