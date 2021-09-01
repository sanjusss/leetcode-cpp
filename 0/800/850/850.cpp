/*
 * @Author: sanjusss
 * @Date: 2021-09-01 08:48:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-01 13:01:50
 * @FilePath: \0\800\850\850.cpp
 */
#include "leetcode.h"

struct Node {
    int64_t area = 0;
    bool full = false;
    array<Node*, 4> children = { 0 };
};
Node nodes[10000];
int nodei = 0;

Node* newNode() {
    return &nodes[nodei++];
}

void reset() {
    nodei = 0;
    memset(nodes, 0, sizeof(nodes));
}

struct Tree {
    Tree(vector<vector<int>>& rectangles) {
        reset();
        root = newNode();
        initIndeies(rectangles);
        for (auto& rect : rectangles) {
            update(rect);
        }
    }
    
    void update(const vector<int>& rect) {
        int x1 = x2i[rect[0]];
        int y1 = y2i[rect[1]];
        int x2 = x2i[rect[2]];
        int y2 = y2i[rect[3]];
        expandRoot(x2, y2);
        update({ x1, y1, x2, y2 }, { 0, 0, xEnd - 1, yEnd - 1 } , root);
    }

    void update(array<int64_t, 4> q, array<int64_t, 4> c, Node*& node) {
        if (q[0] >= c[2] || q[1] >= c[3] || q[2] <= c[0] || q[3] <= c[1]) {
            return;
        }

        if (node == nullptr) {
            node = newNode();
        }

        if (node->full) {
            return;
        }

        static const int64_t mod = 1e9 + 7;
        if (c[0] >= q[0] && c[1] >= q[1] && c[2] <= q[2] && c[3] <= q[3]) {
            node->area = (ys[c[3]] - ys[c[1]]) * (xs[c[2]] - xs[c[0]]) % mod;
            node->full = true;
            return;
        }

        int64_t xMid = (c[0] + c[2]) / 2;
        int64_t yMid = (c[1] + c[3]) / 2;
        update(q, { c[0], c[1], xMid, yMid }, node->children[0]); 
        update(q, { xMid, c[1], c[2], yMid }, node->children[1]); 
        update(q, { c[0], yMid, xMid, c[3] }, node->children[2]); 
        update(q, { xMid, yMid, c[2], c[3] }, node->children[3]);
        node->area = 0;
        for (Node* child : node->children) {
            if (child != nullptr) {
                node->area += child->area;
            }
        }

        node->area %= mod;
    }

    void expandRoot(int64_t x, int64_t y) {
        while (xEnd <= x || yEnd <= y) {
            xEnd *= 2;
            yEnd *= 2;
            Node* node = newNode();
            node->area = root->area;
            node->children[0] = root;
            root = node;
        }
    }

    void initIndeies(vector<vector<int>>& rectangles) {
        set<int> xset;
        set<int> yset;
        for (auto& r : rectangles) {
            xset.insert(r[0]);
            xset.insert(r[2]);
            yset.insert(r[1]);
            yset.insert(r[3]);
        }

        int xi = 0;
        for (int x : xset) {
            x2i[x] = xi++;
            xs.push_back(x);
        }

        int yi = 0;
        for (int y : yset) {
            y2i[y] = yi++;
            ys.push_back(y);
        }
    }

    Node* root = nullptr;
    int64_t xEnd = 1;
    int64_t yEnd = 1;
    unordered_map<int, int> x2i;
    unordered_map<int, int> y2i;
    vector<int64_t> xs;
    vector<int64_t> ys;
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        Tree tree(rectangles);
        return tree.root->area;
    }
};

TEST(&Solution::rectangleArea)