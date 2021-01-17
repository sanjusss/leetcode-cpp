/*
 * @Author: sanjusss
 * @Date: 2021-01-17 13:21:29
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-17 13:45:38
 * @FilePath: \1000\1200\1230\1232.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n <= 2) {
            return true;
        }

        int a = -(coordinates[1][1] - coordinates[0][1]);
        int b = coordinates[1][0] - coordinates[0][0];
        for (int i = 2; i < n; ++i) {
            if (a * (coordinates[i][0] - coordinates[0][0]) + b * (coordinates[i][1] - coordinates[0][1]) != 0) {
                return false;
            }
        }

        return true;
    }
};