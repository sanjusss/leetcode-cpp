/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-25 11:03:47
 * @FilePath: \C\C300\C350\C351\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int64_t n = num1 - num2;
        for (int step = 1; n > 0 && step < 1000; ++step, n -= num2) {
            int cnt = 0;
            for (int i = 0; i <= 63; ++i) {
                if ((1ull << i) & n) {
                    ++cnt;
                }
            }

            if (cnt == step) {
                return step;
            }
            else if (cnt < step && n > step) {
                return step;
            }
        }

        return -1;
    }
};

TEST(&Solution::makeTheIntegerZero)