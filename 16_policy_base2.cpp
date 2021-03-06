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

template <typename T>
struct debug_alloc
{
    T *allocate(std::size_t size)
    {
        T *ptr = static_cast<T *>(malloc(sizeof(T) * size));
        printf("%d allocated at %p\n", size, ptr);
        return ptr;
    }

    void deallocate(T *ptr, int size)
    {
        free(ptr);
        printf("%d deallocated at %p\n", size, ptr);
    }

    debug_alloc() {}
    using value_type = T;
    template <typename U>
    debug_alloc(const U &) {}
};

int main()
{
    std::vector<int> v(5);
    std::vector<int, debug_alloc<int>> v(5);
    v.resize(10);
}
