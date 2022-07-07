/*
 * @Author: sanjusss
 * @Date: 2022-07-07 08:56:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-07 09:36:20
 * @FilePath: \0\300\330\333.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int ans = 1;
        function<tuple<bool, int, int, int>(TreeNode*)> dfs = [&](TreeNode* node) -> tuple<bool, int, int, int> {
            int len = 1;
            bool res = true;
            int minVal = node->val;
            int maxVal = node->val;
            if (node->left != nullptr) {
                auto [cres, clen, cmin, cmax] = dfs(node->left);
                if (cres && cmax < node->val) {
                    minVal = cmin;
                    len += clen;
                }
                else {
                    res = false;
                }
            }

            if (node->right != nullptr) {
                auto [cres, clen, cmin, cmax] = dfs(node->right);
                if (cres && cmin > node->val) {
                    maxVal = cmax;
                    len += clen;
                }
                else {
                    res = false;
                }
            }

            if (res) {
                ans = max(ans, len);
            }

            return make_tuple(res, len, minVal, maxVal);
        };
        dfs(root);
        return ans;
    }
};

TEST(&Solution::largestBSTSubtree)