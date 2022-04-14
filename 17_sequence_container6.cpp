#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>
#include "show.h"

class FindChar
{
    std::string data;

public:
    FindChar(const std::string &s) : data(s) {}
    inline bool operator()(const char &c) const
    {
        return std::find(data.begin(), data.end(), c) != data.end();
    }
};

int main()
{
    std::vector<std::string> v;
    std::ifstream f("3_선형컨테이너6.cpp"); // current file name

    std::string s;

    while (std::getline(f, s))
        v.push_back(s);

    //----------------------------

    std::reverse(v.begin(), v.end());

    for (auto &n : v)
        std::cout << n << std::endl;

    //----------------------------

    std::reverse(v[0].begin(), v[0].end());

    for (auto &n : v)
        std::cout << n << std::endl;

    //----------------------------

    for (auto &e : v)
    {
        std::reverse(e.begin(), e.end());
    }

    for (auto &n : v)
        std::cout << n << std::endl;

    //----------------------------

    for (auto &e : v)
    {
        std::reverse(e.begin(), e.end());
    }

    for (auto &n : v)
        std::cout << n << std::endl;

    //----------------------------

    for (auto &e : v)
    {
        std::replace(e.begin(), e.end(), 'i', ' ');
    }

    for (auto &n : v)
        std::cout << n << std::endl;

    //----------------------------

    for (auto &e : v)
    {
        std::replace_if(
            e.begin(), e.end(), [](char c)
            { return c == 'a' || c == 'e'; },
            " ");
    }

    for (auto &n : v)
        std::cout << n << std::endl;

    //----------------------------

    for (auto &e : v)
    {
        FindChar fc("aeiouAEIOU");
        std::replace_if(e.begin(), e.end(), fc, " ");
    }

    for (auto &n : v)
        std::cout << n << std::endl;
}