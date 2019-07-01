#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> pathInZigZagTree(int label) 
    {
        int level = log10(label) / log10(2);
        vector<int> results(level + 1, label);
        for (int i = level - 1; i >= 0; --i)
        {
            label = (1 << (i + 1)) * 3 - 1 - label;
            label /= 2;
            results[i] = label;
        }

        return results;
    }
};