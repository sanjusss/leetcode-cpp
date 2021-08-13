/*
 * @Author: sanjusss
 * @Date: 2021-08-13 11:00:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-13 11:01:02
 * @FilePath: \jianzhioffer\10-2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numWays(int n) {
        static constexpr int mod = 1e9 + 7;
        if (n < 2) {
            return 1;
        }

        int fn_2 = 1;
        int fn_1 = 1;
        for (int i = 2; i <= n; ++i) {
            int fn = (fn_2 + fn_1) % mod;
            fn_2 = fn_1;
            fn_1 = fn;
        }

        return fn_1;
    }
};