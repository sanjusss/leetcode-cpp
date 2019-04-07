#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int strStr(string haystack, string needle) 
    {
        int nLength = needle.length();
        if (nLength == 0)
        {
            return 0;
        }

        int hLength = haystack.length();
        int iMax = hLength - nLength;
        bool success;
        for (int i = 0; i <= iMax; ++i)
        {
            success = true;
            for (int j = 0; j < nLength; ++j)
            {
                if (haystack[i + j] != needle[j])
                {
                    success = false;
                    break;
                }
            }

            if (success)
            {
                return i;
            }
        }

        return -1;
    }
};