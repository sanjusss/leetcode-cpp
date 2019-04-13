#pragma once
#include "leetcode.h"

class Solution 
{
public:
    //空间使用为O(K)
    vector<int> getRow(int rowIndex) 
    {
        vector<int> n(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; ++i)
        {
            for (int j = i - 1; j >= 1; --j)
            {
                n[j] = n[j - 1] + n[j];
            }
        }

        return n;
    }
    //空间使用为O(2K-1)
    //vector<int> getRow(int rowIndex)
    //{
    //    vector<int> prev(1, 1);
    //    vector<int> current;
    //    int mid;
    //    for (int i = 1; i <= rowIndex; ++i)
    //    {
    //        current = vector<int>(i + 1, 1);
    //        mid = i / 2;
    //        for (int j = 1; j <= mid; ++j)
    //        {
    //            current[j] = prev[j - 1] + prev[j];
    //            current[i - j] = current[j];
    //        }

    //        prev.swap(current);
    //    }

    //    return prev;
    //}
};