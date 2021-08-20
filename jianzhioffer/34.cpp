/*
 * @Author: sanjusss
 * @Date: 2021-08-20 08:27:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-20 08:38:22
 * @FilePath: \jianzhioffer\34.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(TreeNode*, int)> dfs = [&ans, &cur, &dfs, target](TreeNode* node, int sum) {
            cur.push_back(node->val);
            sum += node->val;
            if (node->left == nullptr && node->right == nullptr) {
                if (sum == target) {
                    ans.push_back(cur);
                }
            }
            else {
                if (node->left != nullptr) {
                    dfs(node->left, sum);
                }

                if (node->right != nullptr) {
                    dfs(node->right, sum);
                }
            }

            sum -= node->val;
            cur.pop_back();
        };

        if (root != nullptr) {
            dfs(root, 0);
        }

        return ans;
    }
};