#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        string res;
        int next = 0;
        int num1Size = num1.size();
        int num2Size = num2.size();
        for (int i = 0; i < num1Size || i < num2Size; ++i)
        {
            next += i < num1Size ? (num1[num1Size - 1 - i] - '0') : 0;
            next += i < num2Size ? (num2[num2Size - 1 - i] - '0') : 0;
            res.insert(0, 1, '0' + next % 10);
            next /= 10;
        }

        if (next > 0)
        {
            res.insert(0, 1, '0' + next);
        }

        return res.empty() ? "0" : res;
    }
};