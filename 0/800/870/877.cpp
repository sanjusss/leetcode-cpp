/*
 * @Author: sanjusss
 * @Date: 2021-06-16 08:24:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-16 08:33:57
 * @FilePath: \0\800\870\877.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         int n = piles.size();
//         vector<vector<int>> dp(n, vector<int>(n));
//         for (int i = n - 1; i >= 0; --i) {
//             dp[i][i] = piles[i];
//             for (int j = i + 1; j < n; ++j) {
//                 dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
//             }
//         }

//         return dp[0][n - 1] > 0;
//     }
// };
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;//因为piles.size是偶数
    }
};

TEST(&Solution::stoneGame)