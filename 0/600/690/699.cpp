/*
 * @Author: sanjusss
 * @Date: 2021-08-26 08:57:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-27 13:54:19
 * @FilePath: \0\600\690\699.cpp
 */
#include "leetcode.h"

// class Solution {
//     struct Node {
//         int begin;
//         int end;
//         int minHeight = 0;
//         int maxHeight = 0;
//         Node* left = nullptr;
//         Node* right = nullptr;
//     };

// public:
//     vector<int> fallingSquares(vector<vector<int>>& positions) {
//         vector<int> ans;
//         Node* root = new Node{ INT_MAX, INT_MIN };
//         for (auto& p : positions) {
//             root->begin = min(root->begin, p[0]);
//             root->end = max(root->end, p[0] + p[1]);
//         }

//         for (auto& p : positions) {
//             int begin = p[0];
//             int end = p[0] + p[1];
//             int add = p[1];
//             int height = maxHeight(root, begin, end);
//             height += add;
//             update(root, begin, end, height);
//             ans.push_back(root->maxHeight);
//         }

//         return ans;
//     }

// private:
//     static int maxHeight(Node* node, int begin, int end) {
//         if (node->begin == begin && node->end == end) {
//             return node->maxHeight;
//         }

//         int mid = (node->begin + node->end) / 2;
//         int height = 0;

//         if (begin < mid) {
//             if (node->left == nullptr) {
//                 height = max(height, node->minHeight);
//             }
//             else {
//                 node->left->maxHeight = max(node->left->maxHeight, node->minHeight);
//                 node->left->minHeight = max(node->left->minHeight, node->minHeight);
//                 height = max(height, maxHeight(node->left, begin, min(mid, end)));
//             }
//         }

//         if (end > mid) {
//             if (node->right == nullptr) {
//                 height = max(height, node->minHeight);
//             }
//             else {
//                 node->right->maxHeight = max(node->right->maxHeight, node->minHeight);
//                 node->right->minHeight = max(node->right->minHeight, node->minHeight);
//                 height = max(height, maxHeight(node->right, max(begin, mid), end));
//             }
//         }

//         return height;
//     }

//     static void update(Node* node, int begin, int end, int height) {
//         node->maxHeight = max(node->maxHeight, height);
//         if (node->begin == begin && node->end == end) {
//             node->minHeight = height;
//             return;
//         }

//         int mid = (node->begin + node->end) / 2;
//         if (begin < mid) {
//             if (node->left == nullptr) {
//                 node->left = new Node{ node->begin, mid, node->minHeight, node->minHeight };
//             }

//             update(node->left, begin, min(mid, end), height);
//         }

//         if (end > mid) {
//             if (node->right == nullptr) {
//                 node->right = new Node{ mid, node->end, node->minHeight, node->minHeight };
//             }

//             update(node->right, max(begin, mid), end, height);
//         }

//         if (node->left != nullptr && node->right != nullptr) {
//             node->minHeight = min(node->left->minHeight, node->right->minHeight);
//         }
//     }
// };

class Solution {
    struct TreeNodes {
        TreeNodes(int n) : n(n), tree(n * 10), lazy(n * 10) {
        }

        int query(int left, int right) {
            return query(left, right, 0, n - 1, 1);
        }

        int query(int targetLeft, int targetRight, int curLeft, int curRight, int i) {
            if (i >= tree.size() || curLeft > targetRight || curRight < targetLeft) {
                return 0;
            }

            if (targetLeft <= curLeft && curRight <= targetRight) {
                return tree[i];
            }

            if (lazy[i] > 0) {
                tree[i * 2] = max(tree[i * 2], lazy[i]);
                lazy[i * 2] = max(lazy[i * 2], lazy[i]);
                tree[i * 2 + 1] = max(tree[i * 2 + 1], lazy[i]);
                lazy[i * 2 + 1] = max(lazy[i * 2 + 1], lazy[i]);
                lazy[i] = 0;
            }

            int mid = (curLeft + curRight) / 2;
            return max(query(targetLeft, targetRight, curLeft, mid, i * 2),
                       query(targetLeft, targetRight, mid + 1, curRight, i * 2 + 1));
        }

        void set(int left, int right, int value) {
            set(left, right, 0, n - 1, 1, value);
        }

        void set(int targetLeft, int targetRight, int curLeft, int curRight, int i, int value) {
            if (i >= tree.size() || curLeft > targetRight || curRight < targetLeft) {
                return;
            }

            if (targetLeft <= curLeft && curRight <= targetRight) {
                tree[i] = value;
                lazy[i] = max(lazy[i], value);
                return;
            }

            int mid = (curLeft + curRight) / 2;
            set(targetLeft, targetRight, curLeft, mid, i * 2, value);
            set(targetLeft, targetRight, mid + 1, curRight, i * 2 + 1, value);
            tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
        }

        const int n;
        vector<int> tree;
        vector<int> lazy;
    };

public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        auto index = createIndex(positions);
        TreeNodes tn(index.size());
        vector<int> ans;
        int maxHeight = 0;
        for (auto& p : positions) {
            int left = index[p[0]];
            int right = index[p[0] + p[1] - 1];
            int height = tn.query(left, right);
            height += p[1];
            tn.set(left, right, height);
            maxHeight = max(maxHeight, height);
            ans.push_back(maxHeight);
        }

        return ans;
    }

private:
    unordered_map<int, int> createIndex(const vector<vector<int>>& positions) {
        set<int> ps;
        for (auto& p : positions) {
            ps.insert(p[0]);
            ps.insert(p[0] + p[1] - 1);
        }

        int i = 0;
        unordered_map<int, int> index;
        for (int p : ps) {
            index[p] = i++;
        }

        return index;
    }
};

TEST(&Solution::fallingSquares)