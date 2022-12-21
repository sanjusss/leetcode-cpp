/*
 * @Author: sanjusss
 * @Date: 2022-12-21 08:45:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-21 08:45:15
 * @FilePath: \1000\1700\1750\1753.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if (a < b) {
            swap(a, b);
        }

        if (a < c) {
            swap(a, c);
        }

        if (a > b + c) {
            return b + c;
        }
        else {
            return (a + b + c) / 2;
        }
    }
};