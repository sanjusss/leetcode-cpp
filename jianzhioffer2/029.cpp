/*
 * @Author: sanjusss
 * @Date: 2022-06-18 16:50:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-18 17:31:25
 * @FilePath: \jianzhioffer2\029.cpp
 */
#include "leetcode.h"

class Node {
public:
    int val;
    Node* next;

    Node() {
    }

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if (head == nullptr) {
            node->next = node;
            return node;
        }

        Node* maxNode = nullptr;
        Node* cur = head;
        do {
            if (cur->val > cur->next->val) {
                maxNode = cur;
            }

            cur = cur->next;
        } while (head != cur);

        if (maxNode == nullptr) {
            node->next = head->next;
            head->next = node;
        }
        else {
            cur = maxNode;
            do {
                if (insertVal <= cur->next->val) {
                    break;
                }

                cur = cur->next;
            } while (cur != maxNode);
            node->next = cur->next;
            cur->next = node;
        }

        return head;
    }
};