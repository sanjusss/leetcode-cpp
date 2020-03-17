#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int divide(int dividend, int divisor) 
    {
        if (dividend == 0)
        {
            return 0;
        }

        if (divisor == 1)
        {
            return dividend;
        }

        if (divisor == -1)
        {
            if (dividend == INT_MIN)
            {
                return INT_MAX;
            }
            else
            {
                return -dividend;
            }
        }

        bool sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        vector<pair<long, int64_t>> divisors;
        int64_t a = dividend;
        a = abs(a);
        int64_t b = divisor;
        b = abs(b);
        long k = 1;
        while (b <= a)
        {
            divisors.push_back({ k, b });
            b += b;
            k += k;
        }

        long ans = 0;
        for (int i = divisors.size() - 1; i >= 0 && a > 0; --i)
        {
            if (divisors[i].second <= a)
            {
                a -= divisors[i].second;
                ans += divisors[i].first;
            }
        }

        if (sign == false)
        {
            ans = -ans;
        }

        return ans > INT_MAX ? INT_MAX : ans;
    }
};