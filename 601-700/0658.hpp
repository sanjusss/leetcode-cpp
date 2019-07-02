#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
//    {
//        int length = arr.size();
//        if (length == 0)
//        {
//            return { };
//        }
//
//        int left = 0;
//        int right = length - 1;
//        while (left + 1 < right)
//        {
//            int mid = (left + right) / 2;
//            if (arr[mid] >= x)
//            {
//                right = mid;
//            }
//            else
//            {
//                left = mid;
//            }
//        }
//
//        deque<int> q;
//        for (int i = 0; i < k; i++)
//        {
//            if (left == -1)
//            {
//                q.push_back(arr[right++]);
//            }
//            else if (right == length)
//            {
//                q.push_front(arr[left--]);
//            }
//            else if (x - arr[left] <= arr[right] - x)
//            {
//                q.push_front(arr[left--]);
//            }
//            else
//            {
//                q.push_back(arr[right++]);
//            }
//        }
//
//        return vector<int>(q.begin(), q.end());
//    }
//};
class Solution 
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int left = 0;
        int right = arr.size() - k;

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};