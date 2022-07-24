/*
 * @Author: sanjusss
 * @Date: 2022-07-10 11:04:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-10 22:18:26
 * @FilePath: \C\C300\C300\C301\4.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int idealArrays(int n, int maxValue) {
//         static constexpr int64_t mod = 1e9 + 7;
//         vector<int64_t> cur(maxValue + 1, 1);
//         cur[0] = 0;
//         vector<int64_t> prev(maxValue + 1);
//         for (int i = 2; i <= n; ++i) {
//             swap(cur, prev);
//             fill(cur.begin(), cur.end(), (int64_t)0);
//             for (int j = maxValue; j > 0; --j) {
//                 for (int k = j; k <= maxValue; k += j) {
//                     cur[k] += prev[j];
//                     cur[k] %= mod;
//                 }
//             }
//         }

//         return accumulate(cur.begin(), cur.end(), (int64_t)0) % mod;
//     }
// };

// class Solution {
// public:
//     int idealArrays(int n, int maxValue) {
//         static constexpr int64_t mod = 1e9 + 7;
//         vector<vector<int>> from(maxValue + 1);
//         for (int i = maxValue; i > 0; --i) {
//             for (int j = i + i; j <= maxValue; j += i) {
//                 from[j].push_back(i);
//             }
//         }

//         vector<int64_t> dp(maxValue + 1, 1);
//         dp[0] = 0;
//         for (int i = 2; i <= n; ++i) {
//             for (int j = maxValue; j > 0; --j) {
//                 for (int k : from[j]) {
//                     dp[j] += dp[k];
//                     dp[j] %= mod;
//                 }
//             }
//         }

//         return accumulate(dp.begin(), dp.end(), (int64_t)0) % mod;
//     }
// };

// class Solution {
// public:
//     int idealArrays(int n, int maxValue) {
//         static constexpr int64_t mod = 1e9 + 7;
//         vector<vector<int>> from(maxValue + 1);
//         for (int i = maxValue; i > 0; --i) {
//             for (int j = i + i; j <= maxValue; j += i) {
//                 from[j].push_back(i);
//             }
//         }

//         vector<int64_t> dp(maxValue + 1, 1);
//         dp[0] = 0;
//         for (int i = 2; i <= n; ++i) {
//             for (int j = maxValue; j > 0; --j) {
//                 for (int k : from[j]) {
//                     dp[j] += dp[k];
//                     dp[j] %= mod;
//                 }
//             }
//         }

//         return accumulate(dp.begin(), dp.end(), (int64_t)0) % mod;
//     }
// };

static constexpr int64_t mod = 1e9 + 7;
static constexpr int maxK = 13; // 最大因子数量
static constexpr int maxV = 1e4;
static constexpr int maxC = maxV + maxK; // 最大组合数
static int comb[maxC][maxK + 1];
static vector<int> cnts[maxV + 1];
static int init = [] () {
    for (int i = 1; i <= maxV; ++i) {
        int r = i;
        for (int j = 2; j * j <= r; ++j) {
            if (r % j == 0) {
                int c = 0;
                do {
                    r /= j;
                    ++c;
                } while (r % j == 0);
                cnts[i].push_back(c);
            }
        }

        if (r > 1) {
            cnts[i].push_back(1);
        }
    }

    comb[0][0] = 1;
    for (int n = 1; n < maxC; ++n) {
        comb[n][0] = 1;
        for (int m = 1; m <= min(n, maxK); ++m) {
            comb[n][m] = (comb[n - 1][m] + comb[n - 1][m - 1]) % mod;
        }
    }

    return 0;
} ();

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        int64_t ans = 0;
        for (int i = 1; i <= maxValue; ++i) {
            int64_t mul = 1;
            for (int k : cnts[i]) {
                mul *= comb[k + n - 1][k];
                mul %= mod;
            }

            ans += mul;
            ans %= mod;
        }

        return ans;
    }
};

TEST(&Solution::idealArrays)