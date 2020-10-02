#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        int lefts = 0;
        vector<int> ans;
        for (auto c : seq)
        {
            if (c == '(')
            {
                ++lefts;
                ans.push_back(lefts % 2);
            }
            else
            {
                ans.push_back(lefts % 2);
                --lefts;
            }

        }

        return ans;
    }
};