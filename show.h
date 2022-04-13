template <typename Container>
void show(const Container &c)
{
    for (auto &e : c)
    {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

template <typename InputIter>
void show(InputIter first, InputIter last)
{
    // raw pointer와 iterator 모두 지원.
    std::ostream_iterator<typename std::iterator_traits<InputIter>::value_type> p(std::cout, " ");
    std::copy(first, last, p);
    std::cout << std::endl;
}