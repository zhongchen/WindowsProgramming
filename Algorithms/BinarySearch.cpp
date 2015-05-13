#include "BinarySearch.h"
#include <cstdint>
#include <tuple>
#include <vector>

using namespace clock18;

char FindCharInCharArray::FindChar(char target)
{
    if (target < m_data[0])
        return m_data[0];

    if (target >= m_data[m_data.size() - 1])
        return m_data[0];

    auto beg = 0;
    auto end = static_cast<std::int32_t>(m_data.size() - 1);

    while (beg < end)
    {
        auto mid = beg + (end - beg) / 2;
        if (m_data[mid] == target)
            return m_data[mid + 1];

        if (m_data[mid] < target)
        {
            beg = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    return m_data[beg] > target ? m_data[beg] : m_data[beg + 1];
}


std::tuple<int, int> FindTargetInMatrix::Find(std::vector<std::vector<int>>& vec, int target) const
{
    if (vec.empty() || vec[0].empty())
        return std::tuple<int, int>(-1, -1);
    auto rows = vec.size();
    auto cols = vec[0].size();

    if (target < vec[0][0] || target > vec[rows - 1][cols - 1])
        return std::tuple<int, int>(-1, -1);

    int start = 0;
    int end = rows - 1;

    while (start < end)
    {
        auto mid = start + (end - start) / 2;
        if (vec[mid][0] == target)
            return std::tuple<int, int>(mid, 0);
        else if (vec[mid][0] < target)
            start = mid + 1;
        else
            end = mid;
    }

    int rowIndex = 0;
    if (vec[start][0] > target)
        rowIndex = start - 1;
    else if (vec[start][0] < target)
        rowIndex = start;
    else
        return std::tuple<int, int>(start, 0);

    start = 0;
    end = cols - 1;
    while (start < end)
    {
        auto mid = start + (end - start) / 2;
        if (vec[rowIndex][mid] == target)
            return std::tuple<int, int>(rowIndex, mid);
        else if (vec[rowIndex][mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    if (vec[rowIndex][start] > target || vec[rowIndex][start] < target)
        return std::tuple<int, int>(-1, -1);
    else
        return std::tuple<int, int>(rowIndex, start);
}

void FindTargetInMatrix::Test() const 
{
    std::vector<std::vector<int>> data{ { 1, 2, 3, 5 }, { 6, 7, 10, 11 } };
    auto result = Find(data, static_cast<int>(1));
    result = Find(data, 8);
    result = Find(data, 11);
    result = Find(data, 5);
    result = Find(data, 6);
    result = Find(data, 0);
    result = Find(data, 120);
}


