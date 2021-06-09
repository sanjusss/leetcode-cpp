/*
 * @Author: sanjusss
 * @Date: 2021-06-09 08:28:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-09 09:42:37
 * @FilePath: \0\800\870\879.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
//         static constexpr int mod = 1e9 + 7;
//         int m = group.size();
//         vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
//         dp[0][0] = 1;
//         for (int l = 0; l < m; ++l) {
//             int g = group[l];
//             int p = profit[l];
//             for (int i = n; i >= g; --i) {
//                 for (int j = min(minProfit, p); j >= 0; --j) {
//                     dp[i][minProfit] = (dp[i][minProfit] + dp[i - g][minProfit - j]) % mod;
//                 }

//                 for (int j = minProfit - 1; j >= p; --j) {
//                     dp[i][j] = (dp[i][j] + dp[i - g][j - p]) % mod;
//                 }
//             }
//         }

//         int ans = 0;
//         for (int i = 0; i <= n; ++i) {
//             ans = (ans + dp[i][minProfit]) % mod;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        static constexpr int mod = 1e9 + 7;
        int m = group.size();
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        for (auto& d : dp) {
            d[0] = 1;
        }

        for (int l = 0; l < m; ++l) {
            int g = group[l];
            int p = profit[l];
            for (int i = n; i >= g; --i) {
                for (int j = minProfit; j >= 0; --j) {
                    dp[i][j] = (dp[i][j] + dp[i - g][max(0, j - p)]) % mod;
                }
            }
        }

        return dp[n][minProfit];
    }
};

TEST(&Solution::profitableSchemes)