#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int sumOfLeftLeaves(TreeNode* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//
//        return dfs(root, false);
//    }
//
//private:
//    int dfs(TreeNode* node, bool isLeft) {
//        if (node->left == nullptr && node->right == nullptr) {
//            if (isLeft) {
//                return node->val;
//            }
//            else {
//                return 0;
//            }
//        }
//
//        int res = 0;
//        if (node->left != nullptr) {
//            res += dfs(node->left, true);
//        }
//
//        if (node->right != nullptr) {
//            res += dfs(node->right, false);
//        }
//
//        return res;
//    }
//};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        do {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr) {
                if (node->left->left == nullptr && node->left->right == nullptr) {
                    ans += node->left->val;
                }
                else {
                    q.push(node->left);
                }
            }

            if (node->right != nullptr) {
                q.push(node->right);
            }
        } while (!q.empty());

        return ans;
    }
};