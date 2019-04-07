#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int myAtoi(string str) 
    {
        int64_t res = 0;
        int64_t sign = 1;
        bool setSign = false;
        bool setValue = false;
        for (auto i : str)
        {
            if (i == ' ')
            {
                if (setSign || setValue)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            else if (i == '-')
            {
                if (setSign || setValue)
                {
                    break;
                }
                else
                {
                    sign = -1;
                    setSign = true;
                }
            }
            else if (i == '+')
            {
                if (setSign || setValue)
                {
                    break;
                }
                else
                {
                    setSign = true;
                }
            }
            else if (isdigit(i))
            {
                res = res * 10 + sign * (i - '0');
                setValue = true;
                if (res < INT32_MIN)
                {
                    res = INT32_MIN;
                    break;
                }
                else if (res > INT32_MAX)
                {
                    res = INT32_MAX;
                    break;
                }
            }
            else
            {
                break;
            }
        }

        return res;
    }
};
