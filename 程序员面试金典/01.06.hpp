#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string compressString(string S) 
    {
        string d;
        char last = 0;
        int count = 0;
        for (auto i : S)
        {
            if (i != last)
            {
                if (count > 0)
                {
                    d += last + to_string(count);
                }

                last = i;
                count = 0;
            }

            ++count;
        }

        if (count > 0)
        {
            d += last + to_string(count);
        }

        if (d.size() >= S.size())
        {
            return S;
        }
        else
        {
            return d;
        }
    }
};