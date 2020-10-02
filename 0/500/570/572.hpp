#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        return isSubtree(s, t, true);
    }

private:
    bool isSubtree(TreeNode* s, TreeNode* t, bool tTop)
    {
        if (s == nullptr)
        {
            return t == nullptr;
        }

        if (t == nullptr)
        {
            return false;
        }

        if (s->val == t->val &&
            isSubtree(s->left, t->left, false) &&
            isSubtree(s->right, t->right, false))
        {
            return true;
        }

        if (tTop)
        {
            return isSubtree(s->left, t, true) || isSubtree(s->right, t, true);
        }
        else
        {
            return false;
        }
    }
};