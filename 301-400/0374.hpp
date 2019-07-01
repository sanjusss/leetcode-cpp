#pragma once
#include "leetcode.h"

int guess(int num);

class Solution 
{
public:
    int guessNumber(int n) 
    {
        long left = 1;
        long right = n;
        while (left < right)
        {
            int mid = (left + right + 1) / 2;
            int res = guess(mid);
            if (res == 0)
            {
                return mid;
            }
            else if (res > 0)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};