#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        string res = "0";
        if (num1.size() < num2.size())
        {
            num1.swap(num2);
        }

        int maxBit = num2.size();
        for (int i = 0; i < maxBit; ++i)
        {
            string mid = multiplyBit(num1, num2[maxBit - 1 - i],i);
            res = plus(res, mid);
        }

        while (res.empty() == false && res[0] == '0')
        {
            res.erase(0);
        }

        return res.empty() ? "0" : res;
    }

private:
    string plus(string num1, string num2)
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

    string multiplyBit(string num, char bit, int base)
    {
        string res;
        int size = num.size();
        int next = 0;
        int n = bit - '0';
        for (int i = 0; i < size; ++i)
        {
            next += (num[size - 1 - i] - '0') * n;
            res.insert(0, 1, '0' + next % 10);
            next /= 10;
        }

        if (next > 0)
        {
            res.insert(0, 1, '0' + next);
        }

        return res.empty() ? "0" : res.insert(res.size(), base, '0');
    }
};