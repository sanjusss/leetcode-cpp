/*
 * @Author: sanjusss
 * @Date: 2023-01-23 09:00:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-23 09:03:24
 * @FilePath: \2000\2300\2300\2303.cpp
 */
#include "leetcode.h"

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        int prev = 0;
        for (auto& b : brackets) {
            ans += (min<double>(income, b[0]) - prev) * b[1] / 100.0;
            prev = b[0];
            if (income < prev) {
                break;
            }
        }

        return ans;
    }
};