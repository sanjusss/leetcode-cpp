#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> eles;
        initVector(root1, eles);
        initVector(root2, eles);
        sort(eles.begin(), eles.end());
        return eles;
    }

private:
    void initVector(TreeNode* root, vector<int>& eles)
    {
        if (root == nullptr)
        {
            return;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (q.empty() == false)
        {
            auto node = q.front();
            q.pop();
            eles.push_back(node->val);

            if (node->left != nullptr)
            {
                q.push(node->left);
            }

            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
    }
};