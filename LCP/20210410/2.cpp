/*
 * @Author: sanjusss
 * @Date: 2021-04-10 14:45:49
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-10 16:21:57
 * @FilePath: \LCP\20210410\2.cpp
 */
#include "leetcode.h"

class Solution {
    struct InnerSolution {
        int maxValue(TreeNode* node, int remain) {
            if (node == nullptr) {
                return 0;
            }

            auto& dp = dps[remain];
            if (dp.find(node) != dp.end()) {
                return dp[node];
            }

            int res = maxValue(node->left, k) + maxValue(node->right, k);//不包括自己。
            //包括自己时，左右分配的值。
            for (int left = 0; left < remain; ++left) {
                res = max(res, node->val + maxValue(node->left, left) + maxValue(node->right, remain - 1 - left));
            }

            dp[node] = res;
            return res;
        }

        int k;
        vector<unordered_map<TreeNode*, int>> dps = vector<unordered_map<TreeNode*, int>>(11);
    };
    

public:
    int maxValue(TreeNode* root, int k) {
        InnerSolution sln;
        sln.k = k;
        return sln.maxValue(root, k);
    }
};