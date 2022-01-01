/*
 * @Author: sanjusss
 * @Date: 2022-01-01 10:07:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-01 10:09:22
 * @FilePath: \2000\2000\2020\2022.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) {
            return {};
        }

        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < original.size(); ++i) {
            ans[i / n][i % n] = original[i];
        }

        return ans;
    }
};