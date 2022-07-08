/*
 * @Author: sanjusss
 * @Date: 2022-07-08 08:32:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-08 08:32:05
 * @FilePath: \1000\1200\1210\1217.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0;
        int even = 0;
        for (int i : position) {
            if (i % 2 == 0) {
                ++even;
            }
            else {
                ++odd;
            }
        }

        return min(odd, even);
    }
};