/*
 * @Author: sanjusss
 * @Date: 2022-07-15 08:18:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-15 09:01:06
 * @FilePath: \0\500\550\558.cpp
 */
#include "leetcode.h"

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        return dfs(quadTree1, 0, quadTree2, 0);
    }

private:
    Node* dfs(Node* node1, int val1, Node* node2, int val2) {
        Node* node = new Node();
        if (node1 != nullptr && node1->isLeaf) {
            val1 = node1->val;
        }

        if (node2 != nullptr && node2->isLeaf) {
            val2 = node2->val;
        }

        if ((node1 == nullptr || node1->isLeaf) && (node2 == nullptr || node2->isLeaf)) {
            node->isLeaf = true;
            node->val = (val1 + val2 > 0) ? 1 : 0;
            return node;
        }

        node->topLeft =
            dfs(node1 != nullptr ? node1->topLeft : nullptr, val1, node2 != nullptr ? node2->topLeft : nullptr, val2);
        node->topRight =
            dfs(node1 != nullptr ? node1->topRight : nullptr, val1, node2 != nullptr ? node2->topRight : nullptr, val2);
        node->bottomLeft = dfs(node1 != nullptr ? node1->bottomLeft : nullptr, val1,
                               node2 != nullptr ? node2->bottomLeft : nullptr, val2);
        node->bottomRight = dfs(node1 != nullptr ? node1->bottomRight : nullptr, val1,
                                node2 != nullptr ? node2->bottomRight : nullptr, val2);
        if (node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf && node->bottomRight->isLeaf &&
            node->topLeft->val == node->topRight->val && node->topLeft->val == node->bottomLeft->val &&
            node->topLeft->val == node->bottomRight->val) {
            node->isLeaf = true;
            node->val = node->topLeft->val;
            node->topLeft = nullptr;
            node->topRight = nullptr;
            node->bottomLeft = nullptr;
            node->bottomRight = nullptr;
        }

        return node;
    }
};