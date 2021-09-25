/*
 * @Author: sanjusss
 * @Date: 2021-09-24 06:57:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-24 07:02:22
 * @FilePath: \0\400\430\430_20210924.cpp
 */
#include "leetcode.h"

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* root = nullptr;
        Node* prev = nullptr;
        stack<Node*> s;
        if (head != nullptr) {
            s.push(head);
        }
        
        while (!s.empty()) {
            Node* node = s.top();
            s.pop();
            if (root == nullptr) {
                root = node;
            }

            if (prev != nullptr) {
                prev->next = node;
                node->prev = prev;
            }

            if (node->next != nullptr) {
                s.push(node->next);
            }

            if (node->child != nullptr) {
                s.push(node->child);
                node->child = nullptr;
            }

            prev = node;
        }

        return root;
    }
};