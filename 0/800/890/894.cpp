/*
 * @Author: sanjusss
 * @Date: 2024-04-02 08:41:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-04-02 09:49:18
 * @FilePath: \0\800\890\894.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }

        vector<vector<TreeNode*>> dp(n + 1);
        dp[1].push_back(new TreeNode(0));
        for (int i = 3; i <= n; i += 2) {
            int sum = i - 1;
            for (int j = 1; j < sum; j += 2) {
                int k = sum - j;
                for (auto dj : dp[j]) {
                    for (auto dk : dp[k]) {
                        TreeNode* node = new TreeNode(0);
                        node->left = dj;
                        node->right = dk;
                        dp[i].push_back(node);
                    }
                }
            }
        }

        return dp[n];
    }
};