#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int findDuplicate(vector<int>& nums) 
//    {
//        int n = nums.size() - 1;
//        int left = 1;
//        int right = n;//n
//        while (left <= right)
//        {
//            int count = 0;
//            int greater = 0;
//            int mid = (left + right) / 2;
//            for (auto i : nums)
//            {
//                if (i == mid)
//                {
//                    ++count;
//                }
//                else if (i > mid)
//                {
//                    ++greater;
//                }
//            }
//
//            if (count > 1)
//            {
//                return mid;
//            }
//
//            if (greater > n - mid)
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid - 1;
//            }
//        }
//
//        return -1;
//    }
//};

//修改数组的方法
//class Solution
//{
//public:
//    int findDuplicate(vector<int>& nums)
//    {
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            while (nums[i] != nums[nums[i]])
//            {
//                swap(nums[i], nums[nums[i]]);
//            }
//        }
//
//        return nums[0];
//    }
//};

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = 0;
        int fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = 0;
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
}; 