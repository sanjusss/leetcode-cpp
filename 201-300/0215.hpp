#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int findKthLargest(vector<int>& nums, int k) 
//    {
//        multiset<int> largest;
//        int size = 0;
//        for (auto i : nums)
//        {
//            if (size < k)
//            {
//                largest.insert(i);
//                ++size;
//            }
//            else if (i > *largest.begin())
//            {
//                largest.erase(largest.begin());
//                largest.insert(i);
//            }
//        }
//
//        return *largest.begin();
//    }
//};

//class Solution
//{
//public:
//    int findKthLargest(vector<int>& nums, int k)
//    {
//        priority_queue<int, vector<int>, greater<int>> q;
//        int size = 0;
//        for (auto i : nums)
//        {
//            if (size < k)
//            {
//                q.push(i);
//                ++size;
//            }
//            else if (i > q.top())
//            {
//                q.pop();
//                q.push(i);
//            }
//        }
//
//        return q.top();
//    }
//};

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        auto minmax = minmax_element(nums.begin(), nums.end());
        int left = *minmax.first;
        int right = *minmax.second;

        int mid;
        int countGreat;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            countGreat = count_if(nums.begin(), nums.end(), [mid](int n) { return n > mid; });
            if (countGreat >= k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};