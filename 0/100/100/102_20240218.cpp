/*
 * @Author: sanjusss
 * @Date: 2024-02-18 12:03:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-02-18 12:06:21
 * @FilePath: \0\100\100\102_20240218.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            auto& row = ans.emplace_back();
            for (int qi = q.size(); qi > 0; --qi) {
                auto node = q.front();
                q.pop();
                if (!node) {
                    continue;
                }

                row.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }

            if (row.empty()) {
                ans.pop_back();
                break;
            }
        }

        return ans;
    }
};