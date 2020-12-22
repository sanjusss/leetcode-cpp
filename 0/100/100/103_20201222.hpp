#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        deque<TreeNode*> q;
        if (root != nullptr) {
            q.push_back(root);
        }

        bool left2right = true;
        while (!q.empty()) {
            vector<int> row;
            if (left2right) {
                for (int i = q.size(); i > 0; --i) {
                    TreeNode* node = q.front();
                    q.pop_front();
                    row.emplace_back(node->val);
                    if (node->left != nullptr) {
                        q.push_back(node->left);
                    }

                    if (node->right != nullptr) {
                        q.push_back(node->right);
                    }
                }
            }
            else {
                for (int i = q.size(); i > 0; --i) {
                    TreeNode* node = q.back();
                    q.pop_back();
                    row.emplace_back(node->val);
                    if (node->right != nullptr) {
                        q.push_front(node->right);
                    }

                    if (node->left != nullptr) {
                        q.push_front(node->left);
                    }
                }
            }

            ans.emplace_back(move(row));
            left2right = !left2right;
        }

        return ans;
    }
};