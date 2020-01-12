#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> getNoZeroIntegers(int n) 
    {
        int maxI = n / 2;
        for (int i = 1; i <= maxI; ++i)
        {
            if (hasZero(i) == false &&
                hasZero(n - i) == false)
            {
                return { i, n - i };
            }
        }

        return {};
    }

private:
    bool hasZero(int n)
    {
        while (n > 0)
        {
            if (n % 10 == 0)
            {
                return true;
            }

            n /= 10;
        }

        return false;
    }
};