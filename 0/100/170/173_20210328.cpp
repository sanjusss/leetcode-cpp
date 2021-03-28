/*
 * @Author: sanjusss
 * @Date: 2021-03-28 11:55:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-28 12:01:14
 * @FilePath: \0\100\170\173_20210328.cpp
 */
#include "leetcode.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root != nullptr) {
            m_s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* node = m_s.top();
        m_s.pop();
        int val = node->val;
        node = node->right;
        while (node != nullptr) {
            m_s.push(node);
            node = node->left;
        }

        return val;
    }
    
    bool hasNext() {
        return !m_s.empty();
    }

private:
    stack<TreeNode*> m_s;
};