#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int nextGreaterElement(int n) 
//    {
//        vector<int> bits;
//        while (n > 0)
//        {
//            bits.push_back(n % 10);
//            n /= 10;
//        }
//
//        reverse(bits.begin(), bits.end());
//        if (next_permutation(bits.begin(), bits.end()))
//        {
//            int64_t ans = 0;
//            for (int i : bits)
//            {
//                ans = ans * 10 + i;
//            }
//
//            return ans > INT32_MAX ? -1 : ans;
//        }
//        else
//        {
//            return -1;
//        }
//    }
//};

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        vector<int> bits;
        while (n > 0)
        {
            bits.push_back(n % 10);
            n /= 10;
        }

        if (bits.size() > 1)
        {
            reverse(bits.begin(), bits.end());
            for (auto i = prev(bits.end()); i != bits.begin(); --i)
            {
                auto j = prev(i);
                if (*j < *i)
                {
                    for (auto i2 = prev(bits.end()); i2 != j; --i2)
                    {
                        if (*j < *i2)
                        {
                            swap(*j, *i2);
                            reverse(j + 1, bits.end());
                            break;
                        }
                    }

                    int64_t ans = 0;
                    for (int k : bits)
                    {
                        ans = ans * 10 + k;
                    }

                    return ans > INT32_MAX ? -1 : ans;
                }
            }
        }

        return -1;
    }
};