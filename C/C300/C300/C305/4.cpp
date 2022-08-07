/*
 * @Author: sanjusss
 * @Date: 2022-08-07 10:49:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-07 10:54:47
 * @FilePath: \C\C300\C300\C305\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> dp(26);
        for (char c : s) {
            int i = c - 'a';
            int cnt = 0;
            for (int j = max(0, i - k); j <= min(25, i + k); ++j) {
                cnt = max(cnt, dp[j]);
            }

            dp[i] = cnt + 1;
        }

        return *max_element(dp.begin(), dp.end());
    }
};