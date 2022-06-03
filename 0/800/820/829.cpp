/*
 * @Author: sanjusss
 * @Date: 2022-06-03 10:12:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-03 10:18:20
 * @FilePath: \0\800\820\829.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (int m = 1; m * m <= 2 * n; ++m) {
            int tx = 2 * n - m * m + m;
            if (tx > 0 && tx % (2 * m) == 0) {
                ++ans;
            }
        }

        return ans;
    }
};