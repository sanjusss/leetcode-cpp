#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) 
    {
        int temp = tomatoSlices - 2 * cheeseSlices;
        if (temp < 0 || temp % 2 == 1 || cheeseSlices * 2 < temp)
        {
            return vector<int>();
        }

        return { temp / 2, cheeseSlices - temp / 2 };
    }
};