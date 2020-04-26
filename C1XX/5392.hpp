#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxScore(string s) 
    {
        int left = 0;
        int right = 0;
        for (auto i : s)
        {
            if (i == '1')
            {
                ++right;
            }
        }

        int ans = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (s[i] == '1')
            {
                --right;
            }
            else
            {
                ++left;
            }

            ans = max(ans, left + right);
        }

        return ans;
    }
};