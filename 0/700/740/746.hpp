#pragma once
#include "leetcode.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev = 0;
        int cur = 0;
        for (int i = 1; i < n; ++i) {
            tie(cur, prev) = make_tuple(min(prev + cost[i - 1], cur + cost[i]), cur);
        }

        return cur;
    }
};