/*
 * @Author: sanjusss
 * @Date: 2023-02-22 08:55:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-22 09:48:05
 * @FilePath: \1000\1100\1140\1140.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int stoneGameII(vector<int>& piles) {
//         int n = piles.size();
//         vector<int> sums(n + 1);
//         for (int i = 0; i < n; ++i) {
//             sums[i + 1] = sums[i] + piles[i];
//         }

//         unordered_map<int, int> dp;
//         function<int(int, int)> dfs = [&](int i, int m) -> int {
//             if (i >= n) {
//                 return 0;
//             }

//             int key = (i << 16) + m;
//             if (dp.count(key)) {
//                 return dp[key];
//             }

//             int& res = dp[key];
//             int sum = sums[n] - sums[i];
//             for (int j = 0; j < 2 * m && i + j < n; ++j) {
//                 res = max(res, sum - dfs(i + j + 1, max(m, j + 1)));
//             }

//             return res;
//         };
//         return dfs(0, 1);
//     }
// };

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; --i) {
            int sum = sums[n] - sums[i];
            for (int j = 1; j <= n; ++j) {
                int& v = dp[i][j];
                for (int k = 0; k < 2 * j && i + k < n; ++k) {
                    if (i + k + 1 >= n) {
                        v = max(v, sum);
                    }
                    else {
                        v = max(v, sum - dp[i + k + 1][min(n, max(k + 1, j))]);
                    }
                }
            }
        }

        return dp[0][1];
    }
};