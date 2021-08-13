/*
 * @Author: sanjusss
 * @Date: 2021-08-13 10:56:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-13 10:59:03
 * @FilePath: \jianzhioffer\10-1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int fib(int n) {
        static constexpr int mod = 1e9 + 7;
        if (n < 2) {
            return n;
        }

        int fn_2 = 0;
        int fn_1 = 1;
        for (int i = 2; i <= n; ++i) {
            int fn = (fn_2 + fn_1) % mod;
            fn_2 = fn_1;
            fn_1 = fn;
        }

        return fn_1;
    }
};