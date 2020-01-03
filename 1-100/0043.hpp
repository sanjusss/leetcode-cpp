#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    string multiply(string num1, string num2) 
//    {
//        string res = "0";
//        if (num1.size() < num2.size())
//        {
//            num1.swap(num2);
//        }
//
//        int maxBit = num2.size();
//        for (int i = 0; i < maxBit; ++i)
//        {
//            string mid = multiplyBit(num1, num2[maxBit - 1 - i],i);
//            res = plus(res, mid);
//        }
//
//        while (res.empty() == false && res[0] == '0')
//        {
//            res.erase(0);
//        }
//
//        return res.empty() ? "0" : res;
//    }
//
//private:
//    string plus(string num1, string num2)
//    {
//        string res;
//        int next = 0;
//        int num1Size = num1.size();
//        int num2Size = num2.size();
//        for (int i = 0; i < num1Size || i < num2Size; ++i)
//        {
//            next += i < num1Size ? (num1[num1Size - 1 - i] - '0') : 0;
//            next += i < num2Size ? (num2[num2Size - 1 - i] - '0') : 0;
//            res.insert(0, 1, '0' + next % 10);
//            next /= 10;
//        }
//
//        if (next > 0)
//        {
//            res.insert(0, 1, '0' + next);
//        }
//
//        return res.empty() ? "0" : res;
//    }
//
//    string multiplyBit(string num, char bit, int base)
//    {
//        string res;
//        int size = num.size();
//        int next = 0;
//        int n = bit - '0';
//        for (int i = 0; i < size; ++i)
//        {
//            next += (num[size - 1 - i] - '0') * n;
//            res.insert(0, 1, '0' + next % 10);
//            next /= 10;
//        }
//
//        if (next > 0)
//        {
//            res.insert(0, 1, '0' + next);
//        }
//
//        return res.empty() ? "0" : res.insert(res.size(), base, '0');
//    }
//};

//class Solution 
//{
//public:
//    string multiply(string num1, string num2) 
//    {
//        int num1Size = num1.size();
//        int num2Size = num2.size();
//        map<int, int> bits;
//        for (int i = 0; i < num1Size; ++i)
//        {
//            for (int j = 0; j < num2Size; ++j)
//            {
//                bits[i + j] += (num1[num1Size - 1 - i] - '0') * (num2[num2Size - 1 - j] - '0');
//            }
//        }
//
//        for (int i = 0; i < num1Size + num2Size - 1; ++i)
//        {
//            bits[i + 1] += bits[i] / 10;
//            bits[i] = bits[i] % 10;
//        }
//
//        string res;
//        for (auto i = bits.rbegin(); i != bits.rend(); ++i)
//        {
//            if (res.empty() && i->second == 0)
//            {
//                continue;
//            }
//
//            res.push_back('0' + i->second);
//        }
//
//        return res.empty() ? "0" : res;
//    }
//};
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int num1Size = num1.size();
        int num2Size = num2.size();
        int resSize = num1Size + num2Size;
        string res(resSize, '0');
        for (int i = num1Size - 1; i >= 0; --i)
        {
            for (int j = num2Size - 1; j >= 0; --j)
            {
                int n = (int)(res[1 + i + j] - '0') + (int)(num1[i] - '0') * (int)(num2[j] - '0');
                res[i + j] += n / 10;
                res[1 + i + j] = n % 10 + '0';
            }
        }

        for (int i = 0; i < resSize; ++i)
        {
            if (res[i] != '0')
            {
                return res.substr(i);
            }
        }

        return "0";
    }
};