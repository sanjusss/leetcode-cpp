/*
 * @Author: sanjusss
 * @Date: 2021-06-16 08:42:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-16 09:41:06
 * @FilePath: \0\100\150\156.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     TreeNode* upsideDownBinaryTree(TreeNode* root) {
//         if (root == nullptr) {
//             return nullptr;
//         }

//         stack<pair<TreeNode*, TreeNode*>> s;
//         s.emplace(root, nullptr);
//         while (root->left != nullptr) {
//             s.emplace(root->left, root->right);
//             root = root->left;
//         }

//         TreeNode* prev = nullptr;
//         while (!s.empty()) {
//             auto [left, right] = s.top();
//             s.pop();
//             if (prev == nullptr) {
//                 root = left;
//             }
//             else {
//                 prev->right = left;
//             }

//             left->left = right;
//             left->right = nullptr;
//             prev = left;
//         }

//         return root;
//     }
// };

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* node = root;
        TreeNode* next = nullptr;
        TreeNode* parent = nullptr;
        TreeNode* parentRight = nullptr;
        while (node != nullptr) {
            next = node->left;
            node->left = parentRight;
            parentRight = node->right;
            node->right = parent;
            parent = node;
            node = next;
        }

        return parent;
    }
};

TEST(&Solution::upsideDownBinaryTree)