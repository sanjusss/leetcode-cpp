/*
 * @Author: sanjusss
 * @Date: 2021-08-12 10:12:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-12 10:14:09
 * @FilePath: \jianzhioffer\27.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            if (node == nullptr) {
                continue;
            }

            s.push(node->left);
            s.push(node->right);
            swap(node->left, node->right);
        }

        return root;
    }
};