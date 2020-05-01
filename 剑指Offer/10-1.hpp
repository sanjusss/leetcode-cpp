#pragma once
#include "leetcode.h"

class Solution
{
public:
    int fib(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        if (n == 1)
        {
            return 1;
        }

        int fn_1 = 1;
        int fn_2 = 0;
        int fn = 0;
        int mod = 1000000007;
        for (int i = 2; i <= n; ++i)
        {
            fn = fn_1 + fn_2;
            fn %= mod;
            fn_2 = fn_1;
            fn_1 = fn;
        }

        return fn;
    }
};