#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool divisorGame(int N) 
    {
        set<int> fails;
        for (int i = 1; i <= N; ++i)
        {
            if (fails.find(i - 1) != fails.end())
            {
                continue;
            }

            bool failed = true;
            for (auto j = fails.cbegin(); j != fails.cend(); ++j)
            {
                if (i % (i - (*j)) == 0)
                {
                    failed = false;
                    break;
                }
            }

            if (failed)
            {
                fails.insert(i);
            }
        }

        return fails.find(N) == fails.end();
    }
};