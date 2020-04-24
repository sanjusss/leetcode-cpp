#pragma once
#include "leetcode.h"

//O(n^2)
//class Solution 
//{
//public:
//    int reversePairs(vector<int>& nums) 
//    {
//        int n = nums.size();
//        int ans = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = i + 1; j < n; ++j)
//            {
//                if (nums[i] > nums[j])
//                {
//                    ++ans;
//                }
//            }
//        }
//
//        return ans;
//    }
//};

////O(nlogn)
//class Solution
//{
//public:
//    int reversePairs(vector<int>& nums)
//    {
//        multiset<int> prevs;
//        int ans = 0;
//        for (int i : nums)
//        {
//            ans += distance(prevs.insert(i), prevs.end()) - 1;
//        }
//
//        return ans;
//    }
//};

////O(nlogn)
//class Solution
//{
//public:
//    int reversePairs(vector<int>& nums)
//    {
//        vector<int> prevs;
//        prevs.reserve(nums.size());
//        int ans = 0;
//        for (int i : nums)
//        {
//            auto pos = upper_bound(prevs.begin(), prevs.end(), i);
//            ans += distance(pos, prevs.end());
//            prevs.insert(pos, i);
//        }
//
//        return ans;
//    }
//};

//O(nlogn)
class Solution
{
public:
    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2)
        {
            return 0;
        }

        vector<int> temps(n);
        return mergeSort(nums, 0, n - 1, temps);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right, vector<int>& temps)
    {
        if (left == right)
        {
            return 0;
        }

        int mid = (left + right) / 2;
        int ans = mergeSort(nums, left, mid, temps) + mergeSort(nums, mid + 1, right, temps);
        int p = left;
        int q = mid + 1;
        for (int cur = left; cur <= right; ++cur)
        {
            if (p > mid || (q <= right && nums[q] < nums[p]))
            {
                temps[cur] = nums[q++];
                ans += mid + 1 - p;
            }
            else
            {
                temps[cur] = nums[p++];
            }
        }

        copy(temps.begin() + left, temps.begin() + right + 1, nums.begin() + left);
        return ans;
    }
};