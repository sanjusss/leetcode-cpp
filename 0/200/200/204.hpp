#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int countPrimes(int n) 
    {
        if (n <= 2)
        {
            return 0;
        }

        vector<bool> isp(n, true);
        isp[0] = false;
        isp[1] = false;
        int length = (int)sqrt(n);
        for (int i = 2; i <= length; ++i)
        {
            if (isp[i] == false)
            {
                continue;
            }

            for (int j = i + i; j < n; j += i)
            {
                isp[j] = false;
            }
        }

        return count(isp.cbegin(), isp.cend(), true);
    }
};