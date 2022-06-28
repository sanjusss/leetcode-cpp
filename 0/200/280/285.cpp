/*
 * @Author: sanjusss
 * @Date: 2022-06-28 08:41:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-28 08:51:56
 * @FilePath: \0\200\280\285.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        TreeNode* node = p->right == nullptr ? root : p->right;
        while (node != nullptr) {
            if (node->val <= p->val) {
                node = node->right;
            }
            else {
                ans = node;
                node = node->left;
            }
        }

        return ans;
    }
};