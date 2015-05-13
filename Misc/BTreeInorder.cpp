#include "TreeNode.h"
#include <stack>

using namespace clock18;

class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        while (root != nullptr)
        {
            m_stack.push(root);
            root = root->m_left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return !m_stack.empty();
        // write your code here
    }

    //@return: return next node
    TreeNode* next() {
        if (!hasNext())
            return nullptr;

        auto temp = m_stack.top();
        m_stack.pop();
        // write your code here
        curr = temp->m_right;
        while (curr != nullptr)
        {
            m_stack.push(curr);
            curr = curr->m_left;
        }
        return temp;
    }
private:
    TreeNode* curr;
    std::stack<TreeNode*> m_stack;
};