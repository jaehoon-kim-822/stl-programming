#include <iostream>
#include <vector>
#include <list>

template <typename T>
void print_first_element(T &v)
{
    typename T::value_type n = v.front(); // "value_type"은 STL 규약.
    std::cout << n << std::endl;

    // c++11 이후로는 아래처럼 auto keyword를 사용할 수도 있음.
    // auto n2 = v.front();
    // std::cout << n2 << std::endl;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_first_element(v);

    std::vector<double> dv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_first_element(dv);
}

// template 기반 컨테이너를 만들 때, 컨테이너가 저장하는 타입을 외부에서 알고 싶을 떄가 있다.
template <typename T>
class list
{
public:
    // 해당 컨테이너의 타입을 참조할 수 있도록, 아래 같은 형태로 만들도록 약속 함.
    using value_type = T;
};