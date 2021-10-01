/*
 * @Author: sanjusss
 * @Date: 2021-09-28 08:49:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-28 09:03:28
 * @FilePath: \0\400\430\437.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int64_t, int> cnt = { { (int64_t)0, 1 } };
        int ans = 0;
        function<void(TreeNode*, int64_t)> dfs = [&](TreeNode* node, int64_t cur) {
            if (node == nullptr) {
                return;
            }

            cur += node->val;
            if (cnt.count(cur - targetSum)) {
                ans += cnt[cur - targetSum];
            }

            ++cnt[cur];
            dfs(node->left, cur);
            dfs(node->right, cur);
            --cnt[cur];
        };

        dfs(root, 0);
        return ans;
    }
};

TEST(&Solution::pathSum)