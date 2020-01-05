#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> charCount;
        for (auto i : s)
        {
            ++charCount[i];
        }

        int doubleLength = 0;
        int singleLength = 0;
        for (auto& p : charCount)
        {
            if (p.second % 2 == 0)
            {
                doubleLength += p.second;
            }
            else
            {
                doubleLength += p.second - 1;
                if (singleLength == 0)
                {
                    ++singleLength;
                }
            }
        }

        return doubleLength + singleLength;
    }
};