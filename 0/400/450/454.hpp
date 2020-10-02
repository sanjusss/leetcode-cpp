#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        unordered_map<int, int> ab;
        for (int i : A)
        {
            for (int j : B)
            {
                ab[i + j]++;
            }
        }

        int count = 0;
        for (int i : C)
        {
            for (int j : D)
            {
                auto pos = ab.find(-i -j);
                if (pos != ab.end())
                {
                    count += pos->second;
                }
            }
        };

        return count;
    }
};