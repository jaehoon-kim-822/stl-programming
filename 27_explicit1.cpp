#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Bike
{
    int gear;

public:
    // explicit  생성자 : 직접 초기화만 가능하고, 복사 초기화는 할수 없다.
    explicit Bike(int n) : gear(n) {}
};

void fn(Bike b) {} //
void fn1(std::string s) {}
void fn2(std::vector<int> v) {}
void push_back(std::shared_ptr<int> sp) {}
int main()
{
    // 인자가 한 개인 생성자는 아래 4가지 형태로 객체 생성 가능
    // C++98
    Bike b1(10);  // 직접 초기화
    Bike b2 = 10; // 복사 초기화
    // C++11
    Bike b3{10};    // 직접 초기화
    Bike b4 = {10}; // 복사 초기화

    fn(10);       // error. Bike b = 10, 복사 생성이라 안됨.
    fn(Bike(10)); // ok. Bike b = Bike(10). int 인자가 한 개인 생성자가 아니라, Bike 객체에 대한 복사 생성자.

    fn1("a"); // string은 explicit이 아님.
    fn2(10);  // vector는 explicit임.

    std::string s1("a");
    std::string s2 = "a";

    std::vector<int> v1(10);
    std::vector<int> v2 = 10; // 생성자가 explicit

    std::shared_ptr<int> sp1(new int);
    std::shared_ptr<int> sp2 = new int; // error. explicit

    push_back(new int);                       // error. std::shared_ptr<int> sp = new int
    push_back(std::shared_ptr<int>(new int)); // ok. std::shared_ptr<int> sp = std::shared_ptr<int>(new int)
    push_back(std::make_shared<int>(0));      // ok. std::shared_ptr<int> sp = std::make_shared<int>(0)
}
}
