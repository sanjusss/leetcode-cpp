#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        if (deck.size() < 2)
        {
            return false;
        }

        array<int, 10001> counts;
        counts.fill(0);
        for (int i : deck)
        {
            ++counts[i];
        }

        int last = 0;
        for (int i : counts)
        {
            if (i == 0)
            {
                continue;
            }

            last = gcd(i, last);
            if (last < 2)
            {
                return false;
            }
        }

        return true;
    }

private:
    int gcd(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        else
        {
            return gcd(b, a % b);
        }
    }
};