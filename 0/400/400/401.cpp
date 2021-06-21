/*
 * @Author: sanjusss
 * @Date: 2021-06-21 08:30:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-21 09:37:27
 * @FilePath: \0\400\400\401.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<string> readBinaryWatch(int turnedOn) {
//         vector<vector<vector<int>>> dp(7, vector<vector<int>>(turnedOn + 1));
//         dp[0][0].push_back(0);
//         for (int i = 1; i <= 6; ++i) {
//             dp[i][0].push_back(0);
//             int v = 1 << (i - 1);
//             for (int j = min(i, turnedOn); j > 0; --j) {
//                 copy(dp[i - 1][j].begin(), dp[i - 1][j].end(), back_inserter(dp[i][j]));
//                 for (int k : dp[i - 1][j - 1]) {
//                     dp[i][j].push_back(k + v);
//                 }
//             }
//         }

//         vector<string> ans;
//         for (int hourOn = min(4, turnedOn); hourOn >= 0; --hourOn) {
//             for (int h : dp[4][hourOn]) {
//                 if (h >= 12) {
//                     continue;
//                 }

//                 for (int m : dp[6][turnedOn - hourOn]) {
//                     if (m >= 60) {
//                         continue;
//                     }

//                     ans.emplace_back(to_string(h) + (m >= 10 ? ":"s : ":0"s) + to_string(m));
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.emplace_back(to_string(h) + (m >= 10 ? ":"s : ":0"s) + to_string(m));
                }
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::readBinaryWatch)