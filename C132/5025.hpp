#pragma once
#include "leetcode.h"

class Solution 
{
public:
    //虽然时间复杂度O(n^3)，但由于空间占用O(1)，节省了申请空间的时间，实际速度很快。
    int longestArithSeqLength(vector<int>& A) 
    {
        int res = 1;
        int length = A.size();
        int interval = 0;
        for (int i = 0; i < length; ++i)
        {
            for (int j = i + 1; j < length; ++j)
            {
                int size = 2;
                int v = A[j] - A[i];
                int next = A[j] + v;
                for (int k = j + 1; k < length; ++k)
                {
                    if (A[k] == next)
                    {
                        next += v;
                        ++size;
                    }
                }

                res = max(res, size);
            }
        }

        return res;
    }
};