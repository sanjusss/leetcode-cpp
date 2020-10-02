#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        int size = prices.size();
        vector<int> ans(size);
        stack<int> s;
        for (int i = 0; i < size; ++i)
        {
            while (!s.empty() && prices[i] <= prices[s.top()])
            {
                ans[s.top()] = prices[s.top()] - prices[i];
                s.pop();
            }

            s.push(i);
        }

        while (!s.empty())
        {
            ans[s.top()] = prices[s.top()];
            s.pop();
        }

        return ans;
    }
};