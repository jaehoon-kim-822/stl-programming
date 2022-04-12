#include <iostream>

// Single linked list
template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(const T &a, Node *n) : data(a), next(n) {}
};

template <typename T>
class slist_iterator
{
    Node<T> *current;

public:
    slist_iterator(Node<T> *p = nullptr) : current(p) {}

    slist_iterator &operator++()
    {
        current = current->next;
        return *this;
    }

    T &operator*() { return current->data; }

    bool operator==(const slist_iterator &it) const { return current == it.current; }
    bool operator!=(const slist_iterator &it) const { return current != it.current; }
};

template <typename T>
class slist
{
    Node<T> *head = nullptr;

public:
    void push_front(const T &a)
    {
        head = new Node<T>(a, head);
    }

    using iterator = slist_iterator<T>;

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(nullptr); }
};

int main()
{
    slist<int> s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    slist<int>::iterator p = s.begin();

    std::cout << *p << std::endl; // 50
    ++p;                          // slist s는 array와 다르게, 각 요소가 떨어진 공간에 있지만, 재정의된 ++ 연산으로 다음 요소로 이동 가능.
    std::cout << *p << std::endl; // 40
}