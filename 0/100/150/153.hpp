#pragma once
#include "leetcode.h"

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                return nums[mid + 1];
            }
            else if (nums[mid] < nums[0])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return nums[0];
    }
};