/*
 * @Author: sanjusss
 * @Date: 2024-03-08 09:54:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-03-08 10:03:31
 * @FilePath: \2000\2800\2830\2834.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        static constexpr int64_t mod = 1e9 + 7;
        int64_t left = min(target / 2, n);
        int64_t right = n - left;
        int64_t sum = (1 + left) * left / 2 + (target + target + right - 1) * right / 2;
        return sum % mod;
    }
};