/*
 * @Author: sanjusss
 * @Date: 2023-04-18 08:41:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-18 08:46:52
 * @FilePath: \1000\1000\1020\1026.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        function<pair<int, int>(TreeNode*)> dfs = [&ans, &dfs] (TreeNode* node) -> pair<int, int> {
            int minV = node->val;
            int maxV = node->val;
            if (node->left != nullptr) {
                auto [i, a] = dfs(node->left);
                minV = min(i, minV);
                maxV = max(a, maxV);
            }

            if (node->right != nullptr) {
                auto [i, a] = dfs(node->right);
                minV = min(i, minV);
                maxV = max(a, maxV);
            }

            ans = max(ans, abs(node->val - minV));
            ans = max(ans, abs(node->val - maxV));
            return { minV, maxV };
        };
        dfs(root);
        return ans;
    }
};