/*
 * @Author: sanjusss
 * @Date: 2022-04-29 10:41:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-29 11:16:51
 * @FilePath: \0\400\420\427.cpp
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
    Node* construct(vector<vector<int>>& grid) {
        function<Node*(int, int, int, int)> dfs = [&](int left, int right, int top, int bottom) -> Node* {
            if (left == right) {
                return new Node(grid[top][left] == 1, true);
            }

            Node* node = new Node();
            int edge = (right - left) / 2;
            node->topLeft = dfs(left, left + edge, top, top + edge);
            node->topRight = dfs(left + edge + 1, right, top, top + edge);
            node->bottomLeft = dfs(left, left + edge, top + edge + 1, bottom);
            node->bottomRight = dfs(left + edge + 1, right, top + edge + 1, bottom);
            if (node->topLeft->isLeaf && node->topRight->isLeaf && node->bottomLeft->isLeaf &&
                node->bottomRight->isLeaf && node->topLeft->val == node->topRight->val &&
                node->topLeft->val == node->bottomLeft->val && node->topLeft->val == node->bottomRight->val) {
                node->isLeaf = true;
                node->val = node->topLeft->val;
                delete node->topLeft;
                node->topLeft = nullptr;
                delete node->topRight;
                node->topRight = nullptr;
                delete node->bottomLeft;
                node->bottomLeft = nullptr;
                delete node->bottomRight;
                node->bottomRight = nullptr;
            }

            return node;
        };
        int n = grid.size();
        return dfs(0, n - 1, 0, n - 1);
    }
};