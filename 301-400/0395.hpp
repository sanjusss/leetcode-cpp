#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int longestSubstring(string s, int k) 
    {
        return longestSubstring(s, k, 0, s.size() - 1);
    }

private:
    int longestSubstring(string& s, int k, int start, int end)
    {
        unordered_map<char, int> cs;
        for (int i = start; i <= end; ++i)
        {
            ++cs[s[i]];
        }

        unordered_set<char> useless;
        for (auto i = cs.begin(); i != cs.end(); ++i)
        {
            if (i->second < k)
            {
                useless.insert(i->first);
            }
        }

        if (useless.empty())
        {
            return end - start + 1;
        }
        else
        {
            int res = 0;
            int last = start - 1;
            int i;
            for (i = start; i <= end; ++i)
            {
                if (useless.find(s[i]) == useless.end())
                {
                    continue;
                }

                if (last != i - 1)
                {
                    res = max(res, longestSubstring(s, k, last + 1, i - 1));
                }

                last = i;
            }

            if (last != i - 1)
            {
                res = max(res, longestSubstring(s, k, last + 1, i - 1));
            }

            return res;
        }
    }
};