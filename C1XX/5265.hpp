#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        vector<int> r1;
        vector<int> r2;
        for (auto i : nums)
        {
            sum += i;
            switch(i % 3)
            {
            case 1:
                r1.push_back(i);
                break;

            case 2:
                r2.push_back(i);
                break;

            default:
                break;
            }
        }

        int minSub = 0;
        switch (sum % 3)
        {
        case 1:
            minSub = INT_MAX;
            if (r1.size() >= 1)
            {
                minSub = r1[0];
            }

            if (r2.size() >= 2)
            {
                minSub = min(minSub, r2[0] + r2[1]);
            }
            
            minSub = min(minSub, sum);
            break;

        case 2:
            minSub = INT_MAX;
            if (r1.size() >= 2)
            {
                minSub = r1[0] + r1[1];
            }

            if (r2.size() >= 1)
            {
                minSub = min(minSub, r2[0]);
            }

            minSub = min(minSub, sum);
            break;

        default:
            break;
        }

        return sum - minSub;
    }
};