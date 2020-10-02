#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int subarraysDivByK(vector<int>& A, int K) 
    {
        int ans = 0;
        vector<int> cs(K);
        cs[0] = 1;
        int r = 0;
        for (int i : A)
        {
            r = (r + i) % K;
            if (r < 0)
            {
                r += K;
            }

            ans += cs[r];
            ++cs[r];
        }

        return ans;
    }
};