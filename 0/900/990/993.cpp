/*
 * @Author: sanjusss
 * @Date: 2021-05-17 08:33:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-17 08:44:52
 * @FilePath: \0\900\990\993.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val == y) {
            return false;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* xParent = nullptr;
            TreeNode* yParent = nullptr;
            for (int i = q.size(); i > 0; --i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                    if (node->left->val == x) {
                        xParent = node;
                    }
                    else if (node->left->val == y) {
                        yParent = node;
                    }
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                    if (node->right->val == x) {
                        xParent = node;
                    }
                    else if (node->right->val == y) {
                        yParent = node;
                    }
                }
            }

            if (xParent != nullptr && yParent != nullptr && xParent != yParent) {
                return true;
            }
            else if (xParent != nullptr || yParent != nullptr) {
                return false;
            }
        }

        return false;
    }
};

TEST(&Solution::isCousins)