/*
 * @Author: sanjusss
 * @Date: 2023-06-29 08:40:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-29 08:50:31
 * @FilePath: \1000\1200\1250\1253.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(2, vector<int>(n));
        for (int i = 0; i < n && upper >= 0 && lower >= 0; ++i) {
            int sum = colsum[i];
            if (sum == 2) {
                ans[0][i] = 1;
                ans[1][i] = 1;
                --upper;
                --lower;
            }
            else if (sum == 1) {
                if (upper >= lower) {
                    ans[0][i] = 1;
                    --upper;
                }
                else {
                    ans[1][i] = 1;
                    --lower;
                }
            }
        }

        if (upper != 0 || lower != 0) {
            return {};
        }

        return ans;
    }
};