#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool canThreePartsEqualSum(vector<int>& A) 
    {
        int sum = 0;
        for (int i : A)
        {
            sum += i;
        }

        if (sum % 3 != 0)
        {
            return false;
        }

        int split = sum / 3;
        int count = 0;
        sum = 0;
        for (int i : A)
        {
            sum += i;
            if (sum == split)
            {
                sum = 0;
                ++count;
            }
        }

        return count == 3 || (count > 3 && split == 0);
    }
};