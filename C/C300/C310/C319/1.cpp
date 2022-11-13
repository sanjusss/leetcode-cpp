/*
 * @Author: sanjusss
 * @Date: 2022-11-13 10:26:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-13 10:31:10
 * @FilePath: \C\C300\C310\C319\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {
            {
                celsius + 273.15,
                celsius * 1.80 + 32.00
            }
        };
    }
};