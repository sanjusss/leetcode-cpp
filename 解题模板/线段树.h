#include "leetcode.h"

class Tree {
public:
    struct Node {
        Node* leftChild = nullptr;
        Node* rightChild = nullptr;
        int left = 0;
        int right = 0;
        int val = INT_MAX;
        bool modify = false;
    };

    void update(int left, int right, int val) {
        initRoot(right);
        update(m_root, left, right, val);
    }

    int query(int pos) {
        return query(m_root, pos);
    }

private:
    void initRoot(int right) {
        while (m_root->right < right) {
            Node* node = new Node();
            node->right = (m_root->right + 1) * 2 - 1;
            node->leftChild = m_root;
            m_root = node;
        }
    }

    void update(Node* node, int left, int right, int val) {
        if (node->right < left || node->left > right) {
            return;
        }
        else if (left <= node->left && node->right <= right) {
            node->val = min(node->val, val);
            node->modify = true;
            return;
        }

        if (node->leftChild == nullptr) {
            Node* child = new Node();
            child->left = node->left;
            child->right = (node->left + node->right) / 2;
            node->leftChild = child;
        }

        if (node->rightChild == nullptr) {
            Node* child = new Node();
            child->left = (node->left + node->right) / 2 + 1;
            child->right = node->right;
            node->rightChild = child;
        }

        update(node->leftChild, left, right, val);
        update(node->rightChild, left, right, val);
    }

    int query(Node* node, int pos) {
        if (pos < node->left || node->right < pos) {
            return INT_MAX;
        }

        if (node->leftChild == nullptr || node->rightChild == nullptr) {
            return node->val;
        }

        if (node->modify) {
            node->modify = false;
            node->leftChild->modify = true;
            node->leftChild->val = min(node->leftChild->val, node->val);
            node->rightChild->modify = true;
            node->rightChild->val = min(node->rightChild->val, node->val);
        }

        if (pos <= node->leftChild->right) {
            return query(node->leftChild, pos);
        }
        else {
            return query(node->rightChild, pos);
        }
    }

private:
    Node* m_root = new Node();
};