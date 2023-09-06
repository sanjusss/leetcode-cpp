/*
 * @Author: sanjusss
 * @Date: 2023-09-06 08:32:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-06 08:51:22
 * @FilePath: \1000\1100\1120\1123.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        unordered_map<TreeNode*, TreeNode*> parents;
        unordered_set<TreeNode*> pre;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            pre.clear();
            for (int qi = q.size(); qi > 0; --qi) {
                TreeNode* node = q.front();
                q.pop();
                pre.insert(node);

                if (node->left != nullptr) {
                    parents[node->left] = node;
                    q.push(node->left);
                }
                
                if (node->right != nullptr) {
                    parents[node->right] = node;
                    q.push(node->right);
                }
            }
        }

        while (pre.size() > 1) {
            unordered_set<TreeNode*> cur;
            swap(cur, pre);
            for (auto node : cur) {
                pre.insert(parents[node]);
            }
        }

        return *(pre.begin());
    }
};