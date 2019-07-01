#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int numKLenSubstrNoRepeats(string S, int K) 
    {
        int pos[CHAR_MAX - CHAR_MIN + 1] = { 0 };
        int size = S.size();
        if (size < K)
        {
            return 0;
        }

        int count = 0;
        int start = 0;
        for (int i = 0; i < size; ++i)
        {
            if (pos[S[i]] > start)
            {
                start = pos[S[i]];
            }

            if (i - start + 1 >= K)
            {
                ++count;
            }

            pos[S[i]] = i + 1;
        }

        return count;
    }
};