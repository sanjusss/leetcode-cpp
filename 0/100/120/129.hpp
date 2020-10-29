#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     int sumNumbers(TreeNode* root) {
//         if (root == nullptr) {
//             return 0;
//         }
//         else {
//             return dfs(root, 0);
//         }
//     }

// private:
//     int dfs(TreeNode* node, int prev) {
//         prev = prev * 10 + node->val;
//         if (node->left == nullptr && node->right == nullptr) {
//             return prev;
//         }
//         else if (node->left == nullptr) {
//             return dfs(node->right, prev);
//         }
//         else if (node->right == nullptr) {
//             return dfs(node->left, prev);
//         }
//         else {
//             return dfs(node->left, prev) + dfs(node->right, prev);
//         }
//     }
// };

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        do {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int prev = p.second * 10 + node->val;
            if (node->left == nullptr && node->right == nullptr) {
                ans += prev;
            }
            else {
                if (node->left != nullptr) {
                    q.emplace(node->left, prev);
                }

                if (node->right != nullptr) {
                    q.emplace(node->right, prev);
                }
            }
        } while (!q.empty());

        return ans;
    }
};