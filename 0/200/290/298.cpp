/*
 * @Author: sanjusss
 * @Date: 2022-07-01 16:22:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-01 16:31:31
 * @FilePath: \0\200\290\298.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<tuple<TreeNode*, int>> q;
        int ans = 0;
        q.emplace(root, 0);
        while (!q.empty()) {
            auto [node, len] = q.front();
            q.pop();
            ans = max(ans, ++len);
            if (node->left != nullptr) {
                q.emplace(node->left, node->left->val == node->val + 1 ? len : 0);
            }

            if (node->right != nullptr) {
                q.emplace(node->right, node->right->val == node->val + 1 ? len : 0);
            }
        }

        return ans;
    }
};