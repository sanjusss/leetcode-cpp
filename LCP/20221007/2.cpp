/*
 * @Author: sanjusss
 * @Date: 2022-10-07 14:58:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-07 15:03:34
 * @FilePath: \LCP\20221007\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* expandBinaryTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.emplace(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node->left != nullptr) {
                s.emplace(node->left);
                TreeNode* tmp = new TreeNode(-1);
                tmp->left = node->left;
                node->left = tmp;
            }
            if (node->right != nullptr) {
                s.emplace(node->right);
                TreeNode* tmp = new TreeNode(-1);
                tmp->right = node->right;
                node->right = tmp;
            }
        }

        return root;
    }
};