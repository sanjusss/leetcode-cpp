/*
 * @Author: sanjusss
 * @Date: 2021-05-24 08:28:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-24 09:04:57
 * @FilePath: \0\600\660\664.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int strangePrinter(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(n));
//         unordered_map<char, vector<int>> pos;
//         for (int i = 0; i < n; ++i) {
//             pos[s[i]].push_back(i);
//         }
        
//         for (int i = n - 1; i >= 0; --i) {
//             dp[i][i] = 1;
//             for (int j = i + 1; j < n; ++j) {
//                 if (s[j] == s[j - 1]) {
//                     dp[i][j] = dp[i][j - 1];
//                 }
//                 else {
//                     dp[i][j] = dp[i][j - 1] + 1;
//                     auto& jps = pos[s[j]];
//                     auto p = lower_bound(jps.begin(), jps.end(), j);
//                     while (p != jps.begin() && *prev(p) >= i) {
//                         --p;
//                         dp[i][j] = min(dp[i][j], dp[i][*p] + dp[*p + 1][j - 1]);
//                     }
//                 }
//             }
//         }

//         return dp[0][n - 1];
//     }
// };

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        char prev = 0;
        int len = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != prev) {
                prev = s[i];
                s[len++] = s[i];
            }
        }
        
        n = len;

        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                }
                else {
                    dp[i][j] = dp[i + 1][j] + 1;
                    for (int k = i + 1; k < j; ++k) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};

TEST(&Solution::strangePrinter)