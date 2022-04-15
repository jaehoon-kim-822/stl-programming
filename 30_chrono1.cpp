#include <iostream>
#include <chrono>
#include <ctime>
using namespace std::literals; // literals( h, min, s, ms, us, ns )

// ratio: 비율 관련 라이브러리
// chrono: 시간 및 날짜 관련 라이브러리
// duration: 특정 단위의 갯수를 표현
// literals: user define literals - h, min, s, ms, us, ns
// system_clock: 현재 시간을 얻을때 사용하는 클래스. non monotonic clock
// time_point: 시간의 시작점과 duration<>을 보관하는 클래스
// ex) epoch time: 1970년 1월 1일 기준 16880 시간 경과

int main()
{
    // duration
    std::chrono::duration<int, std::ratio<1, 100>> d1(2); // 1/100 * 2
    std::chrono::duration<int, std::ratio<1, 1000>> d2(d1);

    std::cout << d2.count() << std::endl; // 20

    // 거리 단위
    using Meter = std::chrono::duration<int, std::ratio<1, 1>>;
    // using CentiMeter = std::chrono::duration<int, std::ratio<1, 100>>;
    using CentiMeter = std::chrono::duration<int, std::centi>;
    // using KiloMeter = std::chrono::duration<int, std::ratio<1000, 1>>;
    using KiloMeter = std::chrono::duration<int, std::kilo>;

    KiloMeter km(3);                      // 3km
    CentiMeter cm = km;                   // 30,000cm
    std::cout << cm.count() << std::endl; // 30000

    // 시간 단위
    using seconds = std::chrono::duration<int, std::ratio<1, 1>>;
    using minutes = std::chrono::duration<int, std::ratio<60, 1>>;
    using hours = std::chrono::duration<int, std::ratio<3600, 1>>;

    // predefined typedef
    std::chrono::hours h(1); // typedef duration<int, ratio<3600,1>> hours;
    std::chrono::minutes m = h;
    std::chrono::seconds s = h;
    std::chrono::milliseconds ms = h;
    std::chrono::microseconds us = h;
    std::chrono::nanoseconds ns = h;

    std::chrono::seconds sec(3);

    std::cout << h.count() << std::endl;
    std::cout << m.count() << std::endl;
    std::cout << s.count() << std::endl;
    std::cout << ms.count() << std::endl;
    std::cout << us.count() << std::endl;
    std::cout << ns.count() << std::endl;

    // literals( h, min, s, ms, us, ns )
    // C++11부터 user define literals 가 있음.

    std::chrono::seconds sec = 1min;

    sec = 1min + 3s;
    sec += 40s;
    std::cout << sec.count() << std::endl;

    std::chrono::seconds sec2 = 1min + 3s;
    std::cout << sec2.count() << std::endl;

    // Truncation
    std::chrono::hours h(1);
    std::chrono::seconds s(h);           // 큰 단위 -> 작은 단위: no truncation.
    std::cout << s.count() << std::endl; // 3600
    s = s + 10s;
    std::cout << s.count() << std::endl; // 3610

    std::chrono::minutes m1(s);                                                    // truncation.
    std::chrono::minutes m2 = std::chrono::duration_cast<std::chrono::minutes>(s); // no truncation.
    std::cout << m1.count() << std::endl;                                          // 60
    std::cout << m2.count() << std::endl;                                          // 61

    // 현재 시간을 얻는 방법
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();

    // time_point => duration 얻어내기... 정밀도가 낮아지는 경우 명시적 캐스팅 필요..
    std::chrono::nanoseconds nanosec = tp.time_since_epoch();
    std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(tp.time_since_epoch());
    // std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(nanosec);

    std::cout << nanosec.count() << std::endl;
    std::cout << sec.count() << std::endl;

    using days = std::chrono::duration<int, std::ratio<60 * 60 * 24>>;
    std::cout << (std::chrono::duration_cast<days>(tp.time_since_epoch())).count() << std::endl;

    // time_point => 칼린더 형태의 날짜로 변경하기
    time_t t = std::chrono::system_clock::to_time_t(tp); // 1. time_point => struct time_t
    std::string s = ctime(&t);                           // 2. struct time_t => char*
    std::cout << s << std::endl;
}
