/*
 * @Author: sanjusss
 * @Date: 2022-11-22 08:36:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-22 09:14:33
 * @FilePath: \0\800\870\878.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        static constexpr int64_t mod = 1e9 + 7;  
        int64_t left = 1;
        int64_t right = 4 * 1e13;
        int64_t c = lcm((int64_t)a, (int64_t)b);
        while (left < right) {
            int64_t mid = (left + right) / 2;
            int64_t cnt = mid / a + mid / b - mid / c;
            if (cnt < n) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left % mod;
    }
};