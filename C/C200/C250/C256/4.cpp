/*
 * @Author: sanjusss
 * @Date: 2021-08-29 10:22:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-29 14:23:05
 * @FilePath: \C\C200\C250\C256\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numberOfUniqueGoodSubsequences(string binary) {
        static constexpr int mod = 1e9 +7;
        array<int, 2> dp = { 0, 0 };
        int singleZero = 1;
        for (int i = binary.size() - 1; i >= 0; --i) {
            dp[binary[i] - '0'] = (dp[0] + dp[1] + 1) % mod;
            if (binary[i] == '0') {
                singleZero = 1; 
            }
        }

        return (dp[1] + singleZero) % mod;
    }
};

TEST(&Solution::numberOfUniqueGoodSubsequences)