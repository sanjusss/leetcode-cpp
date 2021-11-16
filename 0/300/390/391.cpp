/*
 * @Author: sanjusss
 * @Date: 2021-11-16 13:48:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-16 18:11:34
 * @FilePath: \0\300\390\391.cpp
 */
#include "leetcode.h"

// class Solution {
//     struct Node {
//         int left;
//         int buttom;
//         int right;  // 右侧终点，不包括
//         int top;  // 最高终点，不包括
//         bool full = false;
//         bool hasSet = false;
//         Node* children[4]{};
//     };

//     struct Tree {
//         bool update(int left, int buttom, int right, int top) {
//             left -= minE;
//             buttom -= minE;
//             right -= minE;
//             top -= minE;
//             while (root->right < right || root->top < top) {
//                 Node* node = new Node{ 0, 0, root->right * 2 + 1, root->top * 2 + 1 };
//                 node->children[0] = root;
//                 root = node;
//             }

//             return update(left, buttom, right, top, root);
//         }

//         bool update(int left, int buttom, int right, int top, Node* node) {
//             if (left > node->right || right < node->left || top < node->buttom ||
//                 buttom > node->top) {
//                 return true;
//             }
//             else if (node->full) {
//                 return false;
//             }
//             else if (node->left >= left && node->right <= right && node->buttom >= buttom && node->top <= top) {
//                 if (node->hasSet) {
//                     return false;
//                 }
//                 else {
//                     node->hasSet = true;
//                     node->full = true;
//                     return true;
//                 }
//             }

//             node->hasSet = true;

//             int midx = (node->left + node->right) / 2;
//             int midy = (node->buttom + node->top) / 2;
//             if (midx >= left && midy >= buttom) {
//                 if (node->children[0] == nullptr) {
//                     node->children[0] = new Node { node->left, node->buttom, midx, midy };
//                 }

//                 if (!update(left, buttom, right, top, node->children[0])) {
//                     return false;
//                 }
//             }
            
//             if (midx < right && midy >= buttom) {
//                 if (node->children[1] == nullptr) {
//                     node->children[1] = new Node { midx + 1, node->buttom, node->right, midy };
//                 }

//                 if (!update(left, buttom, right, top, node->children[1])) {
//                     return false;
//                 }
//             }

//             if (midx >= left && midy < top) {
//                 if (node->children[2] == nullptr) {
//                     node->children[2] = new Node { node->left, midy + 1, midx, node->top };
//                 }

//                 if (!update(left, buttom, right, top, node->children[2])) {
//                     return false;
//                 }
//             }

//             if (midx < right && midy < top) {
//                 if (node->children[3] == nullptr) {
//                     node->children[3] = new Node { midx + 1, midy + 1, node->right, node->top };
//                 }

//                 if (!update(left, buttom, right, top, node->children[3])) {
//                     return false;
//                 }
//             }

//             node->full = true;
//             for (auto& i : node->children) {
//                 node->full = node->full && i != nullptr && i->full;
//             }

//             return true;
//         }

//         bool isFull(int left, int buttom, int right, int top) {
//             left -= minE;
//             buttom -= minE;
//             right -= minE;
//             top -= minE;
//             if (right > root->right || top > root->top) {
//                 return false;
//             }

//             return isFull(left, buttom, right, top, root);
//         }

//         bool isFull(int left, int buttom, int right, int top, Node* node) {
//             if (node->full || left > node->right || right < node->left || top < node->buttom ||
//                 buttom > node->top) {
//                 return true;
//             }
//             else if (node->left >= left && node->right <= right && node->buttom >= buttom && node->top <= top) {
//                 return false;
//             }

//             int midx = (node->left + node->right) / 2;
//             int midy = (node->buttom + node->top) / 2;
//             if (midx >= left && midy >= buttom) {
//                 if (node->children[0] == nullptr || !isFull(left, buttom, right, top, node->children[0])) {
//                     return false;
//                 }
//             }
            
//             if (midx < right && midy >= buttom) {
//                 if (node->children[1] == nullptr || !isFull(left, buttom, right, top, node->children[1])) {
//                     return false;
//                 }
//             }

//             if (midx >= left && midy < top) {
//                 if (node->children[2] == nullptr || !isFull(left, buttom, right, top, node->children[2])) {
//                     return false;
//                 }
//             }

//             if (midx < right && midy < top) {
//                 if (node->children[3] == nullptr || !isFull(left, buttom, right, top, node->children[3])) {
//                     return false;
//                 }
//             }

//             return true;
//         }

//         Node* root = new Node{ 0, 0, 0, 0 };
//         static constexpr int minE = -1e5;
//     };

// public:
//     bool isRectangleCover(vector<vector<int>>& rectangles) {
//         Tree t;
//         int left = INT_MAX;
//         int buttom = INT_MAX;
//         int right = INT_MIN;
//         int top = INT_MIN;
//         for (auto& r : rectangles) {
//             if (!t.update(r[0], r[1], r[2] - 1, r[3] - 1)) {
//                 return false;
//             }

//             left = min(left, r[0]);
//             buttom = min(buttom, r[1]);
//             right = max(right, r[2] - 1);
//             top = max(top, r[3] - 1);
//         }

//         return t.isFull(left, buttom, right, top);
//     }
// };

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<uint64_t, int> cnt;
        auto topoint = [&cnt] (int x, int y) -> uint64_t {
            static constexpr int base = 1e5;
            return ((uint64_t)(x + base) << 32) | (uint64_t)(y + base);
        };

        int sum = 0;
        int left = INT_MAX;
        int buttom = INT_MAX;
        int right = INT_MIN;
        int top = INT_MIN;
        for (auto& rect : rectangles) {
            int l = rect[0];
            int b = rect[1];
            int r = rect[2];
            int t = rect[3];

            left = min(left, l);
            buttom = min(buttom, b);
            right = max(right, r);
            top = max(top, t);
            sum += (t - b) * (r - l);

            ++cnt[topoint(l, b)];
            ++cnt[topoint(l, t)];
            ++cnt[topoint(r, b)];
            ++cnt[topoint(r, t)];
        }

        unordered_set<uint64_t> angles {
            topoint(left, buttom),
            topoint(left, top),
            topoint(right, buttom),
            topoint(right, top),
        };
        for (auto [p, c] : cnt) {
            if (angles.count(p)) {
                if (c != 1) {
                    return false;
                }
            }
            else if (c != 2 && c != 4) {
                return false;
            }
        }

        return (top - buttom) * (right - left) == sum;
    }
};

TEST(&Solution::isRectangleCover)