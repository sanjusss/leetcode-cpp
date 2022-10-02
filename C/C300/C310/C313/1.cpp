/*
 * @Author: sanjusss
 * @Date: 2022-10-02 10:26:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-02 10:31:17
 * @FilePath: \C\C300\C310\C313\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int commonFactors(int a, int b) {
        int c = gcd(a, b);
        int cnt = 0;
        for (int i = 1; i <= c; ++i) {
            if (c % i == 0) {
                ++cnt;
            }
        }

        return cnt;
    }
};