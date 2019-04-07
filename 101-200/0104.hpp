#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};