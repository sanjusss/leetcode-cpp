/*
 * @Author: sanjusss
 * @Date: 2022-09-23 08:24:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-23 08:34:02
 * @FilePath: \0\700\700\707_20220923.cpp
 */
#include "leetcode.h"

struct Node {
    int val = 0;
    Node* next = nullptr;
};

class MyLinkedList {
public:
    MyLinkedList() {
    }

    int get(int index) {
        Node* node = m_root->next;
        while (index > 0 && node != nullptr) {
            node = node->next;
            --index;
        }

        if (node == nullptr) {
            return -1;
        }
        else {
            return node->val;
        }
    }

    void addAtHead(int val) {
        Node* node = new Node{
            .val = val,
            .next = m_root->next,
        };
        m_root->next = node;
    }

    void addAtTail(int val) {
        Node* node = m_root;
        while (node->next != nullptr) {
            node = node->next;
        }

        node->next = new Node{ .val = val };
    }

    void addAtIndex(int index, int val) {
        Node* node = m_root;
        while (index > 0 && node != nullptr) {
            node = node->next;
            --index;
        }

        if (node == nullptr) {
            return;
        }

        node->next = new Node{ .val = val, .next = node->next };
    }

    void deleteAtIndex(int index) {
        Node* node = m_root;
        while (index > 0 && node->next != nullptr) {
            node = node->next;
            --index;
        }

        if (node->next == nullptr) {
            return;
        }

        node->next = node->next->next;
    }

private:
    Node* m_root = new Node();
};