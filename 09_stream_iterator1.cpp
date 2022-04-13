#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

int main()
{
    int n = 10;

    std::cout << n << std::endl;

    // 스트림 반복자: 입출력에 사용하는 반복자
    std::ostream_iterator<int> p(std::cout, " ");

    *p = 10;
    ++p; // dummy
    *p = 20;

    // list의 모든 내용을 copy 알고리즘과 스트림 반복자로 출력하기.
    std::list<int> s = {1, 2, 3};
    std::copy(s.begin(), s.end(), p);
}