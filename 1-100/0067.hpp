#pragma once
#include "leetcode.h"

class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        if (b.length() > a.length())
        {
            a.swap(b);
        }

        int remain = 0;
        int res;
        for (int i = a.length() - 1, j = b.length() - 1;
            i >= 0;
            --i, --j)
        {
            res = a[i] + (j >= 0 ? (b[j] - '0') : 0) + remain;
            if (res >= '2')
            {
                a[i] = res - 2;
                remain = 1;
            }
            else
            {
                a[i] = res;
                remain = 0;
            }
        }

        if (remain == 1)
        {
            a = '1' + a;
        }

        return a;
    }
};