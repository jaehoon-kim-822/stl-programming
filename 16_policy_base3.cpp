#include <set>
#include <functional>
#include "show.h"

template <typename T, typename Pred = std::less<T>, typename Alloc = std::allocator<T>>
class set
{
public:
    void insert(const T &newElem)
    {
        if (pred(newElem, rootElem))
        {
            // add right child
        }
        else if (pred(rootElem, newElem))
        {
            // add left child
        }
        else
        {
            // fail
        }
    }
};

template <typename T>
struct Greater
{
    // 상수 객체로 만들어도 사용할 수 있어야 하므로, 상수 멤버함수로 선언한다.
    // typename T가 primitive가 아닐 수 있으므로, call by reference.
    // call be reference에 대한 read only operation 이므로 const 추가.
    // 인자로 상수를 받을 수가 있으므로, const 추가.
    inline bool operator()(const T& a, const T& b) const
    {
        return a > b;
    }
};

int main()
{
    const Greater<int> g;
    g(10, 20);

    std::set<int, Greater<int>> s;
    s.insert(15);
    s.insert(25);
    s.insert(5);
    s.insert(17);
    s.insert(10);
    show(s);

    std::set<int, std::greater<int>> b;
    b.insert(15);
    b.insert(25);
    b.insert(5);
    b.insert(17);
    b.insert(10);
    show(b);
}