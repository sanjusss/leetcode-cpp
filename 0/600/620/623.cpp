/*
 * @Author: sanjusss
 * @Date: 2022-08-05 08:23:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-05 08:34:30
 * @FilePath: \0\600\620\623.cpp
 */
#include "leetcode.h"

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* ans = new TreeNode(val);
            ans->left = root;
            return ans;
        }

        TreeNode head(0);
        head.left = root;
        queue<TreeNode*> q;
        q.emplace(&head);
        for (int i = 1; i < depth; ++i) {
            for (int j = q.size(); j > 0; --j) {
                auto node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.emplace(node->left);
                }

                if (node->right != nullptr) {
                    q.emplace(node->right);
                }
            }
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            auto left = new TreeNode(val);
            left->left = node->left;
            node->left = left;
            auto right = new TreeNode(val);
            right->right = node->right;
            node->right = right;
        }

        return head.left;
    }
};