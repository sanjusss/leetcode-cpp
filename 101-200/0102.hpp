#pragma once
#include "leetcode.h"

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> levels;
        list<TreeNode*> s;
        s.push_back(root);
        do
        {
            list<TreeNode*> next;
            vector<int> level;
            for (auto i : s)
            {
                if (i == nullptr)
                {
                    continue;
                }

                level.push_back(i->val);
                next.push_back(i->left);
                next.push_back(i->right);
            }

            if (level.empty() == false)
            {
                levels.push_back(level);
            }

            s.swap(next);
        } while (s.empty() == false);
        return levels;
    }
};