#pragma once
#include "leetcode.h"

////直接排序，空间复杂度O(m+n)
//class Solution 
//{
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
//    {
//        vector<int> nums(nums1.size() + nums2.size());
//        copy(nums1.begin(), nums1.end(), nums.begin());
//        copy(nums2.begin(), nums2.end(), nums.begin() + nums1.size());
//        sort(nums.begin(), nums.end());
//        if (nums.size() % 2 == 1)
//        {
//            return nums[(nums.size() - 1) / 2];
//        }
//        else
//        {
//            return (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
//        }
//    }
//};

//合并
//class Solution
//{
//public:
//    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//    {
//        int size1 = nums1.size();
//        int size2 = nums2.size();
//        int i = 0;
//        int j = 0;
//        int mid = (size1 + size2 + 1) / 2;
//        int ans = 0;
//        while (i + j < mid)
//        {
//            if (i < size1)
//            {
//                if (j < size2 && nums1[i] >= nums2[j])
//                {
//                    ++j;
//                    ans = nums2[j];
//                }
//                else
//                {
//                    ++i;
//                    ans = nums1[i];
//                }
//            }
//            else
//            {
//                ++j;
//                ans = nums2[j];
//            }
//        }
//
//        if ((size1 + size2) % 2 == 0)
//        {
//            if (i < size1)
//            {
//                if (j < size2 && nums1[i] >= nums2[j])
//                {
//                    ans += nums2[j];
//                }
//                else
//                {
//                    ans += nums1[i];
//                }
//            }
//            else
//            {
//                ans += nums2[j];
//            }
//
//            return ans / 2.0;
//        }
//        else
//        {
//            return ans;
//        }
//    }
//};

//二分查找，且不改变原数组
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (size1 > size2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        //避免数组大小为0。
        //nums1扩充到size1 * 2 + 1
        //nums2扩充到size2 * 2 + 1
        int left = 0;
        int right = size1 * 2;
        int n1 = 0;
        int n2 = 0;
        int halfSum = size1 + size2;//halfSum=n1+n2
        int maxN1 = size1 * 2;
        int maxN2 = size2 * 2;

        int l1 = 0;
        int l2 = 0;
        int r1 = 0;
        int r2 = 0;
        while (left <= right)
        {
            n1 = left + (right - left) / 2;
            n2 = halfSum - n1;

            l1 = n1 == 0 ? INT_MIN : nums1[(n1 - 1) / 2];
            r1 = n1 == maxN1 ? INT_MAX : nums1[n1 / 2];
            l2 = n2 == 0 ? INT_MIN : nums2[(n2 - 1) / 2];
            r2 = n2 == maxN2 ? INT_MAX : nums2[n2 / 2];
            if (l1 > r2)
            {
                right = n1 - 1;
            }
            else if (l2 > r1)
            {
                left = n1 + 1;
            }
            else
            {
                break;
            }
        }

        return (max(l1, l2) + min(r1, r2)) / 2.0;
    }
};