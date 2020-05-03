#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int longestSubarray(vector<int>& nums, int limit) 
    {
        int ans = 0;
        int start = -1;
        deque<int> maxs;
        deque<int> mins;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (maxs.empty() == false &&
                nums[maxs.back()] < nums[i])
            {
                maxs.pop_back();
            }

            maxs.push_back(i);

            while (mins.empty() == false &&
                nums[mins.back()] > nums[i])
            {
                mins.pop_back();
            }

            mins.push_back(i);

            while (maxs.empty() == false &&
                mins.empty() == false &&
                nums[maxs.front()] - nums[mins.front()] > limit)
            {
                if (maxs.front() < mins.front())
                {
                    start = maxs.front();
                    maxs.pop_front();
                }
                else
                {
                    start = mins.front();
                    mins.pop_front();
                }
            }

            ans = max(ans, i - start);
        }

        return ans;
    }
};