/*
 * @Author: sanjusss
 * @Date: 2023-03-21 08:31:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-21 08:31:16
 * @FilePath: \2000\2400\2460\2469.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return { { celsius + 273.15, celsius * 1.80 + 32.00 } };
    }
};