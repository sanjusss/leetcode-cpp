/*
 * @Author: sanjusss
 * @Date: 2022-09-24 17:00:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-25 12:13:42
 * @FilePath: \LCP\20220924\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int closeLampInTree(TreeNode* root) {
        map<tuple<TreeNode*, int, int>, int> dp;
        function<int(TreeNode*, int, int)> dfs = [&](TreeNode* node, int sw2, int sw3) -> int {
            if (node == nullptr) {
                return 0;
            }

            auto key = make_tuple(node, sw2, sw3);
            if (dp.count(key)) {
                return dp[key];
            }

            int cur = (node->val + sw2 + sw3) % 2;
            int ans;
            if (cur == 1) {  // 当前灯亮
                // 1、2、3、123
                int r1 = dfs(node->left, sw2, 0) + dfs(node->right, sw2, 0) + 1;
                int r2 = dfs(node->left, (sw2 + 1) % 2, 0) + dfs(node->right, (sw2 + 1) % 2, 0) + 1;
                int r3 = dfs(node->left, sw2, 1) + dfs(node->right, sw2, 1) + 1;
                int r123 = dfs(node->left, (sw2 + 1) % 2, 1) + dfs(node->right, (sw2 + 1) % 2, 1) + 3;
                ans = min({ r1, r2, r3, r123 });
            }
            else {
                // 无、12、13、23
                int r = dfs(node->left, sw2, 0) + dfs(node->right, sw2, 0);
                int r12 = dfs(node->left, (sw2 + 1) % 2, 0) + dfs(node->right, (sw2 + 1) % 2, 0) + 2;
                int r13 = dfs(node->left, sw2, 1) + dfs(node->right, sw2, 1) + 2;
                int r23 = dfs(node->left, (sw2 + 1) % 2, 1) + dfs(node->right, (sw2 + 1) % 2, 1) + 2;
                ans = min({ r, r12, r13, r23 });
            }

            dp[key] = ans;
            return ans;
        };
        return dfs(root, 0, 0);
    }
};