#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include "show.h"

int main()
{
    std::map<std::string, std::list<int>> indexMap;
    std::ifstream f("readme.txt");

    int line = 0;
    std::string s;

    while (std::getline(f, s))
    {
        ++line;
        std::istringstream iss(s);
        std::string word;
        while (iss >> word)
        {
            // key가 없으면, pair를 생성하고, value를 반환.
            // key가 있으면, value 반환.
            indexMap[word].push_back(line);
        }
    }

    for (auto &p : indexMap)
    {
        std::cout << p.first << ": ";
        show(p.second);
    }
}
