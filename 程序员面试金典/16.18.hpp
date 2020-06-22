#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool patternMatching(string pattern, string value) 
    {
        if (pattern.empty())
        {
            return value.empty();
        }

        char a = pattern[0];
        char b = a == 'a' ? 'b' : 'a';
        int aCount = 0;
        int bCount = 0;
        int bStart = 0;
        for (int i = 0; i < pattern.size(); ++i)
        {
            if (pattern[i] == a)
            {
                ++aCount;
            }
            else
            {
                ++bCount;
                if (bStart == 0)
                {
                    bStart = i;
                }
            }
        }

        int vSize = value.size();
        string_view vView = value;
        for (int aSize = vSize / aCount; aSize >= 0; --aSize)
        {
            int bSize = bCount > 0 ? (vSize - aSize * aCount) / bCount : 0;
            if (bSize * bCount + aSize * aCount != vSize)
            {
                continue;
            }

            string_view aStr = vView.substr(0, aSize);
            string_view bStr = vView.substr(aSize * bStart, bSize);
            if (bCount > 0 && aStr == bStr)
            {
                continue;
            }

            bool success = true;
            int cur = aSize;
            for (int j = 1; j < pattern.size(); ++j)
            {
                if (pattern[j] == a)
                {
                    if (aStr == vView.substr(cur, aSize))
                    {
                        cur += aSize;
                    }
                    else
                    {
                        success = false;
                        break;
                    }
                }
                else
                {
                    if (bStr == vView.substr(cur, bSize))
                    {
                        cur += bSize;
                    }
                    else
                    {
                        success = false;
                        break;
                    }
                }
            }

            if (success)
            {
                return true;
            }
        }

        return false;
    }
};