#include <vector>

template <typename T, typename Alloc = std::allocator<T>>
class vector
{
    alloc ax;

public:
    void resize(int sz)
    {
        T *buf = ax.allocate(sz);
        // maybe. need to copy data.
        ax.deallocate(buf, size);
    }
};

int main()
{
    std::vector<int> v(5);
    v.resize(10);
}
