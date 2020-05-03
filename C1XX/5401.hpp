#pragma once
#include "leetcode.h"

class Solution
{
public:
    bool kLengthApart(vector<int>& nums, int k)
    {
        int dis = INT_MAX / 2;
        for (int i : nums)
        {
            if (i == 1)
            {
                if (dis < k)
                {
                    return false;
                }

                dis = 0;
            }
            else
            {
                ++dis;
            }
        }

        return true;
    }
};