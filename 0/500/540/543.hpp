#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int diameterOfBinaryTree(TreeNode* root) 
//    {
//        return search(root).first;
//    }
//
//private:
//    pair<int, int> search(TreeNode* node)
//    {
//        if (node == nullptr)
//        {
//            return { 0, 0 };
//        }
//
//        auto left = search(node->left);
//        auto right = search(node->right);
//        return { max({ left.first, right.first, left.second + right.second }),  max(left.second, right.second) + 1 };
//    }
//};

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        m_ans = 0;
        search(root);
        return m_ans;
    }

private:
    int search(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int left = search(node->left);
        int right = search(node->right);
        m_ans = max(m_ans, left + right);
        return max(left, right) + 1;
    }

    int m_ans =0;
};