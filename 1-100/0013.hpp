#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int romanToInt(string s) 
    {
        int max = s.length() - 1;
        int res = 0;
        for (int i = 0; i <= max; ++i)
        {
            switch (s[i])
            {
            case 'I':
                if (i < max && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                {
                    res -= 1;
                }
                else
                {
                    res += 1;
                }

                break;

            case 'V':
                res += 5;
                break;

            case 'X':
                if (i < max && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                {
                    res -= 10;
                }
                else
                {
                    res += 10;
                }

                break;

            case 'L':
                res += 50;
                break;

            case 'C':
                if (i < max && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                {
                    res -= 100;
                }
                else
                {
                    res += 100;
                }

                break;

            case 'D':
                res += 500;
                break;

            case 'M':
                res += 1000;
                break;

            default:
                break;
            }
        }

        return res;
    }
};