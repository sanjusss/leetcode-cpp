#pragma once
#include "leetcode.h"

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root->val == p->val || root->val == q->val)
        {
            return root;
        }

        if (root->val > p->val)
        {
            if (root->val > q->val)
            {
                return lowestCommonAncestor(root->left, p, q);
            }
            else
            {
                return root;
            }
        }
        else
        {
            if (root->val > q->val)
            {
                return root;
            }
            else
            {
                return lowestCommonAncestor(root->right, p, q);
            }
        }
    }
};