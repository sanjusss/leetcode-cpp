/*
 * @Author: sanjusss
 * @Date: 2021-08-11 10:52:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-11 10:54:53
 * @FilePath: \jianzhioffer\32-2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }

        while (!q.empty()) {
            vector<int> row;
            row.reserve(q.size());
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();
                row.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            ans.emplace_back(move(row));
        }

        return ans;
    }
};