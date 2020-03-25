#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<vector<int>> findContinuousSequence(int target) 
    {
        vector<vector<int>> ans;
        for (int i = target / 2; i >= 2; --i)
        {
            int start;
            if (i % 2 == 0)
            {
                if (target * 2 % i != 0 || target % i == 0)
                {
                    continue;
                }

                start = ((target * 2 / i) - 1) / 2 - i / 2 + 1;
            }
            else
            {
                if (target % i != 0)
                {
                    continue;
                }

                start = target / i - i / 2;
            }
            if (start <= 0)
            {
                continue;
            }

            vector<int> s(i);
            for (int j = 0; j < i; ++j)
            {
                s[j] = start + j;
            }

            ans.push_back(s);
        }

        return ans;
    }
};