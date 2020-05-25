#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int maxVowels(string s, int k) 
    {
        bool vowels[CHAR_MAX + 1] = { 0 };
        vowels['a'] = true;
        vowels['e'] = true;
        vowels['i'] = true;
        vowels['o'] = true;
        vowels['u'] = true;

        int ans = 0;
        int cur = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (vowels[s[i]])
            {
                ++cur;
            }

            if (i >= k && vowels[s[i - k]])
            {
                --cur;
            }

            ans = max(cur, ans);
        }

        return ans;
    }
};