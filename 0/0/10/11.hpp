#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int maxArea(vector<int>& height) 
//    {
//        int ans = 0;
//        for (int i = height.size() - 1; i > 0; --i)
//        {
//            for (int j = 0; j < i; ++j)
//            {
//                if (height[j] >= height[i])
//                {
//                    ans = max((i - j) * height[i], ans);
//                    break;
//                }
//            }
//        }
//
//        for (int i = 0; i < height.size() - 1; ++i)
//        {
//            for (int j = height.size() - 1; j >= i; --j)
//            {
//                if (height[j] >= height[i])
//                {
//                    ans = max((j - i) * height[i], ans);
//                    break;
//                }
//            }
//        }
//
//        return ans;
//    }
//};

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int ans = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i != j)
        {
            if (height[i] < height[j])
            {
                ans = max((j - i) * height[i], ans);
                ++i;
            }
            else
            {
                ans = max((j - i) * height[j], ans);
                --j;
            }
        }

        return ans;
    }
};