/*
 * @Author: sanjusss
 * @Date: 2023-03-20 08:54:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-20 10:06:53
 * @FilePath: \1000\1000\1010\1012.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        int u = 0;
        int cur = 10;
        for (; cur - 1 <= n; cur *= 10) {
            int cnt = 9;
            int f = 9;
            for (int i = cur; i > 10; i /= 10) {
                cnt *= f--;
            }

            u += cnt;
        }

        cur /= 10;
        int base = cur;
        vector<bool> used(10);
        int startF = 9;
        for (; cur > 0; cur /= 10) {
            for (; base + cur - 1 <= n; base += cur) {
                int bit = (base / cur) % 10;
                if (used[bit]) {
                    continue;
                }

                int cnt = 1;
                int f = startF;
                for (int i = cur; i > 1; i /= 10) {
                    cnt *= f--;
                }

                u += cnt;
            }

            --startF;
            int bit = (base / cur) % 10;
            if (used[bit]) {
                break;
            }
            else {
                used[bit] = true;
            }
        }

        return n - u;
    }
};

TEST(&Solution::numDupDigitsAtMostN)