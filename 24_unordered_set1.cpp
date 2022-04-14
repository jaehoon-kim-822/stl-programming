#include <iostream>
#include <unordered_set>
#include <string>
#include "show.h"

// 정렬되지 않은 트리.
int main()
{
    // STL의 hash는 함수 객체로 되어 있다.
    std::hash<int> hi;
    std::hash<double> hd;
    std::hash<std::string> hs;

    std::cout << hi(30) << std::endl;
    std::cout << hi(40) << std::endl;
    std::cout << hd(3.4) << std::endl;
    std::cout << hs("hello") << std::endl;
    
    // set: tree 기반.
    // unordered_set: hash 기반. 정렬이 불필요하나, 탐색 속도는 빠른것.
    std::unordered_set<int> s;
    s.insert(10); // set이라면 rb tree 기반이나, unordered_set은 30을 hash 함수로 보냄.
    s.insert(35);
    s.insert(20);
    s.insert(25);

    auto p = s.find(20); // 해쉬 함수를 사용해서 검색

    std::cout << *p << std::endl;

    show(s);
}
