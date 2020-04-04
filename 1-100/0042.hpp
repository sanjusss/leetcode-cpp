#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int trap(vector<int>& height) 
//    {
//        int n = height.size();
//        int ans = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            int left = height[i];
//            for (int j = 0; j < i; ++j)
//            {
//                left = max(height[j], left);
//            }
//
//            int right = height[i];
//            for (int j = i + 1; j < n; ++j)
//            {
//                right = max(height[j], right);
//            }
//
//            ans += min(left, right) - height[i];
//        }
//
//        return ans;
//    }
//};

//class Solution
//{
//public:
//    int trap(vector<int>& height)
//    {
//        int n = height.size();
//        int ans = 0;
//        vector<int> rights(n);
//        int right = 0;
//        for (int i = n - 1; i >= 0; --i)
//        {
//            right = max(right, height[i]);
//            rights[i] = right;
//        }
//
//        int left = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            left = max(left, height[i]);
//            ans += min(left, rights[i]) - height[i];
//        }
//
//        return ans;
//    }
//};

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int n = height.size();
        int ans = 0;
        int left = 0;
        int right = n - 1;
        int left_max = 0;
        int right_max = 0;
        while (left < right)
        {
            if (height[left] < height[right])
            {
                left_max = max(left_max, height[left]);
                ans += left_max - height[left];
                ++left;
            }
            else
            {
                right_max = max(right_max, height[right]);
                ans += right_max - height[right];
                --right;
            }
        }

        return ans;
    }
};