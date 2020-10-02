#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> lefts;
        for (char i : s)
        {
            switch (i)
            {
            case ')':
                if (lefts.empty() == false && lefts.top() == '(')
                {
                    lefts.pop();
                }
                else
                {
                    return false;
                }

                break;

            case ']':
                if (lefts.empty() == false && lefts.top() == '[')
                {
                    lefts.pop();
                }
                else
                {
                    return false;
                }

                break;

            case '}':
                if (lefts.empty() == false && lefts.top() == '{')
                {
                    lefts.pop();
                }
                else
                {
                    return false;
                }

                break;

            default:
                lefts.push(i);
            }
        }

        return lefts.empty();
    }
};