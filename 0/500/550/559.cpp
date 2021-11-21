/*
 * @Author: sanjusss
 * @Date: 2021-11-21 08:40:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-21 08:42:11
 * @FilePath: \0\500\550\559.cpp
 */
#include "leetcode.h"

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int d = 0;
        for (auto i : root->children) {
            d = max(d, maxDepth(i));
        }

        return d + 1;
    }
};