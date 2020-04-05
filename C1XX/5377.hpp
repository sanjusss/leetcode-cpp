#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int numSteps(string s) 
    {
        int ans = 0;
        static const string one = "1";
        while (s != one)
        {
            ++ans;
            if (s.back() == '0')
            {
                s.erase(prev(s.end()));
            }
            else
            {
                bool add1 = true;
                for (auto i = s.rbegin(); i != s.rend() && add1; ++i)
                {
                    if (*i == '0')
                    {
                        *i = '1';
                        add1 = false;
                    }
                    else
                    {
                        *i = '0';
                    }
                }

                if (add1)
                {
                    s.insert(s.begin(), '1');
                }
            }
        }

        return ans;
    }
};