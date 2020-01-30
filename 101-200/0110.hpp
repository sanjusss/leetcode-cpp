#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    bool isBalanced(TreeNode* root) 
//    {
//        int h = 0;
//        return isBalanced(root, h);
//    }
//
//private:
//    bool isBalanced(TreeNode* node, int& height)
//    {
//        if (node == nullptr)
//        {
//            height = 0;
//            return true;
//        }
//
//        int lh = 0;
//        int rh = 0;
//        bool ans = isBalanced(node->left, lh) && isBalanced(node->right, rh) && abs(lh - rh) <= 1;
//        height = max(lh, rh) + 1;
//        return ans;
//    }
//};

class Solution
{
public:
    bool isBalanced(TreeNode* root)
    {
        return height(root) != -1;
    }

private:
    int height(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int lh = height(node->left);
        if (lh == -1)
        {
            return -1;
        }

        int rh = height(node->right);
        if (rh == -1)
        {
            return -1;
        }

        return abs(lh - rh) < 2 ? max(lh, rh) + 1 : -1;
    }
};