/*
 * @Author: sanjusss
 * @Date: 2022-06-12 10:27:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-12 10:39:30
 * @FilePath: \C\C200\C290\C297\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        int n = brackets.size();
        for (int i = 0; i < n; ++i) {
            double in = min(income, brackets[i][0]) - (i == 0 ? 0 : brackets[i - 1][0]);
            ans += in * brackets[i][1] / 100.0;
            if (brackets[i][0] >= income) {
                break;
            }
        }

        return ans;
    }
};