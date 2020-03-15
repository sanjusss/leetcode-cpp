#pragma once
#include "leetcode.h"

class Solution 
{
public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<TreeNode*> nodes;
        createArray(nodes, root);
        return createBST(nodes, 0, nodes.size() - 1);
    }

private:
    void createArray(vector<TreeNode*>& nodes, TreeNode* cur)
    {
        if (cur == nullptr)
        {
            return;
        }

        createArray(nodes, cur->left);
        nodes.push_back(cur);
        createArray(nodes, cur->right);
    }

    TreeNode* createBST(vector<TreeNode*>& nodes, int begin, int end)
    {
        if (begin > end)
        {
            return nullptr;
        }
        
        TreeNode* res = nullptr;
        int mid = (begin + end) / 2;
        res = nodes[mid];
        res->left = createBST(nodes, begin, mid - 1);
        res->right = createBST(nodes, mid + 1, end);
        return res;
    }
};