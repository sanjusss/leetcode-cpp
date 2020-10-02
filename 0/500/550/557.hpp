#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string reverseWords(string s) 
    {
        int start = -1;
        int end;
        int length = s.length();
        for (int i = 0; i <= length; ++i)
        {
            if (i == length || s[i] == ' ')
            {
                if (start != -1)
                {
                    end = i - 1;
                    while (start < end)
                    {
                        swap(s[start++], s[end--]);
                    }

                    start = -1;
                }
            }
            else if (start == -1)
            {
                start = i;
            }
        }

        return s;
    }
};