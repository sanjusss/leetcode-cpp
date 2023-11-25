/*
 * @Author: sanjusss
 * @Date: 2023-11-25 22:48:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-25 22:59:18
 * @FilePath: \1000\1400\1450\1457.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int pseudoPalindromicPaths (TreeNode* root) {
//         queue<pair<int, TreeNode*>> q;
//         q.emplace(0, root);
//         int ans = 0;
//         while (!q.empty()) {
//             auto [cur, node] = q.front();
//             q.pop();
//             cur ^= 1 << (node->val - 1);
//             if (node->left == nullptr && node->right == nullptr) {
//                 if (__builtin_popcount(cur) <= 1) {
//                     ++ans;
//                 }
//             }
//             else {
//                 if (node->left != nullptr) {
//                     q.emplace(cur, node->left);
//                 }

//                 if (node->right != nullptr) {
//                     q.emplace(cur, node->right);
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        stack<pair<int, TreeNode*>> s;
        s.emplace(0, root);
        int ans = 0;
        while (!s.empty()) {
            auto [cur, node] = s.top();
            s.pop();
            cur ^= 1 << (node->val - 1);
            if (node->left == nullptr && node->right == nullptr) {
                if (cur == (cur & -cur)) {
                    ++ans;
                }
            }
            else {
                if (node->left != nullptr) {
                    s.emplace(cur, node->left);
                }

                if (node->right != nullptr) {
                    s.emplace(cur, node->right);
                }
            }
        }

        return ans;
    }
};