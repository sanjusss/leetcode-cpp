/*
 * @Author: sanjusss
 * @Date: 2022-04-11 13:32:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-11 13:37:35
 * @FilePath: \0\300\350\357.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        int ans = 10;
        int cur = 9;
        for (int i = 1; i < n; ++i) {
            cur *= 10 - i;
            ans += cur;
        }

        return ans;
    }
};