#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int findBestValue(vector<int>& arr, int target) 
    {
        int size = arr.size();
        if (size == 0)
        {
            return 0;
        }

        sort(arr.begin(), arr.end());
        int sum = 0;
        for (int i = 0; i < size; ++i)
        {
            int avg = (target - sum) / (size - i);
            if (avg < arr[i])
            {
                double dAvg = double(target - sum) / double(size - i);
                if (dAvg - avg > 0.5)
                {
                    return avg + 1;
                }
                else
                {
                    return avg;
                }
            }
            else
            {
                sum += arr[i];
            }
        }

        return arr.back();
    }
};