/*
 * @Author: sanjusss
 * @Date: 2021-08-15 11:07:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-15 11:35:14
 * @FilePath: \解题模板\大数阶乘.h
 */
#include "leetcode.h"

int64_t pow(int64_t a, int64_t b) {
    static const int64_t mod = 1e9 + 7;
    a %= mod;
    int64_t ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return ans;
}