#include <memory>
#include <iostream>
#include <string>

struct People
{
    std::string name;

    People(std::string n) : name(n) {}
    ~People() { std::cout << name << "detroyed" << std::endl; }

    std::weak_ptr<People> bf;
};

int main()
{
    std::shared_ptr<People> sp1(new People("kim"));
    {
        std::shared_ptr<People> sp2(new People("lee"));
        sp1->bf = sp2;
        sp2->bf = sp1;
    }

    if (sp1->bf.expired()) // 없어도 됨. lock이 있으니까.
    {
        std::cout << "소멸 됨" << std::endl;
    }
    else
    {
        std::cout << "소멸 안됨" << std::endl;
        auto ret = sp1->bf->name;                    // error. weak_ptr로는 접근할 수 없음. 접근 중 다른 쓰레드에서 소멸시킬 수 있으니까.
        std::shared_ptr<People> sp = sp1->bf.lock(); // shared_ptr을 하나 만들어서, 소멸되지 않게함. sp를 만드는 동안에 소멸될 수 있으므로 thread lock을 시도.

        if (sp) // 유효성 확인 다시 시도. expired()부터 lock() 사이에 소멸했을 수 있기 때문에.
        {
            std::cout << sp->name << std::endl;
        }
    }
}
