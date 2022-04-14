#include <memory>
#include <iostream>
#include <string>

struct People
{
    std::string name;

    People(std::string n) : name(n) {}
    ~People() { std::cout << name << "detroyed" << std::endl; }

    People *bf;
};

int main()
{
    std::shared_ptr<People> sp1(new People("kim"));
    {
        std::shared_ptr<People> sp2(new People("lee"));
        sp1->bf = sp2.get();
        sp2->bf = sp1.get();
    }

    if (sp1->bf != 0) // dangling pointer 발생.
    {
        std::cout << sp1->bf->name << std::endl;
    }
}
