#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxAncestorDiff(TreeNode* root) 
    {
        return maxAncestorDiff(root, INT_MIN, INT_MAX);
    }

private:
    int maxAncestorDiff(TreeNode* node, int maxa, int mina)
    {
        if (node == nullptr)
        {
            return INT_MIN;
        }

        maxa = max(maxa, node->val);
        mina = min(mina, node->val);
        int diff = maxa - mina;
        diff = max(diff, maxAncestorDiff(node->left, maxa, mina));
        diff = max(diff, maxAncestorDiff(node->right, maxa, mina));
        return diff;
    }
};