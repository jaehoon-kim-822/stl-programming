template <typename T>
class List
{
public:
    void push_front(const T &a)
    {
    }
};

List<int> st; // 전역변수는 멀티스레드 환경에서 안전하지 않음.

int main()
{
    st.push_front(10);
}