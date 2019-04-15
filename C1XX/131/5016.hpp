#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string removeOuterParentheses(string S) 
    {
        string res;
        int left = 0;
        for (auto i : S)
        {
            if (i == '(')
            {
                if (left != 0)
                {
                    res += i;
                }

                ++left;
            }
            else
            {
                --left; 
                if (left != 0)
                {
                    res += i;
                }
            }
        }

        return res;
    }
};