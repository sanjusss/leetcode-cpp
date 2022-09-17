/*
 * @Author: sanjusss
 * @Date: 2022-09-16 08:46:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-16 11:25:58
 * @FilePath: \0\800\850\850_20220916.cpp
 */
#include "leetcode.h"

// class Solution {
//     struct Node {
//         int x1;
//         int x2;
//         int y1;
//         int y2;
//         int64_t cnt = 0;
//         bool full = false;
//         Node* children[4]{};
//     };

// public:
//     int rectangleArea(vector<vector<int>>& rectangles) {
//         set<int> xs;
//         set<int> ys;
//         for (auto& rect : rectangles) {
//             xs.insert(rect[0]);
//             xs.insert(rect[2]);
//             ys.insert(rect[1]);
//             ys.insert(rect[3]);
//         }

//         int xi = 0;
//         for (int x : xs) {
//             m_xi[x] = xi++;
//             m_x.push_back(x);
//         }

//         int yi = 0;
//         for (int y : ys) {
//             m_yi[y] = yi++;
//             m_y.push_back(y);
//         }

//         Node* root = new Node{ .x1 = 0, .x2 = 1, .y1 = 0, .y2 = 1 };
//         for (auto& rect : rectangles) {
//             int x1 = m_xi[rect[0]];
//             int y1 = m_yi[rect[1]];
//             int x2 = m_xi[rect[2]];
//             int y2 = m_yi[rect[3]];
//             root = updateRoot(x2, y2, root);
//             updateNode(x1, x2, y1, y2, root);
//         }

//         return root->cnt;
//     }

// private:
//     Node* updateRoot(int x2, int y2, Node* root) {
//         while (root->x2 < x2 || root->y2 < y2) {
//             Node* node = new Node{
//                 .x1 = 0,
//                 .x2 = root->x2 * 2,
//                 .y1 = 0,
//                 .y2 = root->y2 * 2,
//                 .cnt = root->cnt,
//             };
//             node->children[0] = root;
//             root = node;
//         }

//         return root;
//     }

//     void updateNode(int x1, int x2, int y1, int y2, Node* node) {
//         if (node->full) {
//             return;
//         }

//         if (node->x1 >= x1 && node->x2 <= x2 && node->y1 >= y1 && node->y2 <= y2) {
//             node->full = true;
//             node->cnt = (int64_t)(m_x[node->x2] - m_x[node->x1]) * (int64_t)(m_y[node->y2] - m_y[node->y1]) % m_mod;
//             return;
//         }

//         if (node->y1 >= y2 || node->x1 >= x2 || node->y2 <= y1 || node->x2 <= x1) {
//             return;
//         }

//         fillChildren(node);
//         node->full = true;
//         node->cnt = 0;
//         for (auto& child : node->children) {
//             updateNode(x1, x2, y1, y2, child);
//             node->full = node->full && child->full;
//             node->cnt += child->cnt;
//             node->cnt %= m_mod;
//         }
//     }

//     void fillChildren(Node* parent) {
//         int half = (parent->x2 - parent->x1) / 2;
//         if (parent->children[0] == nullptr) {
//             Node* node = new Node{
//                 .x1 = parent->x1,
//                 .x2 = parent->x1 + half,
//                 .y1 = parent->y1,
//                 .y2 = parent->y1 + half,
//             };
//             parent->children[0] = node;
//         }

//         if (parent->children[1] == nullptr) {
//             Node* node = new Node{
//                 .x1 = parent->x1 + half,
//                 .x2 = parent->x2,
//                 .y1 = parent->y1,
//                 .y2 = parent->y1 + half,
//             };
//             parent->children[1] = node;
//         }

//         if (parent->children[2] == nullptr) {
//             Node* node = new Node{
//                 .x1 = parent->x1,
//                 .x2 = parent->x1 + half,
//                 .y1 = parent->y1 + half,
//                 .y2 = parent->y2,
//             };
//             parent->children[2] = node;
//         }

//         if (parent->children[3] == nullptr) {
//             Node* node = new Node{
//                 .x1 = parent->x1 + half,
//                 .x2 = parent->x2,
//                 .y1 = parent->y1 + half,
//                 .y2 = parent->y2,
//             };
//             parent->children[3] = node;
//         }
//     }

// private:
//     static constexpr int64_t m_mod = 1e9 + 7;
//     unordered_map<int, int> m_xi;
//     vector<int> m_x;
//     unordered_map<int, int> m_yi; 
//     vector<int> m_y;
// };

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        static constexpr int64_t mod = 1e9 + 7;
        if (rectangles.empty()) {
            return 0;
        }

        map<int, map<int, int>> x2l;
        for (auto& rect : rectangles) {
            x2l[rect[0]];
            x2l[rect[2]];
        }

        for (auto& rect : rectangles) {
            auto begin = x2l.find(rect[0]);
            auto end = x2l.find(rect[2]);
            for (auto xi = begin; xi != end; ++xi) {
                xi->second[rect[1]] += 1;
                xi->second[rect[3]] -= 1;
            }
        }

        int64_t ans = 0;
        for (auto xi = x2l.begin(), end = prev(x2l.end()); xi != end; ++xi) {
            int64_t x = next(xi)->first - xi->first;
            int64_t prevY = 0;
            int cnt = 0;
            for (auto [y, c] : xi->second) {
                if (cnt > 0) {
                    ans += ((int64_t)y - prevY) * x;
                    ans %= mod;
                }

                prevY = y;
                cnt += c;
            }
        }

        return ans;
    }
};

TEST(&Solution::rectangleArea)