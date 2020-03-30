#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int lastRemaining(int n, int m) 
    {
        if (n == 1)
        {
            return 0;
        }
        else
        {
            return (lastRemaining(n - 1, m) + m) % n;
        }
    }
};