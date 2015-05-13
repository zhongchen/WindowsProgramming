#pragma once
#include <vector>
#include <tuple>

namespace clock18
{

class FindCharInCharArray
{
public:
    // Find the char in a sorted char array.
    FindCharInCharArray(std::vector<char> data)
        : m_data(std::move(data))
    {}

    char FindChar(char target);

private:
    std::vector<char> m_data;
};


class FindTargetInMatrix
{
public:
    // Example:
    // 1 2 3
    // 4 5 6
    std::tuple<int, int> Find(std::vector<std::vector<int>>& vec, int target) const;

    void Test() const;
};

}