/*
 * @Author: sanjusss
 * @Date: 2023-05-22 09:13:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-22 09:28:42
 * @FilePath: \1000\1000\1080\1080.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        function<int(TreeNode*, int)> dfs = [limit, &dfs](TreeNode* node, int parent) -> int {
            int cur = parent + node->val;
            if (node->left == nullptr && node->right == nullptr) {
                return node->val;
            }
            else if (node->left == nullptr) {
                int sum = dfs(node->right, cur);
                if (sum + cur < limit) {
                    node->right = nullptr;
                }

                return node->val + sum;
            }
            else if (node->right == nullptr) {
                int sum = dfs(node->left, cur);
                if (sum + cur < limit) {
                    node->left = nullptr;
                }

                return node->val + sum;
            }
            else {
                int left = dfs(node->left, cur);
                if (left + cur < limit) {
                    node->left = nullptr;
                }

                int right = dfs(node->right, cur);
                if (right + cur < limit) {
                    node->right = nullptr;
                }

                return max(left, right) + node->val;
            }
        };
        if (dfs(root, 0) >= limit) {
            return root;
        }
        else {
            return nullptr;
        }
    }
};