/*
 * @Author: sanjusss
 * @Date: 2021-08-28 10:02:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-28 11:43:33
 * @FilePath: \0\700\710\715.cpp
 */
#include "leetcode.h"

struct Node {
    int left;
    int right;
    bool tracked = false;
    int mark = 0;
    Node* leftChild = nullptr;
    Node* rightChild = nullptr;
};
Node nodes[50000];
class RangeModule {
public:
    RangeModule() {
    }

    void addRange(int left, int right) {
        --right;
        while (root->right < right) {
            Node* node = getNode(root->left, root->right * 2);
            node->leftChild = root;
            root = node;
        }

        addRange(left, right, root);
    }

    bool queryRange(int left, int right) {
        return root->right >= right - 1 && queryRange(left, right - 1, root);
    }

    void removeRange(int left, int right) {
        if (root->right >= left) {
            removeRange(left, right - 1, root);
        }
    }

private:
    void addRange(int left, int right, Node* node) {
        if (node->left >= left && node->right <= right) {
            node->tracked = true;
            node->mark = 1;
            return;
        }

        pull(node);
        int mid = (node->left + node->right) / 2;
        if (left <= mid) {
            if (node->leftChild == nullptr) {
                node->leftChild = getNode(node->left, mid);
            }

            addRange(left, right, node->leftChild);
        }

        if (right > mid) {
            if (node->rightChild == nullptr) {
                node->rightChild = getNode(mid + 1, node->right);
            }

            addRange(left, right, node->rightChild);
        }

        setNode(node);
    }

    bool queryRange(int left, int right, Node* node) {
        if (node->left >= left && node->right <= right) {
            return node->tracked;
        }

        pull(node);
        int mid = (node->left + node->right) / 2;
        bool res = true;
        if (left <= mid) {
            if (node->leftChild == nullptr) {
                return false;
            }

            res = res && queryRange(left, right, node->leftChild);
        }

        if (res && right > mid) {
            if (node->rightChild == nullptr) {
                return false;
            }

            res = res && queryRange(left, right, node->rightChild);
        }

        return res;
    }

    void removeRange(int left, int right, Node* node) {
        if (node->left >= left && node->right <= right) {
            node->tracked = false;
            node->mark = -1;
            return;
        }

        pull(node);
        int mid = (node->left + node->right) / 2;
        if (left <= mid) {
            if (node->leftChild != nullptr) {
                removeRange(left, right, node->leftChild);
            }
        }

        if (right > mid) {
            if (node->rightChild != nullptr) {
                removeRange(left, right, node->rightChild);
            }
        }

        setNode(node);
    }

    void pull(Node* node) {
        if (node->mark == 0) {
            return;
        }

        if (node->left != node->right) {
            createLeftChild(node);
            pullChildNode(node->leftChild, node->mark);
            createRightChild(node);
            pullChildNode(node->rightChild, node->mark);
        }

        node->mark = 0;
    }

    void pullChildNode(Node* node, int mark) {
        node->mark = mark;
        node->tracked = mark == 1;
    }

    void createLeftChild(Node* node) {
        if (node->leftChild != nullptr) {
            return;
        }

        node->leftChild = getNode(node->left, (node->left + node->right) / 2);
    }

    void createRightChild(Node* node) {
        if (node->rightChild != nullptr) {
            return;
        }

        node->rightChild = getNode((node->left + node->right) / 2 + 1, node->right);
    }

    void setNode(Node* node) {
        node->tracked = (node->leftChild != nullptr && node->leftChild->tracked) &&
                        (node->rightChild != nullptr && node->rightChild->tracked);
    }

    Node* getNode(int left, int right) {
        Node* node = &nodes[nodeIndex++];
        memset(node, 0, sizeof(Node));
        node->left = left;
        node->right = right;
        return node;
    }

private:
    Node* root = getNode(1, 1);
    int nodeIndex = 0;
};

int main(int, char**) {
    RangeModule r;
    cout << r.queryRange(3, 7) << endl;
    r.addRange(2, 9);
    cout << r.queryRange(6, 8) << endl;
    cout << r.queryRange(5, 8) << endl;
    r.removeRange(2, 3);
    cout << r.queryRange(7, 10) << endl;
    return 0;
}