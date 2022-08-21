/*
 * @Author: sanjusss
 * @Date: 2022-08-21 10:29:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-21 10:54:50
 * @FilePath: \C\C300\C300\C307\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parents;
        unordered_map<int, TreeNode*> nodes;
        queue<TreeNode*> q;
        q.push(root);
        parents[root] = nullptr;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            nodes[node->val] = node;
            if (node->left != nullptr) {
                parents[node->left] = node;
                q.push(node->left);
            }

            if (node->right != nullptr) {
                parents[node->right] = node;
                q.push(node->right);
            }
        }

        q.push(nodes[start]);
        nodes[start]->val = 0;
        int ans = 0;
        while (true) {
            for (int i = q.size(); i > 0; --i) {
                auto node = q.front();
                q.pop();

                auto parent = parents[node];
                if (parent != nullptr && parent->val != 0) {
                    parent->val = 0;
                    q.push(parent);
                }

                if (node->left != nullptr && node->left->val != 0) {
                    node->left->val = 0;
                    q.push(node->left);
                }

                if (node->right != nullptr && node->right->val != 0) {
                    node->right->val = 0;
                    q.push(node->right);
                }
            }

            if (q.empty()) {
                break;
            }
            else {
                ++ans;
            }
        }

        return ans;
    }
};