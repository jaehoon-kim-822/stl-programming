#include <iostream>
#include <string>
#include "show.h"
#include <map>

// map : pair 를 저장하는 set,   key 값으로 value 를 저장
// 동일 key 안됨.
int main()
{
    std::map<std::string, std::string> m;

    // 요소 넣기
    // 1. pair 만들어서 넣기
    m.insert(std::pair<std::string, std::string>("mon", "월요일"));

    // 2. make_pair
    m.insert(std::make_pair("tue", "화요일"));

    // 3. emplace
    m.emplace("wed", "수요일");

    // 4. [] 연산자 사용. 항목을 추가하는 연산. 항목에 접근하는 연산이 아님.
    m["sun"] = "일요일";
    std::string s1 = m["sun"];
    std::string s2 = m["sat"]; // map에 key "sat"가 없지만 연산은 성공한다. 이 시점에서 {"sat", ""} 으로 항목을 추가한 뒤, value를 반환한다.

    bool b = m["fri"] == "";            // 항상 성공
    bool b2 = m.find("thr") == m.end(); // 권장하는 방식.

    // 반복자에 대해서
    auto p = m.begin();
    std::cout << p->first << p->second << std::endl;

    auto p = m.find("wed"); // find(키값)

    // p를 사용해서 "wed : 수요일" 이라고 출력해보세요

    // [] 연산자
    std::cout << m["sun"] << std::endl;

    // map 과 range-for
    for (const auto &e : m)
    {
        std::cout << e.first << std::endl;
    }

    // Since C++17
    std::pair<int, int> p(1, 2);
    auto [a, b] = p;

    for (auto [key, value] : m)
    {
        std::cout << key << std::endl;
        std::cout << value << std::endl;
    }
}
