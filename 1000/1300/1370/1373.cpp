/*
 * @Author: sanjusss
 * @Date: 2023-05-20 17:00:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-20 17:13:39
 * @FilePath: \1000\1300\1370\1373.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        struct Result {
            bool isBST;
            int sum;
            int minVal;
            int maxVal;
        };
        int ans = 0;
        function<Result(TreeNode*)> dfs = [&ans, &dfs] (TreeNode* node) -> Result {
            Result res;
            res.isBST = true;
            res.sum = node->val;
            res.minVal = node->val;
            res.maxVal = node->val;
            if (node->left) {
                auto left = dfs(node->left);
                if (left.isBST && left.maxVal < node->val) {
                    res.minVal = left.minVal;
                    res.sum += left.sum;
                }
                else {
                    res.isBST = false;
                }
            }

            if (node->right) {
                auto right = dfs(node->right);
                if (right.isBST && right.minVal > node->val) {
                    res.maxVal = right.maxVal;
                    res.sum += right.sum;
                }
                else {
                    res.isBST = false;
                }
            }

            if (res.isBST) {
                ans = max(ans, res.sum);
            }

            return res;
        };
        dfs(root);
        return ans;
    }
};