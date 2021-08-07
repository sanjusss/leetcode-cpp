/*
 * @Author: sanjusss
 * @Date: 2021-08-07 15:04:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-07 15:09:55
 * @FilePath: \jianzhioffer\35.cpp
 */
#include "leetcode.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node = head;
        while (node != nullptr) {
            Node* next = node->next;
            node->next = new Node(node->val);
            node->next->next = next;
            node = next;
        }

        node = head;
        while (node != nullptr) {
            if (node->random != nullptr) {
                node->next->random = node->random->next;
            }

            node = node->next->next;
        }

        Node root(0);
        Node* cur = &root;
        node = head;
        while (node != nullptr) {
            cur->next = node->next;
            cur = cur->next;
            node->next = node->next->next;
            node = node->next;
        }

        return root.next;
    }
};