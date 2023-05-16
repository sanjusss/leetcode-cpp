/*
 * @Author: sanjusss
 * @Date: 2023-05-16 08:22:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-16 09:42:09
 * @FilePath: \1000\1300\1330\1335.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minDifficulty(vector<int>& jobDifficulty, int d) {
//         static constexpr int sc_invalid = INT_MAX / 2;
//         int n = jobDifficulty.size();
//         vector<vector<int>> dp(n + 1, vector<int>(d + 1, sc_invalid));
//         dp[0][0] = 0;
//         for (int i = 0; i < n; ++i) {
//             int v = jobDifficulty[i];
//             for (int j = i; j >= 0; --j) {
//                 v = max(v, jobDifficulty[j]);
//                 for (int k = 1; k <= d; ++k) {
//                     dp[i + 1][k] = min(dp[i + 1][k], dp[j][k - 1] + v);
//                 }
//             }
//         }

//         if (dp[n][d] == sc_invalid) {
//             return -1;
//         }
//         else {
//             return dp[n][d];
//         }
//     }
// };

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        static constexpr int sc_invalid = INT_MAX / 2;
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, sc_invalid));
        dp[0][0] = 0;
        for (int k = 1; k <= d; ++k) {
            stack<pair<int, int>> s;
            for (int i = 0; i < n; ++i) {
                int prev = dp[i][k - 1];
                while (!s.empty() && jobDifficulty[s.top().first] < jobDifficulty[i]) {
                    prev = min(prev, s.top().second);
                    s.pop();
                }

                if (s.empty()) {
                    dp[i + 1][k] = prev + jobDifficulty[i];
                }
                else {
                    dp[i + 1][k] = min(prev + jobDifficulty[i], dp[s.top().first + 1][k]);
                }

                s.emplace(i, prev);
            }
        }

        return dp[n][d];
    }
};