/*
 * @Author: sanjusss
 * @Date: 2022-06-21 08:17:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-21 08:43:10
 * @FilePath: \0\700\710\715_20220621.cpp
 */
#include "leetcode.h"

struct Node {
    int left = 0;
    int right = 0;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
    bool allIsTrue = false;
    bool needUpdate = false; 
};

class RangeModule {
public:
    RangeModule() {
        m_root->right = 1;
    }
    
    void addRange(int left, int right) {
        initRoot(right);
        set(m_root, left, right, true);
    }
    
    bool queryRange(int left, int right) {
        initRoot(right);
        return query(m_root, left, right);
    }
    
    void removeRange(int left, int right) {
        initRoot(right);
        set(m_root, left, right, false);
    }

private:
    void initRoot(int right) {
        while (m_root->right < right) {
            Node* node = new Node();
            node->right = m_root->right * 2;
            node->leftChild = m_root;
            m_root = node;
        }
    }

    void initNode(Node* node) {
        if (node->right - node->left <= 1) {
            return;
        }

        if (node->leftChild == nullptr) {
            Node* next = new Node();
            next->left = node->left;
            next->right = (node->left + node->right) / 2;
            node->leftChild = next;
        }

        if (node->rightChild == nullptr) {
            Node* next = new Node();
            next->left = (node->left + node->right) / 2;
            next->right = node->right;
            node->rightChild = next;
        }

        if (node->needUpdate) {
            node->needUpdate = false;
            node->leftChild->needUpdate = true;
            node->rightChild->needUpdate = true;
            node->leftChild->allIsTrue = node->allIsTrue;
            node->rightChild->allIsTrue = node->allIsTrue;
        }
    }

    void set(Node* node, int left, int right, bool value) {
        if (node->left >= right || node->right <= left) {
            return;
        }
        else if (node->left >= left && node->right <= right) {
            node->allIsTrue = value;
            node->needUpdate = true;
            return;
        }

        initNode(node);
        set(node->leftChild, left, right, value);
        set(node->rightChild, left, right, value);
        node->allIsTrue = node->leftChild->allIsTrue && node->rightChild->allIsTrue;
    }

    bool query(Node* node, int left, int right) {
        if (node->left >= right || node->right <= left) {
            return true;
        }
        else if (node->left >= left && node->right <= right) {
            return node->allIsTrue;
        }
        else if (node->needUpdate) {
            return node->allIsTrue;
        }

        initNode(node);
        return query(node->leftChild, left, right) && query(node->rightChild, left, right);
    }

private:
    Node* m_root = new Node();
};