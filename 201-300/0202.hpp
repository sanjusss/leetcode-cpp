#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool isHappy(int n) 
    {
        unordered_set<int> used;
        int sum;
        int temp;
        while (true)
        {
            if (n == 1)
            {
                return true;
            }

            if (used.count(n) > 0)
            {
                return false;
            }
            else
            {
                used.insert(n);
            }

            sum = 0;
            while (n != 0)
            {
                temp = n % 10;
                sum += temp * temp;
                n /= 10;
            }

            n = sum;
        }

        return false;
    }
};