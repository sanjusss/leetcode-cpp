#pragma once
#include "leetcode.h"

class MountainArray 
{
public:
    MountainArray(vector<int>&& nums) :
        m_nums(nums)
    {

    }

    int get(int index)
    {
        return m_nums[index];
    }
    int length()
    {
        return m_nums.size();
    }

private:
    vector<int> m_nums;
};
 

//class Solution 
//{
//public:
//    int findInMountainArray(int target, MountainArray& mountainArr) 
//    {
//        int size = mountainArr.length();
//        int left = 0;
//        int right = size - 1;
//        int top = 0;
//        int vTop = 0;
//        while (left <= right)
//        {
//            top = (left + right) / 2;
//            vTop = mountainArr.get(top);
//            bool asc;
//            if (vTop > mountainArr.get(top - 1))
//            {
//                if (vTop > mountainArr.get(top + 1))
//                {
//                    break;
//                }
//                else
//                {
//                    asc = true;
//                }
//            }
//            else
//            {
//                asc = false;
//            }
//
//            if (vTop > mountainArr.get(left) && asc)
//            {
//                left = top + 1;
//            }
//            else
//            {
//                right = top;
//            }
//        }
//
//        left = 0;
//        right = top;
//        int mid;
//        int vMid;
//        while (left <= right)
//        {
//            mid = (left + right) / 2;
//            vMid = mountainArr.get(mid);
//            if (vMid == target)
//            {
//                return mid;
//            }
//            else if (vMid < target)
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid - 1;
//            }
//        }
//
//        left = top;
//        right = size - 1;
//        while (left <= right)
//        {
//            mid = (left + right) / 2;
//            vMid = mountainArr.get(mid);
//            if (vMid == target)
//            {
//                return mid;
//            }
//            else if (vMid > target)
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

class Solution
{
public:
    int findInMountainArray(int target, MountainArray& mountainArr)
    {
        int size = mountainArr.length();
        int left = 0;
        int right = size - 1;
        int top = 0;
        while (left < right)
        {
            top = (left + right) / 2;
            if (mountainArr.get(top) < mountainArr.get(top + 1))
            {
                left = top + 1;
            }
            else
            {
                right = top - 1;
            }
        }

        top = left;
        left = 0;
        right = top;
        int mid;
        int vMid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            vMid = mountainArr.get(mid);
            if (vMid == target)
            {
                return mid;
            }
            else if (vMid < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        left = top;
        right = size - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            vMid = mountainArr.get(mid);
            if (vMid == target)
            {
                return mid;
            }
            else if (vMid > target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};