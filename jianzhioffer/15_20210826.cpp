/*
 * @Author: sanjusss
 * @Date: 2021-08-26 08:34:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-26 08:35:05
 * @FilePath: \jianzhioffer\15_20210826.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n > 0) {
            ++ans;
            n = n & (n - 1);
        }

        return ans;
    }
};