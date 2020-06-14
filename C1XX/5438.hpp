#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int n = bloomDay.size();
        if (n < m * k)
        {
            return -1;
        }

        int left = 0;
        int right = (int)1e9;
        int mid;
        int prevBloom;
        int cur;
        while (left < right)
        {
            mid = (left + right) / 2;
            prevBloom = 0;
            cur = 0;
            for (int i : bloomDay)
            {
                if (i > mid)
                {
                    prevBloom = 0;
                }
                else
                {
                    ++prevBloom;
                    if (prevBloom == k)
                    {
                        prevBloom = 0;
                        ++cur;
                        if (cur == m)
                        {
                            break;
                        }
                    }
                }
            }

            if (cur == m)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }
};