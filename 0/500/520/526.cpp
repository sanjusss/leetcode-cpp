/*
 * @Author: sanjusss
 * @Date: 2021-08-16 08:37:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-16 09:01:01
 * @FilePath: \0\500\520\526.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int countArrangement(int n) {
//         vector<bool> used(n + 1);
//         return dfs(used, 1, n);
//     }

// private:
//     int dfs(vector<bool>& used, int i, int n) {
//         if (i > n) {
//             return 1;
//         }

//         int res = 0;
//         for (int j = 1; j <= n; ++j) {
//             if (used[j]) {
//                 continue;
//             }

//             if (j % i != 0 && i % j != 0) {
//                 continue;
//             }

//             used[j] = true;
//             res += dfs(used, i + 1, n);
//             used[j] = false;
//         }

//         return res;
//     }
// };

// class Solution {
// public:
//     int countArrangement(int n) {
//         int allMask = (1 << n) - 1;
//         vector<int> dp(allMask + 1);
//         dp[0] = 1;
//         for (int i = 1; i <= allMask; ++i) {
//             int count = __builtin_popcount(i);
//             for (int j = 1; j <= n; ++j) {
//                 int bit = 1 << (j - 1);
//                 if (!(i & bit)) {
//                     continue;
//                 }

//                 if (count % j != 0 && j % count != 0) {
//                     continue;
//                 }

//                 dp[i] += dp[i ^ bit];
//             }
//         }

//         return dp[allMask];
//     }
// };

class Solution {
public:
    int countArrangement(int n) {
        int allMask = (1 << n) - 1;
        vector<int> dp(allMask + 1);
        dp[0] = 1;
        for (int mask = 1; mask <= allMask; ++mask) {
            int i = __builtin_popcount(mask);
            for (int k = mask; k > 0; k = k & (k - 1)) {
                int j = __builtin_ctz(k) + 1;
                if (i % j == 0 || j % i == 0) {
                    dp[mask] += dp[mask ^ (1 << (j - 1))];
                }
            }
        }

        return dp[allMask];
    }
};

TEST(&Solution::countArrangement)