#pragma once
#include "leetcode.h"

//实现加法器 https://zh.wikipedia.org/wiki/%E5%8A%A0%E6%B3%95%E5%99%A8
class Solution 
{
public:
    int getSum(int a, int b) 
    {
        int base = 1;
        int ans = 0;
        bool cbit = false;
        for (int i = 0; i < 32; ++i)
        {
            if ((a & base) == 0)
            {
                if ((b & base) == 0)
                {
                    if (cbit)
                    {
                        ans |= base;
                        cbit = false;
                    }
                    else
                    {
                        cbit = false;
                    }
                }
                else
                {
                    if (cbit)
                    {
                        cbit = true;
                    }
                    else
                    {
                        ans |= base;
                        cbit = false;
                    }
                }
            }
            else
            {
                if ((b & base) == 0)
                {
                    if (cbit)
                    {
                        cbit = true;
                    }
                    else
                    {
                        ans |= base;
                        cbit = false;
                    }
                }
                else
                {
                    if (cbit)
                    {
                        ans |= base;
                        cbit = true;
                    }
                    else
                    {
                        cbit = true;
                    }
                }
            }

            if (i != 31)
            {
                base <<= 1;
            }
        }

        return ans;
    }
};