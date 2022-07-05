/*
 * @Author: sanjusss
 * @Date: 2022-07-05 07:57:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-05 08:09:50
 * @FilePath: \0\700\720\729_20220705.cpp
 */
#include "leetcode.h"

class MyCalendar {
    struct Node {
        int left = 0;
        int right = 0;
        Node* leftChild = nullptr;
        Node* rightChild = nullptr;
        bool all = false;
    };

public:
    MyCalendar() {
        m_root->right = 1;
    }
    
    bool book(int start, int end) {
        InitRoot(end);
        if (find(m_root, start, end)) {
            return false;
        }

        update(m_root, start, end);
        return true;
    }

private:
    void InitRoot(int end) {
        while (m_root->right < end) {
            Node* node = new Node();
            node->right = m_root->right * 2;
            node->leftChild = m_root;
            m_root = node;
        }
    }

    bool find(Node* node, int start, int end) {
        if (node->left >= end || node->right <= start) {
            return false;
        }
        else if (node->all) {
            return true;
        }

        return (node->leftChild != nullptr && find(node->leftChild, start, end)) || (node->rightChild != nullptr && find(node->rightChild, start, end));
    }

    void update(Node* node, int start, int end) {
        if (node->all || node->left >= end || node->right <= start) {
            return;
        }
        else if (node->left >= start && node->right <= end) {
            node->all = true;
            return;
        }

        if (node->leftChild == nullptr) {
            node->leftChild = new Node();
            node->leftChild->left = node->left;
            node->leftChild->right = (node->left + node->right) / 2;
        }

        if (node->rightChild == nullptr) {
            node->rightChild = new Node();
            node->rightChild->left = (node->left + node->right) / 2;
            node->rightChild->right = node->right;
        }

        update(node->leftChild, start, end);
        update(node->rightChild, start, end);
    }

private:
    Node* m_root = new Node();;
};