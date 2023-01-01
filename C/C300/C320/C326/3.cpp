/*
 * @Author: sanjusss
 * @Date: 2023-01-01 10:21:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-01 10:48:53
 * @FilePath: \C\C300\C320\C326\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        vector<int64_t> bits{ { 1 } };
        for (int i = 0; i <= 10; ++i) {
            bits.push_back(bits.back() * 10);
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] - '0' > k) {
                return -1;
            }

            int64_t cur = 0;
            for (int j = i; j >= 0; --j) {
                cur += (s[j] - '0') * bits[i - j];
                if (cur > k) {
                    break;
                }

                dp[i + 1] = min(dp[i + 1], dp[j] + 1);
            }
        }

        return dp[n];
    }
};