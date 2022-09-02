/*
 * @Author: sanjusss
 * @Date: 2022-09-02 08:20:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-02 08:39:33
 * @FilePath: \0\600\680\687.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            int left = 0;
            int right = 0;
            if (node->left != nullptr) {
                int child = dfs(node->left);
                if (node->left->val == node->val) {
                    left = child;
                }
            }

            if (node->right != nullptr) {
                int child = dfs(node->right);
                if (node->right->val == node->val) {
                    right = child;
                }
            }

            ans = max(ans, 1 + left + right);
            return max(1 + left, 1 + right);
        };
        dfs(root);
        return ans - 1;
    }
};