/*
 * @Author: sanjusss
 * @Date: 2021-08-23 08:39:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-23 08:43:42
 * @FilePath: \jianzhioffer\55-2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        function<int(TreeNode*)> dfs = [&dfs, &ans] (TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }

            int left = dfs(node->left);
            int right = dfs(node->right);
            if (abs(left - right) > 1) {
                ans = false;
            }

            return max(left, right) + 1;
        };

        dfs(root);
        return ans;
    }
};