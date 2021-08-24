/*
 * @Author: sanjusss
 * @Date: 2021-08-24 09:25:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-24 09:30:04
 * @FilePath: \jianzhioffer\68-2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) {
            return right;
        }
        else if (right == nullptr) {
            return left;
        }
        else {
            return root;
        }
    }
};