#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        if (nums.size() % k != 0)
        {
            return false;
        }

        map<int, int> numsCount;
        for (int i : nums)
        {
            ++numsCount[i];
        }

        while (numsCount.size() > 0)
        {
            int num = 0;
            for (int i = 0; i < k; ++i)
            {
                if (num == 0)
                {
                    num = numsCount.begin()->first;
                }
                else
                {
                    ++num;
                }

                if (numsCount.find(num) == numsCount.end())
                {
                    return false;
                }
                else
                {
                    --numsCount[num];
                    if (numsCount[num] == 0)
                    {
                        numsCount.erase(num);
                    }
                }
            }
        }

        return true;
    }
};