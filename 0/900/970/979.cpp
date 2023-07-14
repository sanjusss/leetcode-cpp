/*
 * @Author: sanjusss
 * @Date: 2023-07-14 10:13:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-14 10:25:31
 * @FilePath: \0\900\970\979.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int distributeCoins(TreeNode* root) {
//         function<pair<int,int>(TreeNode*)> dfs = [&dfs] (TreeNode* node) -> pair<int, int> {
//             if (node == nullptr) {
//                 return { 0, 0 };
//             }

//             auto [lmoves, lcoins] = dfs(node->left); 
//             auto [rmoves, rcoins] = dfs(node->right);
//             int coins = node->val - 1 + lcoins + rcoins;
//             int moves = lmoves + abs(lcoins) + rmoves + abs(rcoins);
//             return { moves, coins };
//         };

//         return dfs(root).first;
//     }
// };

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&dfs, &ans] (TreeNode* node) -> int {
            if (node == nullptr) {
                return 0;
            }

            auto l = dfs(node->left); 
            auto r = dfs(node->right);
            ans += abs(l) + abs(r);
            return node->val - 1 + l + r;
        };

        dfs(root);
        return ans;
    }
};