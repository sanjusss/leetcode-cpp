/*
 * @Author: sanjusss
 * @Date: 2022-02-11 14:02:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-11 14:06:30
 * @FilePath: \0\200\250\250.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        function<bool(TreeNode*, TreeNode*)> dfs = [&ans, &dfs] (TreeNode* node, TreeNode* parent) -> bool {
            if (node == nullptr) {
                return true;
            }

            bool left = dfs(node->left, node);
            bool right = dfs(node->right, node);
            if (left && right) {
                ++ans;
            }

            return left && right && parent != nullptr && node->val == parent->val;
        };

        dfs(root, nullptr);
        return ans;
    }
};