#pragma once

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