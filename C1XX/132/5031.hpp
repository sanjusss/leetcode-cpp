#pragma once
#include "leetcode.h"

class Solution 
{
public:
    TreeNode* recoverFromPreorder(string S) 
    {
        int length = S.length();
        int floor = 0;
        vector<vector<TreeNode*>> tree;
        for (int i = 0; i < length; ++i)
        {
            if (S[i] == '-')
            {
                ++floor;
            }
            else
            {
                int j = i;
                int n = 0;
                while (isdigit(S[j]))
                {
                    n = 10 * n + (S[j] - '0');
                    ++j;
                }

                TreeNode* node = new TreeNode(n);
                if (tree.size() <= floor)
                {
                    tree.push_back(vector<TreeNode*>({ node }));
                }
                else
                {
                    tree[floor].push_back(node);
                }

                if (floor > 0)
                {
                    auto p = tree[floor - 1][tree[floor - 1].size() - 1];
                    if (p->left == nullptr)
                    {
                        p->left = node;
                    }
                    else
                    {
                        p->right = node;
                    }
                }

                i = j - 1;
                floor = 0;
            }
        }

        return tree[0][0];
    }
};