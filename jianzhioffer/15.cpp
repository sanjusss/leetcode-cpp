/*
 * @Author: sanjusss
 * @Date: 2021-06-23 08:22:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-23 08:23:49
 * @FilePath: \jianzhioffer\15.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};