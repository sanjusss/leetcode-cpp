/*
 * @Author: sanjusss
 * @Date: 2023-02-03 08:25:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-03 08:36:21
 * @FilePath: \1000\1100\1140\1145.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<int> cnt(n + 1);
        TreeNode* xLeft = nullptr;
        TreeNode* xRight = nullptr;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }

            if (node->val == x) {
                xLeft = node->left;
                xRight = node->right;
            }

            return cnt[node->val] = dfs(node->left) + dfs(node->right) + 1;
        };

        dfs(root);
        int parent = n - cnt[x];
        int left = xLeft ? cnt[xLeft->val] : 0;
        int right = xRight ? cnt[xRight->val] : 0;
        return (left + right + 1 < parent) || (left + parent + 1 < right) || (right + parent + 1 < left);
    }
};