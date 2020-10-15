#pragma once
#include "leetcode.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// class Solution {
// public:
//     Node* connect(Node* root) {
//         queue<Node*> q;
//         q.push(root);
//         do {
//             Node* prev = nullptr;
//             Node* node;
//             for (int i = q.size(); i > 0; --i) {
//                 node = q.front();
//                 q.pop();
//                 if (node == nullptr) {
//                     break;
//                 }

//                 if (prev != nullptr) {
//                     prev->next = node;
//                 }

//                 prev = node;
//                 q.push(node->left);
//                 q.push(node->right);
//             }
//         } while (!q.empty());

//         return root;
//     }
// };

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        Node* mostLeft = root;
        Node* head;
        while (mostLeft->left != nullptr) {
            head = mostLeft;
            mostLeft = mostLeft->left;
            do {
                head->left->next = head->right;
                if (head->next == nullptr) {
                    break;
                }
                else {
                    head->right->next = head->next->left;
                    head = head->next;
                }

            } while (true);
        }

        return root;
    }
};