#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    TreeNode* insertIntoBST(TreeNode* root, int val) {
//        if (root == nullptr) {
//            return new TreeNode(val);
//        }
//
//        if (root->val > val) {
//            if (root->left == nullptr) {
//                root->left = new TreeNode(val);
//            }
//            else {
//                insertIntoBST(root->left, val);
//            }
//        }
//        else {
//            if (root->right == nullptr) {
//                root->right = new TreeNode(val);
//            }
//            else {
//                insertIntoBST(root->right, val);
//            }
//        }
//        
//        return root;
//    }
//};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode* node = root;
        while (true) {
            if (node->val > val) {
                if (node->left == nullptr) {
                    node->left = new TreeNode(val);
                    break;
                }
                else {
                    node = node->left;
                }
            }
            else {
                if (node->right == nullptr) {
                    node->right = new TreeNode(val);
                    break;
                }
                else {
                    node = node->right;
                }
            }
        }

        return root;
    }
};