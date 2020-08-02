#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    void flatten(TreeNode* root) {
//        stack<TreeNode*> s;
//        s.push(root);
//        TreeNode* cur = nullptr;
//        do {
//            auto node = s.top();
//            s.pop();
//            if (cur != nullptr) {
//                cur->left = node;
//            }
//
//            while (node != nullptr) {
//                if (node->right != nullptr) {
//                    s.push(node->right);
//                }
//
//                cur = node;
//                node = node->left;
//            }
//
//
//        } while (!s.empty());
//
//        cur = root;
//        while (cur != nullptr) {
//            cur->right = cur->left;
//            cur->left = nullptr;
//            cur = cur->right;
//        }
//    }
//};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* pre;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                cur = cur->right;
                continue;
            }

            if (cur->right == nullptr) {
                cur->right = cur->left;
                cur->left = nullptr;
                cur = cur->right;
                continue;
            }

            pre = cur->left;
            while (pre->right != nullptr) {
                pre = pre->right;
            }

            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
    }
};