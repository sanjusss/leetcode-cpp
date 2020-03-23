#pragma once
#include "leetcode.h"

class Solution 
{
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) 
    {
        auto AEnd = next(A.begin(), m - 1);
        for (auto i : B)
        {
            ++AEnd;
            auto pos = upper_bound(A.begin(), AEnd, i);
            for (auto j = AEnd; j != pos; --j)
            {
                *j = *prev(j);
            }

            *pos = i;
        }
    }
};