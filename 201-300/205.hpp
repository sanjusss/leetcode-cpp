#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        if (s.length() != t.length())
        {
            return false;
        }

        int length = s.length();
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < length; ++i)
        {
            if (s2t.count(s[i]) == 0 && t2s.count(t[i]) == 0)
            {
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            }
            else if (s2t.count(s[i]) == 0 || t2s.count(t[i]) == 0 ||
                s2t[s[i]] != t[i] || t2s[t[i]] != s[i])
            {
                return false;
            }
        }

        return true;
    }
};