#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        vector<int> indexs;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 2 == 1)
            {
                indexs.push_back(i);
            }
        }

        int res = 0;
        for (int i = k - 1; i < indexs.size(); ++i)
        {
            int start = i - k;
            int front = 0;
            if (start == -1)
            {
                front = indexs[0] + 1;
            }
            else
            {
                front = indexs[start + 1] - indexs[start];
            }

            int end = i + 1;
            int back = 0;
            if (end == indexs.size())
            {
                back = nums.size() - indexs[i];
            }
            else
            {
                back = indexs[end] - indexs[i];
            }

            res += front * back;
        }

        return res;
    }
};