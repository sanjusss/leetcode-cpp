#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int twoSumLessThanK(vector<int>& A, int K) 
    {
        multiset<int> nums(A.begin(), A.end());
        auto mid = nums.lower_bound((K + 1) / 2);
        int sum = -1;
        for (auto i = nums.begin(); i != mid; ++i)
        {
            int a = *i;
            auto maxpos = nums.lower_bound(K - a);
            if (maxpos == nums.begin())
            {
                continue;
            }

            auto bpos = prev(maxpos);
            if (i == bpos)
            {
                continue;
            }

            sum = max(sum, a + *bpos);
        }

        return sum;
    }
};