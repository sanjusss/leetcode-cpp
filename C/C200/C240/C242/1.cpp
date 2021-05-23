/*
 * @Author: sanjusss
 * @Date: 2021-05-23 10:29:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-23 10:34:08
 * @FilePath: \C\C200\C240\C242\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool checkZeroOnes(string s) {
        char prev = 0;
        int len = 0;
        int one = 0;
        int zero = 0;
        for (char i : s) {
            if (i == prev) {
                ++len;
            }
            else {
                if (prev == '1') {
                    one = max(one, len);
                }
                else if (prev == '0') {
                    zero = max(zero, len);
                }

                prev = i;
                len = 1;
            }
        }

        if (prev == '1') {
            one = max(one, len);
        }
        else if (prev == '0') {
            zero = max(zero, len);
        }

        return one > zero;
    }
};