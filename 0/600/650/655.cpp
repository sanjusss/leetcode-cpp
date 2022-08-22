/*
 * @Author: sanjusss
 * @Date: 2022-08-22 09:01:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-22 09:14:43
 * @FilePath: \0\600\650\655.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            ++height;
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }

        vector<int> pow2(height + 1);
        pow2[0] = 1;
        for (int i = 1; i <= height; ++i) {
            pow2[i] = pow2[i - 1] * 2;
        }

        vector<vector<string>> ans(height, vector<string>(pow2[height] - 1));
        queue<pair<TreeNode*, int>> row;
        row.emplace(root, pow2[height - 1] - 1);
        for (int r = 0; !row.empty(); ++r) {
            for (int i = row.size(); i > 0; --i) {
                auto [node, c] = row.front();
                row.pop();
                ans[r][c] = to_string(node->val);
                if (node->left != nullptr) {
                    row.emplace(node->left, c - pow2[height - r - 2]);
                }
                
                if (node->right != nullptr) {
                    row.emplace(node->right, c + pow2[height - r - 2]);
                }
            }
        }

        return ans;
    }
};