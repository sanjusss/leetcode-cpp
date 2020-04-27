#pragma once
#include "leetcode.h"

class Solution
{
public:
    string replaceSpace(string s)
    {
        vector<char> ans(s.size() * 3);
        int size = 0;
        for (char i : s)
        {
            if (i == ' ')
            {
                ans[size++] = '%';
                ans[size++] = '2';
                ans[size++] = '0';
            }
            else
            {
                ans[size++] = i;
            }
        }

        return string(ans.begin(), ans.begin() + size);
    }
};