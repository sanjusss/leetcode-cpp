#pragma once
#include "leetcode.h"

class Solution 
{
    int64_t mod = 1000000007;

public:
    int sumRootToLeaf(TreeNode* root) 
    {
        return (int)sumRootToLeaf(root, 0);
    }

    int64_t sumRootToLeaf(TreeNode* node, int64_t pre)
    {
        pre = ((pre << 1) + (int64_t)node->val) % mod;
        int64_t res = 0;
        if (node->left != nullptr)
        {
            res += sumRootToLeaf(node->left, pre);
        }

        if (node->right != nullptr)
        {
            res += sumRootToLeaf(node->right, pre);
        }

        if (res == 0)
        {
            res = pre;
        }

        return res % mod;
    }
};