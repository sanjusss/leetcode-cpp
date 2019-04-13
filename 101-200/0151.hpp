#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string reverseWords(string s) 
    {
        string temp;
        string res;
        for (auto i : s)
        {
            if (i == ' ')
            {
                if (temp.empty() == false)
                {
                    if (res.empty())
                    {
                        res = temp;
                    }
                    else
                    {
                        res = temp + ' ' + res;
                    }

                    temp.clear();
                }
            }
            else 
            {
                temp += i;
            }
        }

        if (temp.empty() == false)
        {
            if (res.empty())
            {
                res = temp;
            }
            else
            {
                res = temp + ' ' + res;
            }
        }

        return res;
    }
};