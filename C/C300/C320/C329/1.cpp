/*
 * @Author: sanjusss
 * @Date: 2023-01-22 10:31:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-22 10:33:36
 * @FilePath: \C\C300\C320\C329\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int alternateDigitSum(int n) {
        int sign = 1;
        int ans = 0;
        while (n > 0) {
            ans += sign * (n % 10);
            n /= 10;
            sign *= -1;
        }

        return ans * sign * -1;
    }
};