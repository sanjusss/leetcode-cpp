#pragma once
#include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        int n0;
        int n1;
        int n2;
        for (int i = 1; i < prices.size(); ++i) {
            n0 = max(f0, f2 - prices[i]);
            n1 = f0 + prices[i];
            n2 = max(f1, f2);
            f0 = n0;
            f1 = n1;
            f2 = n2;
        }

        return max({ f0, f1, f2 });
    }
};