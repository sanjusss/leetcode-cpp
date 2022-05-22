/*
 * @Author: sanjusss
 * @Date: 2022-05-22 10:29:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-22 10:49:21
 * @FilePath: \C\C200\C290\C294\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        if (n < 3) {
            return n - 1;
        }

        sort(stockPrices.begin(), stockPrices.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });

        int ans = 1;
        int a = 0;
        int b = 1;
        for (int i = 2; i < n; ++i) {
            int64_t x1 = stockPrices[a][0];
            int64_t y1 = stockPrices[a][1];
            int64_t x2 = stockPrices[b][0];
            int64_t y2 = stockPrices[b][1];
            int64_t x3 = stockPrices[i][0];
            int64_t y3 = stockPrices[i][1];
            if ((y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1) != 0) {
                ++ans;
                a = i - 1;
                b = i;
            }
        }

        return ans;
    }
};

TEST(&Solution::minimumLines)