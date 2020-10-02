#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        int mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (check(matrix, k, mid, n))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool check(vector<vector<int>>& matrix, int k, int mid, int n)
    {
        int c = 0;
        int i = n - 1;
        int j = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] > mid)
            {
                --i;
            }
            else
            {
                ++j;
                c += i + 1;
            }
        }

        return c >= k;
    }
};