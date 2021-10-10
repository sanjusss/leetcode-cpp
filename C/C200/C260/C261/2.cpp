/*
 * @Author: sanjusss
 * @Date: 2021-10-03 10:34:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-03 10:38:28
 * @FilePath: \C\C200\C260\C261\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int nsum = mean * (m + n) - accumulate(rolls.begin(), rolls.end(), 0);
        if (nsum < n || nsum > n * 6) {
            return {};
        }

        vector<int> ans(n, nsum / n);
        for (int i = nsum % n; i > 0; --i) {
           ++ans[i - 1];
        }

        return ans;
    }
};