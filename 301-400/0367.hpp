#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool isPerfectSquare(int num) 
    {
        long left = 1;
        long right = num;
        while (left <= right)
        {
            long mid = (left + right) / 2;
            long value = mid * mid;
            if (value == num)
            {
                return true;
            }
            else if (value > num)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }
};