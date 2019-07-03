#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int closestValue(TreeNode* root, double target)
    {
        double left = INFINITY;
        double right = INFINITY;
        auto head = root;
        while (head != nullptr)
        {
            if (target > head->val)
            {
                left = head->val;
                head = head->right;
            }
            else
            {
                right = head->val;
                head = head->left;
            }
        }

        if (left == INFINITY)
        {
            return right;
        }
        else if (right == INFINITY)
        {
            return left;
        }
        if (target - left < right - target)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
};