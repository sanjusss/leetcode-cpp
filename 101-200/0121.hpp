#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        int sell = 0;
        for (int i = prices.size() - 1; i >= 0; --i)
        {
            if (prices[i] < sell)
            {
                profit = max(sell - prices[i], profit);
            }
            else
            {
                sell = prices[i];
            }
        }

        return profit;
    }
};