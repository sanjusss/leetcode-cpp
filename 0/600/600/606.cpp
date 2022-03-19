/*
 * @Author: sanjusss
 * @Date: 2022-03-19 16:20:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-19 16:33:38
 * @FilePath: \0\600\600\606.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string tree2str(TreeNode* root) {
        string ans;
        function<void(TreeNode*)> dfs = [&dfs, &ans](TreeNode* node) {
            ans += to_string(node->val);
            if (node->left == nullptr && node->right == nullptr) {
                return;
            }

            ans += "("s;
            if (node->left != nullptr) {
                dfs(node->left);
            }
            ans += ")"s;

            if (node->right != nullptr) {
                ans += "("s;
                dfs(node->right);
                ans += ")"s;
            }
        };

        if (root == nullptr) {
            return "()";
        }

        dfs(root);
        return ans;
    }
};