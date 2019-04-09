#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool isPowerOfThree(int n) 
    {
        return n > 0 && pow(3, (int)nearbyint(log(n) / log(3))) == n;
    }
};