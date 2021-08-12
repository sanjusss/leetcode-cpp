/*
 * @Author: sanjusss
 * @Date: 2021-08-12 10:15:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-12 10:24:26
 * @FilePath: \jianzhioffer\28.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        stack<pair<TreeNode*, TreeNode*>> s;
        s.emplace(root->left, root->right);
        while (!s.empty()) {
            auto [a, b] = s.top();
            s.pop();
            if (a == nullptr && b == nullptr) {
                continue;
            }
            else if (a == nullptr || b == nullptr || a->val != b->val) {
                return false;
            }

            s.emplace(a->left, b->right);
            s.emplace(a->right, b->left);
        }

        return true;
    }
};