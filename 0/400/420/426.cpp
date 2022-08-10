/*
 * @Author: sanjusss
 * @Date: 2022-08-10 13:41:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-10 13:46:49
 * @FilePath: \0\400\420\426.cpp
 */
#include "leetcode.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* ans = nullptr;
        Node* prev = nullptr;
        Node* node = root;
        stack<Node*> s;
        while (!s.empty() || node != nullptr) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }

            node = s.top();
            s.pop();
            if (ans == nullptr) {
                ans = node;
                prev = node;
            }
            else {
                node->left = prev;
                prev->right = node;
                prev = node;
            }

            node = node->right;
        }

        if (ans != nullptr) {
            ans->left = prev;
            prev->right = ans;
        }

        return ans;
    }
};