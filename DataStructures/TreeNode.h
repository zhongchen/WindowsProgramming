#pragma once
#include <cstdint>

namespace clock18
{

class TreeNode {
public:
    TreeNode(std::int32_t val)
        : m_val(val),
        m_left(nullptr),
        m_right(nullptr)
    {}
    std::int32_t m_val;
    TreeNode *m_left;
    TreeNode *m_right;
};

}

