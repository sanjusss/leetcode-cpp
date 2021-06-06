/*
 * @Author: sanjusss
 * @Date: 2021-06-06 10:08:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-06 10:27:05
 * @FilePath: \0\400\470\474_20210606.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         unordered_map<int64_t, int> cnt;
//         cnt[0] = 0;
//         int ans = 0;
//         for (string& s : strs) {
//             int one = 0;
//             int zero = 0;
//             for (char i : s) {
//                 if (i == '0') {
//                     ++zero;
//                 }
//                 else {
//                     ++one;
//                 }
//             }

//             unordered_map<int64_t, int> temp;
//             for (auto [key, c] : cnt) {
//                 int64_t prevOne = key >> 32;
//                 int64_t prevZero = key & INT_MAX;
//                 if (zero + prevZero > m || one + prevOne > n) {
//                     continue;
//                 }

//                 int64_t next = ((prevOne + one) << 32) | (prevZero + zero);
//                 temp[next] = max(temp[next], c + 1);
//             }

//             for (auto [key, c] : temp) {
//                 cnt[key] = max(cnt[key], c);
//                 ans = max(ans, c);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (string& s : strs) {
            int one = 0;
            int zero = 0;
            for (char i : s) {
                if (i == '0') {
                    ++zero;
                }
                else {
                    ++one;
                }
            }

            for (int i = m - zero; i >= 0; --i) {
                for (int j = n - one; j >= 0; --j) {
                    dp[i + zero][j + one] = max(dp[i + zero][j + one], dp[i][j] + 1);
                }
            }
        }

        return dp[m][n];
    }
};

TEST(&Solution::findMaxForm)