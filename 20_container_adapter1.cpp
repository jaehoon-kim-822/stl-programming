#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include "debug_alloc.h"

template <typename T, typename Cont = std::deque<T>>
class stack
{
    Cont c;

public:
    inline void push(const T &c) { c.push_back(c); }
    inline void pop(void) { c.pop_back(); }
    inline Cont &top() { return c.back(); }
};

#include <stack> // 공식 명칭은 stack adapter. sequence container를 stack 처럼 사용하도록 adapting.
int main()
{
    stack<int> s;
    stack<int, std::list<int>> s1;
    stack<int, std::vector<int>> s2; // 내부 컨테이너 변경하는 방법
    std::stack<int> s3;
    std::stack<int, std::list<int>> s4;
    std::stack<int, std::vector<int, debug_alloc<int>>> s5; // allocator는 debug alloc, 컨테이너는 vector<int>

    s.push(10);
    s.push(20);

    std::cout << s3.top() << std::endl;
}