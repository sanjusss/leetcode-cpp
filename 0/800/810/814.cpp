/*
 * @Author: sanjusss
 * @Date: 2022-07-21 08:12:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-21 08:13:48
 * @FilePath: \0\800\810\814.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        } 

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        else {
            return root;
        }
    }
};