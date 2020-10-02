#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode*> results;
        if (root == nullptr)
        {
            return results;
        }

        passSubtrees(root);
        for (auto i : m_trees)
        {
            if (i.second.size() >= 2)
            {
                results.push_back(i.second[0]);
            }
        }

        return results;
    }

private:
    string passSubtrees(TreeNode* node)
    {
        string key = to_string(node->val);
        key += ",";
        if (node->left == nullptr)
        {
            key += "null";
        }
        else
        {
            key += passSubtrees(node->left);
        }

        key += ",";
        if (node->right == nullptr)
        {
            key += "null";
        }
        else
        {
            key += passSubtrees(node->right);
        }

        m_trees[key].push_back(node);
        return key;
    }

    map<string, vector<TreeNode*>> m_trees;
};