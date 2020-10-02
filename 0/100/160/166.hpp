#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        if (numerator == 0)
        {
            return "0";
        }

        int64_t a = numerator;
        int64_t b = denominator;
        if (a % b == 0)
        {
            return to_string(a / b);
        }

        bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = abs(a);
        b = abs(b);

        unordered_map<int64_t, size_t> remains;
        long r = a % b;
        string ans = to_string(a / b) + ".";
        string d;
        for (int i = 0; r > 0; ++i)
        {
            r *= 10;
            if (remains.find(r) == remains.end())
            {
                d += to_string(r / b);
                remains[r] = i;
                r %= b;
            }
            else
            {
                d.insert(remains[r], "(");
                d += ")";
                break;
            }
        }

        ans += d;
        if (sign == false)
        {
            ans = '-' + ans;
        }

        return ans;
    }
};