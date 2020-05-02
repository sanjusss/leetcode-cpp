#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minArray(vector<int>& numbers) 
    {
        int left = 0;
        int right = numbers.size() - 1;
        int mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (numbers[mid] == numbers[right])
            {
                --right;
            }
            else if (numbers[mid] > numbers[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return numbers[left];
    }
};