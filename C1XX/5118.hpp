#pragma once

#include "leetcode.h"

class Solution 
{
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) 
{
        vector<int> diff(n + 1, 0);
        for (auto& booking : bookings) 
        {
            diff[booking[0] - 1] += booking[2];
            diff[booking[1]] -= booking[2];
        }

        vector<int> results(n);
        results[0] = diff[0];
        for (int i = 1; i < n; ++i) 
        {
            results[i] = results[i - 1] + diff[i];
        }

        return results;
    }
};