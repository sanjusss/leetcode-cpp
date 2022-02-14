/*
 * @Author: sanjusss
 * @Date: 2022-02-14 13:22:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-14 13:33:03
 * @FilePath: \0\200\260\265.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int k = costs[0].size();
        int prev1color = -1;
        int prev1cost = 0;
        int prev2cost = 0;
        for (auto& c : costs) {
            int cur1color = -1;
            int cur1cost = INT_MAX;
            int cur2cost = INT_MAX;
            for (int i = 0; i < k; ++i) {
                int cost = c[i] + (prev1color == i ? prev2cost : prev1cost);
                if (cost < cur1cost) {
                    cur2cost = cur1cost;
                    cur1cost = cost;
                    cur1color = i;
                }
                else if (cost < cur2cost) {
                    cur2cost = cost;
                }
            }

            prev1color = cur1color;
            prev1cost = cur1cost;
            prev2cost = cur2cost;
        }

        return prev1cost;
    }
};