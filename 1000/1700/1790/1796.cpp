/*
 * @Author: sanjusss
 * @Date: 2022-12-04 11:22:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-04 11:26:03
 * @FilePath: \1000\1700\1790\1796.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int secondHighest(string s) {
        int max1 = -1;
        int max2 = -1;
        for (char i : s) {
            if (i < '0' || i > '9') {
                continue;
            }

            int v = i - '0';
            if (max1 < v) {
                max2 = max1;
                max1 = v;
            }
            else if (v != max1 && max2 < v) {
                max2 = v;
            }
        }

        return max2;
    }
};