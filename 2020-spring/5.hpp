#pragma once
#include "leetcode.h"

class Solution 
{
public:
    double minimalExecTime(TreeNode* root) 
    {
        if (root == nullptr)
        {
            return 0;
        }

        double ans = root->val;
        if (root->left == nullptr || root->right == nullptr)
        {
            ans += minimalExecTime(root->left);
            ans += minimalExecTime(root->right);
        }
        else
        {
            //double left = 
        }

        return ans;
    }
};