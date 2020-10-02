#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int findTheLongestSubstring(string s) 
    {
        int n = s.size();
        unordered_map<char, int> odds =
        {
            { 'a', 1 },
            { 'e', 2 },
            { 'i', 4 },
            { 'o', 8 },
            { 'u', 16 },
        };
        int status = 0;
        int ans = 0;
        vector<int> pts(32, -1);
        pts[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            if (odds.find(s[i]) != odds.end())
            {
                status ^= odds[s[i]];
            }

            if (pts[status] == -1)
            {
                pts[status] = i + 1;
            }
            else
            {
                ans = max(ans, i + 1 - pts[status]);
            }
        }

        return ans;
    }
};