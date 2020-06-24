#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX / 2;
        int n = nums.size();
        int temp;
        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                temp = nums[i] + nums[left] + nums[right];
                if (temp == target)
                {
                    return target;
                }
                else if (abs(ans - target) > abs(temp - target))
                {
                    ans = temp;
                }

                if (temp > target)
                {
                    --right;
                }
                else
                {
                    ++left;
                }
            }
        }

        return ans;
    }
};