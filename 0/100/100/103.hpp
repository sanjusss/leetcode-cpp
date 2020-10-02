#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool insertFront = false;
        while (q.empty() == false)
        {
            queue<TreeNode*> next;
            vector<int> row;
            while (q.empty() == false)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node == nullptr)
                {
                    continue;
                }
                    
                row.push_back(node->val);
                next.push(node->left);
                next.push(node->right);
            }
            
            if (row.empty() == false)
            {
                if (insertFront)
                {
                    ans.push_back(vector<int>(row.rbegin(), row.rend()));
                }
                else
                {
                    ans.push_back(row);
                }
            }

            q.swap(next);
            insertFront = !insertFront;
        }

        return ans;
    }
};