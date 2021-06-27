/*
 * @Author: sanjusss
 * @Date: 2021-06-27 10:28:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-27 13:57:22
 * @FilePath: \C\C200\C240\C247\3.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     long long wonderfulSubstrings(string word) {
//         int n = word.size();
//         vector<vector<int>> dp(n + 1);
//         vector<int> cur(10);
//         dp[0] = cur;
//         int64_t ans = 0;
//         for (int i = 0; i < n; ++i) {
//             ++cur[word[i] - 'a'];
//             dp[i + 1] = cur;
//             for (int j = 0; j <= i; ++j) {
//                 int odd = 0;
//                 for (int k = 0; k < 10 && odd < 2; ++k) {
//                     if ((cur[k] - dp[j][k]) % 2 == 1) {
//                         ++odd;
//                     }
//                 }

//                 if (odd < 2) {
//                     ++ans;
//                 }
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     long long wonderfulSubstrings(string word) {
//         int64_t ans = 0;
//         int allMask = (1 << 10) - 1;
//         vector<int> prev(allMask + 1);
//         vector<int> cur(allMask + 1);
//         for (char i : word) {
//             swap(prev, cur);
//             fill(cur.begin(), cur.end(), 0);
//             int c = i - 'a';
//             int bit = 1 << c;
//             int curMask = allMask - bit;
//             cur[0] += prev[bit];
//             cur[bit] += prev[0] + 1;
//             for (int j = curMask; j != 0; j = (j - 1) & curMask) {
//                 cur[j + bit] += prev[j];
//                 cur[j] += prev[j + bit];
//             }

//             ans += cur[0];
//             for (int j = 0; j < 10; ++j) {
//                 ans += cur[1 << j];
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     long long wonderfulSubstrings(string word) {
//         int64_t ans = 0;
//         int allMask = (1 << 10) - 1;
//         vector<int> cnt(1 << 10);
//         cnt[0] = 1;
//         int cur = 0;
//         for (char i : word) {
//             cur = cur ^ (1 << (i - 'a'));
//             ans += cnt[cur];
//             for (int j = 0; j < 10; ++j) {
//                 ans += cnt[cur ^ (1 << j)];
//             }

//             ++cnt[cur];
//         }

//         return ans;
//     }
// };

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int64_t ans = 0;
        vector<int> cnt(1 << 10);
        cnt[0] = 1;
        vector<int> targets{ 0 };
        for (int i = 0; i < 10; ++i) {
            targets.push_back(1 << i);
        }

        int cur = 0;
        for (char i : word) {
            cur = cur ^ (1 << (i - 'a'));
            for (int j : targets) {
                ans += cnt[cur ^ j];
            }

            ++cnt[cur];
        }

        return ans;
    }
};

TEST(&Solution::wonderfulSubstrings)