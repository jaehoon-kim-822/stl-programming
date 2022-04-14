// Policy base design 단위 전략 디자인
// 클래스가 사용하는 정책을 템플릿 인자를 통해 전달.

// 템플릿 인자로 전달되는 정책 클래스가 지켜야 할 규칙.
// 동일한 인터페이스
// 이런 규칙을 named requirement

// STL은 단위전략 디자인을 적극 사용 중.

template <typename T, typename ThreadModel = noLock>
class List
{
    ThreadModel tm;

public:
    void push_front(const T &a)
    {
        tm.lock();
        // ...
        tm.unlock();
    }
};

class mutexLock
{
public:
    inline void lock()
    {
        // pthread_acquire_mutex();
    }
    inline void unlock()
    {
        // pthread_release_mutex();
    }
};

class noLock
{
public:
    inline void lock() {}
    inline void unlock() {}
};

List<int, mutexLock> st;
List<int> stLockable;

int main()
{
    st.push_front(10);
    stLockable.push_front(10);
}