/*
 * @Author: sanjusss
 * @Date: 2022-08-30 08:21:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-30 08:27:15
 * @FilePath: \0\900\990\998.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* ins = new TreeNode(val);
        if (root->val < val) {
            ins->left = root;
            return ins;
        }

        TreeNode* node = root;
        while (node->right != nullptr && node->right->val > val) {
            node = node->right;
        }

        ins->left = node->right;
        node->right = ins;

        return node;
    }
};