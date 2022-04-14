#include <memory>
#include <iostream>
#include <string>

struct People
{
    std::string name;

    People(std::string n) : name(n) {}
    ~People() { std::cout << name << "detroyed" << std::endl; }

    People *bf; // shared_ptr 대신 primitive pointer 사용.
};

int main()
{
    std::shared_ptr<People> sp1(new People("kim"));
    std::shared_ptr<People> sp2(new People("lee"));

    sp1->bf = sp2.get();
    sp2->bf = sp1.get();
}
