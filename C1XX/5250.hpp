#pragma once
#include "leetcode.h"

class Solution 
{
    static int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        else
        {
            return gcd(b, a % b);
        }
    }

public:
    bool isGoodArray(vector<int>& nums) 
    {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            res = gcd(res, nums[i]);
        }

        return res == 1;
    }
};