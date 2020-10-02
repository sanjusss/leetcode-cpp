#pragma once
#include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1st = 0;
        int none1st = 0;
        int hold2nd = 0;
        int none2st = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (i == 0) {
                hold1st = -prices[i];
            }
            else if (i == 1) {
                none1st = max(none1st, hold1st + prices[i]);
                hold1st = max(hold1st, -prices[i]);
            }
            else if (i == 2) {
                hold2nd = -prices[0] + prices[1] - prices[2];
                none1st = max(none1st, hold1st + prices[i]);
                hold1st = max(hold1st, -prices[i]);
            }
            else {
                none2st = max(none2st, hold2nd + prices[i]);
                hold2nd = max(hold2nd, none1st - prices[i]);
                none1st = max(none1st, hold1st + prices[i]);
                hold1st = max(hold1st, -prices[i]);
            }
        }

        return max({ hold1st, none1st, hold2nd, none2st });
    }
};