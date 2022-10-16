/*
 * @Author: sanjusss
 * @Date: 2022-10-14 10:59:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-14 11:34:19
 * @FilePath: \0\900\940\940_20221014.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int distinctSubseqII(string s) {
//         static constexpr uint32_t mod = 1e9 + 7;
//         int n = s.size();
//         vector<vector<uint32_t>> dp(n, vector<uint32_t>(26));
//         for (int i = 0; i < n; ++i) {
//             int c = s[i] - 'a';
//             for (int j = i; j >= 0; --j) {
//                 if (j == 0) {
//                     dp[j][c] = 1;
//                     continue;
//                 }

//                 dp[j][c] = 0;
//                 for (int k = 0; k < 26; ++k) {
//                     dp[j][c] += dp[j - 1][k];
//                     dp[j][c] %= mod;
//                 }
//             }
//         }

//         uint32_t ans = 0;
//         for (auto& d : dp) {
//             for (auto& cnt : d) {
//                 ans += cnt;
//                 ans %= mod;
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int distinctSubseqII(string s) {
//         static constexpr uint32_t mod = 1e9 + 7;
//         int n = s.size();
//         vector<vector<uint32_t>> dp(n, vector<uint32_t>(26));
//         vector<uint32_t> sums(n + 1);
//         sums[0] = 1;
//         for (int i = 0; i < n; ++i) {
//             int c = s[i] - 'a';
//             for (int j = i; j >= 0; --j) {
//                 sums[j + 1] += mod - dp[j][c];
//                 dp[j][c] = sums[j];
//                 sums[j + 1] += sums[j];
//                 sums[j + 1] %= mod;
//             }
//         }

//         uint32_t ans = 0;
//         for (int i = 1; i <= n; ++i) {
//             ans += sums[i];
//             ans %= mod;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int distinctSubseqII(string s) {
        static constexpr uint32_t mod = 1e9 + 7;
        uint32_t sum = 1;
        vector<uint32_t> prev(26);
        for (char c : s) {
            int i = c - 'a';
            uint32_t old = sum;
            sum *= 2;
            sum %= mod;
            sum += mod - prev[i];
            sum %= mod;
            prev[i] = old;
        }

        return (sum + mod - 1) % mod;
    }
};

TEST(&Solution::distinctSubseqII)