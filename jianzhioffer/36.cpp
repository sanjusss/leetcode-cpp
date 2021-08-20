/*
 * @Author: sanjusss
 * @Date: 2021-08-20 08:39:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-20 08:47:47
 * @FilePath: \jianzhioffer\36.cpp
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
        stack<Node*> s;
        Node* head = nullptr;
        Node* prev = nullptr;
        Node* cur = root;
        while (!s.empty() || cur != nullptr) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            s.pop();
            if (head == nullptr) {
                head = cur;
            }
            else {
                prev->right = cur;
                cur->left = prev;
            }

            prev = cur;
            cur = cur->right;
        }

        if (prev != nullptr) {
            prev->right = head;
            head->left = prev;
        }

        return head;
    }
};