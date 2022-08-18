/*
 * @Author: sanjusss
 * @Date: 2022-08-18 09:26:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-18 09:54:48
 * @FilePath: \0\500\510\510.cpp
 */
#include "leetcode.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

// class Solution {
// public:
//     Node* inorderSuccessor(Node* node) {
//         while (node != nullptr) {
//             if (node->right != nullptr) {
//                 node = node->right;
//                 while (node->left != nullptr) {
//                     node = node->left;
//                 }

//                 return node;
//             }
//             else if (node->parent == nullptr) {
//                 return nullptr;
//             }
//             else if (node->parent->left == node) {
//                 return node->parent;
//             }
//             else {
//                 node = node->parent;
//                 node->right = nullptr;
//             }
//         }

//         return nullptr;
//     }
// };

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right != nullptr) {
            node = node->right;
            while (node->left != nullptr) {
                node = node->left;
            }

            return node;
        }

        while (node->parent != nullptr && node->parent->right == node) {
            node = node->parent;
        }

        return node->parent;
    }
};