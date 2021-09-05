/*
 * @Author: sanjusss
 * @Date: 2021-09-05 15:03:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-05 15:10:07
 * @FilePath: \43.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        int64_t base = 1;
        while (base <= n) {
            int64_t nextBase = base * 10;
            ans += n / nextBase * base;
            ans += max(min(n % nextBase - base + 1, base), (int64_t)0);
            base = nextBase;
        }

        return ans;
    }
};