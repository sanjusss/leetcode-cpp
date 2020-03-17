#pragma once
#include "leetcode.h"

//O(logmlogn)
//class Solution 
//{
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) 
//    {
//        int m = matrix.size();
//        if (m == 0)
//        {
//            return false;
//        }
//
//        int n = matrix[0].size();
//        if (n == 0)
//        {
//            return false;
//        }
//
//        int left = 0;
//        int right = m;
//        int mid;
//        while (left < right)
//        {
//            mid = left + (right - left) / 2;
//            if (matrix[mid][0] > target)
//            {
//                right = mid;
//            }
//            else
//            {
//                left = mid + 1;
//            }
//        }
//
//        int endi = left;
//        for (int i = 0; i < endi; ++i)
//        {
//            if (binary_search(matrix[i].begin(), matrix[i].end(), target))
//            {
//                return true;
//            }
//        }
//
//        return false;
//    }
//};

//O(m+n)
class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
        {
            return false;
        }

        int n = matrix[0].size();
        if (n == 0)
        {
            return false;
        }

        int i = m - 1;
        int j = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }

            if (matrix[i][j] > target)
            {
                --i;
            }
            else
            {
                ++j;
            }
        }
        
        return false;
    }
};