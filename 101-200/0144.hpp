#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> s;
        s.push(root);
        vector<int> res;
        while (s.empty() == false)
        {
            auto node = s.top();
            s.pop();
            if (node == nullptr)
            {
                continue;
            }

            res.push_back(node->val);
            s.push(node->right);
            s.push(node->left);
        }

        return res;
    }
};