#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <queue> // queue, priority_queue
#include "show.h"

// STL의 container adapter는 stack, queue, priority_queue

int main()
{
    // 다음중 에러를 모두 골라 보세요
    // stack은 단방향
    std::stack<int, std::list<int>> s1;
    std::stack<int, std::vector<int>> s2;
    std::stack<int, std::deque<int>> s3;

    // queue는 양방향
    std::queue<int, std::list<int>> q1;
    std::queue<int, std::vector<int>> q2; // runtime error. push front 안됨.
    std::queue<int, std::deque<int>> q3;

    q2.push(10); // vector의 push back 정상 동작.
    q2.front();  // 제거 아니라서 정상.
    q2.pop();    // queue의 pop은 container의 pop_front를 호출하는데, vector는 해당 함수가 없음.

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // -> 가장 작은 값
    pq.push(10);
    pq.push(-10);
    pq.push(-20);
    pq.push(20);
    pq.push(15);

    std::cout << pq.top() << std::endl;
    pq.pop();
    std::cout << pq.top() << std::endl;
}
