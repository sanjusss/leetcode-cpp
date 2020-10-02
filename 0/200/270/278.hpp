#pragma once
#include "leetcode.h"

bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int start = 1;
        int end = n;
        int mid;
        while (start < end)
        {
            mid = (end - start) / 2 + start;
            if (isBadVersion(mid))
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return start;
    }
};

bool isBadVersion(int)
{
    return true;
}