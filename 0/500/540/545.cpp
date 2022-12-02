/*
 * @Author: sanjusss
 * @Date: 2022-12-02 08:43:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-02 08:56:28
 * @FilePath: \0\500\540\545.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        ans.push_back(root->val);
        if (root->left != nullptr) {
            FindLeft(root->left, true, ans);
        }

        if (root->right != nullptr) {
            FindRight(root->right, true, ans);
        }

        return ans;
    }

private:
    void FindLeft(TreeNode* node, bool isLeft, vector<int>& vals) {
        if (isLeft || (node->left == nullptr && node->right == nullptr)) {
            vals.push_back(node->val);
        }

        if (node->left != nullptr) {
            FindLeft(node->left, isLeft, vals);
        }

        if (node->right != nullptr) {
            FindLeft(node->right, isLeft && node->left == nullptr, vals);
        }
    }

    void FindRight(TreeNode* node, bool isRight, vector<int>& vals) {
        if (node->left != nullptr) {
            FindRight(node->left, isRight && node->right == nullptr, vals);
        }

        if (node->right != nullptr) {
            FindRight(node->right, isRight, vals);
        }

        if (isRight || (node->left == nullptr && node->right == nullptr)) {
            vals.push_back(node->val);
        }
    }
};