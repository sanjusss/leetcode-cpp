/*
 * @Author: sanjusss
 * @Date: 2023-02-16 08:58:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-16 09:08:40
 * @FilePath: \0\500\540\549.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        // return +1, -1
        function<pair<int, int>(TreeNode*, int)> dfs = [&ans, &dfs](TreeNode* node, int parent) -> pair<int, int> {
            if (node == nullptr) {
                return { 0, 0 };
            }

            auto left = dfs(node->left, node->val);
            auto right = dfs(node->right, node->val);
            ans = max(ans, 1 + max(left.first + right.second, left.second + right.first));
            if (node->val == parent + 1) {
                return { 1 + max(left.first, right.first), 0 };
            }
            else if (node->val == parent - 1) {
                return { 0, 1 + max(left.second, right.second) };
            }
            else {
                return { 0, 0 };
            }
        };
        dfs(root, 0);
        return ans;
    }
};