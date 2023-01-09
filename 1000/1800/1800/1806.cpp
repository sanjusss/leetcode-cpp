/*
 * @Author: sanjusss
 * @Date: 2023-01-09 11:14:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-09 11:28:32
 * @FilePath: \1000\1800\1800\1806.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int reinitializePermutation(int n) {
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            int j = i;
            int step = 0;
            do {
                ++step;
                if (j < n / 2) {
                    j *= 2;
                }
                else {
                    j = 2 * j + 1 - n;
                }
            } while (j != i);

            ans = lcm(ans, step);
        }

        return ans;
    }
};