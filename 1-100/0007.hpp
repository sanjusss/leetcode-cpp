#include "leetcode.h"

class Solution 
{
public:
    int reverse(int x) 
    {
        int64_t res = 0;
        int64_t v = x;
        bool sign = v >= 0;
        v = abs(v);
        while (v != 0)
        {
            res = res * 10 + v % 10;
            v /= 10;
        }

        if (sign == false)
        {
            res = -res;
        }

        if (res < INT32_MIN || res > INT32_MAX)
        {
            return 0;
        }
        else
        {
            return res;
        }
    }
};