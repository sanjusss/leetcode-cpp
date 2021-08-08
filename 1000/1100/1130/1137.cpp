/*
 * @Author: sanjusss
 * @Date: 2021-08-08 08:48:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-08 08:51:04
 * @FilePath: \1000\1100\1130\1137.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int tribonacci(int n) {
        switch (n) {
            case 0:
                return 0;
            case 1:
                return 1;
            case 2:
                return 1;

            default:
                break;
        }

        int t1 = 0;
        int t2 = 1;
        int t3 = 1;
        for (int i = 4; i <= n; ++i) {
            tie(t1, t2, t3) = make_tuple(t2, t3, t1 + t2 + t3);
        }

        return t3;
    }
};