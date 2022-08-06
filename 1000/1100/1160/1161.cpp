/*
 * @Author: sanjusss
 * @Date: 2022-07-31 08:48:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-31 08:53:25
 * @FilePath: \1000\1100\1160\1161.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ans = -1;
        queue<TreeNode*> q;
        q.push(root);
        for (int row = 1; !q.empty(); ++row) {
            int sum = 0;
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            if (sum > maxSum) {
                ans = row;
                maxSum = sum;
            }
        }

        return ans;
    }
};