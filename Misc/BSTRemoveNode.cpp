#include "TreeNode.h"

namespace clock18
{
TreeNode* removeNode(TreeNode* root, int value) {
    if (root == nullptr)
        return nullptr;

    if (root->m_val == value)
    {
        if (root->m_right != nullptr)
        {
            auto temp = root->m_right;
            // find the least node in the m_right sub tree.
            if (temp->m_left == nullptr)
            {
                // it is the m_right child.
                temp->m_left = root->m_left;
                root->m_right = nullptr;
                return temp;
            }
            else
            {
                while (temp->m_left != nullptr && temp->m_left->m_left != nullptr)
                {
                    temp = temp->m_left;
                }

                // temp->m_left is the least node.
                // newRoot still can have a right subtree.
                auto newRoot = temp->m_left;
                temp->m_left = newRoot->m_right;
                newRoot->m_left = root->m_left;
                root->m_left = nullptr;
                newRoot->m_right = root->m_right;
                root->m_right = nullptr;
                return newRoot;
            }
        }
        else if (root->m_left != nullptr)
        {
            // we know that the m_right sub tree is empty.
            auto temp = root->m_left;
            root->m_left = nullptr;
            return temp;
        }
        else
        {
            // the node is the only node in the tree.
            return nullptr;
        }
    }

    if (root->m_val < value)
    {
        root->m_right = removeNode(root->m_right, value);
    }
    else
    {
        root->m_left = removeNode(root->m_left, value);
    }
    return root;
}
}