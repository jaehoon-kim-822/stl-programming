#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <fstream>

int main()
{
    std::ofstream fout("a.txt");
    std::ostream_iterator<int> p(fout, " ");
    *p = 100; // write 100 into a.txt
    std::list<int> s = {1, 2, 3};
    std::copy(s.begin(), s.end(), p);
}