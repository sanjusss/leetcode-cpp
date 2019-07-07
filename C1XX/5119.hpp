#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        if (root == nullptr)
        {
            return vector<TreeNode*>();
        }

        set<int> removes(to_delete.begin(), to_delete.end());
        queue<pair<TreeNode*, TreeNode*>> q({ { nullptr, root } });
        vector<TreeNode*> trees;
        set<TreeNode*> deletedNodes({ nullptr });
        while (q.empty() == false)
        {
            auto parent = q.front().first;
            auto node = q.front().second;
            q.pop();

            if (removes.find(node->val) != removes.end())
            {
                deletedNodes.insert(node);
                if (parent != nullptr)
                {
                    if (parent->left == node)
                    {
                        parent->left = nullptr;
                    }
                    else
                    {
                        parent->right = nullptr;
                    }
                }
            }
            else if (deletedNodes.find(parent) != deletedNodes.end())
            {
                trees.push_back(node);
            }

            if (node->left != nullptr)
            {
                q.push({ node, node->left });
            }

            if (node->right != nullptr)
            {
                q.push({ node, node->right });
            }
        }

        return trees;
    }
};