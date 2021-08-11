/*
 * @Author: sanjusss
 * @Date: 2021-08-11 10:55:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-11 10:56:52
 * @FilePath: \jianzhioffer\32-3.cpp
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

        bool needReverse = false;
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

            if (needReverse) {
                reverse(row.begin(), row.end());
            }

            ans.emplace_back(move(row));
            needReverse = !needReverse;
        }

        return ans;
    }
};