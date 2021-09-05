/*
 * @Author: sanjusss
 * @Date: 2021-09-05 10:01:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-05 10:10:52
 * @FilePath: \jianzhioffer\14-2.cpp
 */
#include "leetcode.h"

class Solution {
    static constexpr int64_t mod = 1e9 + 7;

public:
    int cuttingRope(int n) {
        if (n <= 3) {
            return n - 1;
        }

        switch (n % 3) {
            case 0:
                return pow(3, n / 3);

            case 1:
                return pow(3, n / 3 - 1) * 4 % mod;

            case 2:
                return pow(3, n / 3) * 2 % mod;
        }

        return 0;
    }

private:
    int64_t pow(int64_t a, int64_t b) {
        a %= mod;
        int64_t ans = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                ans = ans * a % mod;
            }

            b /= 2;
            a = a * a % mod;
        }

        return ans;
    }
};