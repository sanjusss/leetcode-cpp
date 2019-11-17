#pragma once
#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements 
{
public:
    FindElements(TreeNode* root) 
    {
        m_root = root;
        root->val = 0;
        m_set.insert(0);
        initNode(root);
    }

    bool find(int target) 
    {
        return m_set.find(target) != m_set.end();
    }

private:
    void initNode(TreeNode* node)
    {
        if (node->left != nullptr)
        {
            node->left->val = 2 * node->val + 1;
            m_set.insert(node->left->val);
            initNode(node->left);
        }

        if (node->right != nullptr)
        {
            node->right->val = 2 * node->val + 2;
            m_set.insert(node->right->val);
            initNode(node->right);
        }
    }

private:
    TreeNode* m_root = nullptr;
    set<int> m_set;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */