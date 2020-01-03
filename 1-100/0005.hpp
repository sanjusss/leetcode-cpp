#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int maxLength = 0;
        int start = 0;
        int size = s.size();

        //i作为中心
        for (int i = 0; i < size; ++i)
        {
            int step = min(i, size - i - 1);
            int j = 0;
            while (++j <= step)
            {
                if (s[i - j] != s[i + j])
                {
                    break;
                }
            }

            int length = 2 * j - 1;
            if (maxLength < length)
            {
                maxLength = length;
                start = i - j + 1;
            }
        }

        //i的右侧作为中心
        for (int i = size - 2; i >= 0; --i)
        {
            int step = min(i + 1, size - i - 1);
            int j = 0;
            while (j < step)
            {
                if (s[i - j] != s[i + j + 1])
                {
                    break;
                }
                else
                {
                    ++j;
                }
            }

            int length = 2 * j;
            if (maxLength < length)
            {
                maxLength = length;
                start = i - j + 1;
            }
        }

        return s.substr(start, maxLength);
    }
};