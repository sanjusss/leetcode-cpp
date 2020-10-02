#pragma once
#include "leetcode.h"

//O(logm+logn)=O(logmn)
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
//        return left > 0 &&
//            binary_search(matrix[left - 1].begin(), matrix[left - 1].end(), target);
//    }
//};

//O(logmn)
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

        int left = 0;
        int right = m * n;
        int mid;
        int i;
        int j;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            i = mid / n;
            j = mid % n;
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }
};