/*
 * @Author: sanjusss
 * @Date: 2023-02-04 19:51:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-04 19:56:45
 * @FilePath: \1000\1700\1790\1798.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int maxV = 0;
        sort(coins.begin(), coins.end());
        for (int i : coins) {
            if (maxV - i < -1) {
                break;
            }

            maxV += i;
        }

        return maxV + 1;
    }
};