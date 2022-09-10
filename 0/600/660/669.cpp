/*
 * @Author: sanjusss
 * @Date: 2022-09-10 11:15:21
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-10 11:22:51
 * @FilePath: \0\600\660\669.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     TreeNode* trimBST(TreeNode* root, int low, int high) {
//         if (root == nullptr) {
//             return nullptr;
//         }

//         if (root->val < low) {
//             return trimBST(root->right, low, high);
//         }
//         else if (root->val > high) {
//             return trimBST(root->left, low, high);
//         }

//         root->left = trimBST(root->left, low, high);
//         root->right = trimBST(root->right, low, high);
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root != nullptr) {
            if (root->val < low) {
                root = root->right;
            }
            else if (root->val > high) {
                root = root->left;
            }
            else {
                break;
            }
        }

        if (root == nullptr) {
            return nullptr;
        }

        for (TreeNode* node = root; node->left != nullptr;) {
            if (node->left->val < low) {
                node->left = node->left->right;
            }
            else {
                node = node->left;
            }
        }

        for (TreeNode* node = root; node->right != nullptr;) {
            if (node->right->val > high) {
                node->right = node->right->left;
            }
            else {
                node = node->right;
            }
        }

        return root;
    }
};