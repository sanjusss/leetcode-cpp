/*
 * @Author: sanjusss
 * @Date: 2022-07-19 08:34:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-19 09:13:04
 * @FilePath: \0\700\730\731_20220719.cpp
 */
#include "leetcode.h"

class MyCalendarTwo {
    struct Node {
        int start = 0;
        int end = 0;
        Node* left = nullptr;
        Node* right = nullptr;
        int maxVal = 0;
        int add = 0;
    };

public:
    MyCalendarTwo() {
        m_root->end = 1;
    }
    
    bool book(int start, int end) {
        initRoot(end);
        if (check2(m_root, start, end) == false) {
            return false;
        }

        add1(m_root, start, end);
        return true;
    }

private:
    void initRoot(int end) {
        while (m_root->end < end) {
            Node* node = new Node();
            node->end = m_root->end * 2;
            node->left = m_root;
            m_root = node;
        }
    }

    bool check2(Node* node, int start, int end) {
        if (node->start >= end || node->end <= start) {
            return true;
        }
        else if (node->start >= start && node->end <= end) {
            return node->maxVal < 2;
        }

        update(node);
        return check2(node->left, start, end) && check2(node->right, start, end);
    }

    void add1(Node* node, int start, int end) {
        if (node->start >= end || node->end <= start) {
            return;
        }
        else if (node->start >= start && node->end <= end) {
            ++node->maxVal;
            ++node->add;
            return;
        }

        add1(node->left, start, end);
        add1(node->right, start, end);
        node->maxVal = max(node->left->maxVal, node->right->maxVal);
    }

    void update(Node* node) {
        if (node->left == nullptr) {
            node->left = new Node();
            node->left->start = node->start;
            node->left->end = (node->start + node->end) / 2;
        }

        if (node->right == nullptr) {
            node->right = new Node();
            node->right->start = (node->start + node->end) / 2;
            node->right->end = node->end;
        }

        node->left->add += node->add;
        node->left->maxVal += node->add;
        node->right->add += node->add;
        node->right->maxVal += node->add;
        node->add = 0;
    }

private:
    Node* m_root = new Node();
};
