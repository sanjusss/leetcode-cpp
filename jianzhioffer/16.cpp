/*
 * @Author: sanjusss
 * @Date: 2021-08-25 10:18:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-25 10:24:50
 * @FilePath: \jianzhioffer\16.cpp
 */
#include "leetcode.h"

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        int64_t nn = n;
        nn = abs(nn);
        while (nn > 0) {
            if (nn % 2 == 1) {
                ans *= x;
            }

            x *= x;
            nn /= 2;
        }

        if (n > 0) {
            return ans;
        }
        else {
            return 1 / ans;
        }
    }
};