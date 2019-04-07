#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 0)
        {
            return string();
        }

        int length = INT_MAX;
        for (auto& s : strs)
        {
            length = min((int)s.length(), length);
        }

        string res;
        int strCount = strs.size();
        for (int i = 0; i < length; ++i)
        {
            for (int j = 1; j < strCount; ++j)
            {
                if (strs[0][i] != strs[j][i])
                {
                    return res;
                }
            }

            res += strs[0][i];
        }

        return res;
    }
};