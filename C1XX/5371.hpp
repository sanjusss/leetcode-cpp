#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int findGoodStrings(int n, string s1, string s2, string evil) 
    {
        int mod = 1000000007;
        if (s2 >= s1)
        {
            return 0;
        }

        int common = 0;
        while (common < n && s1[common] == s2[common])
        {
            ++common;
        }

        string pub = s1.substr(0, common);
        if (pub.find(evil) != string::npos)
        {
            return 0;
        }

        int ans = 0;

        return ans;
    }
};