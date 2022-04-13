#include <iostream>
#include <bitset>
// 0 ~ 9 사이의 난수를 반환하는 함수
// 0 ~ 9 사이의 중복되지 않은 난수를 반환하는 함수. 상태가 필요함. 함수에는 상태가 없음.
// 일반 함수는 상태를 가질 수 없지만, 함수 객체는 상태(데이터)를 가질 수 있다.

class URandom
{
    std::bitset<10> bs;
    bool recycle;
public:
    URandom(bool b = false) : recycle(b)
    {
        bs.set();
    }

    int operator()()
    {
        if (bs.none())
        {
            if (true == recycle)
            {
                bs.set();
            }
            else
            {
                return -1;
            }
        }
        int value = -1;
        while (false == bs.test(value = rand() % 10));
        bs.reset(value);
        return value;
    }
};

URandom urand(true); // 11번 째에 초기화됨. 

int main()
{
    for (int i = 0; i < 10; i++)
        std::cout << urand() << std::endl;
}
