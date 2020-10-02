#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int rob(vector<int>& nums) 
//    {
//        int n = nums.size();
//        if (n <= 0)
//        {
//            return 0;
//        }
//        else if (n == 1)
//        {
//            return nums[0];
//        }
//
//        int prev2 = 0;
//        int prev1 = nums[0];
//        int res = prev1;
//        for (int i = 1; i < n; ++i)
//        {
//            res = max(prev2 + nums[i], prev1);
//            prev2 = prev1;
//            prev1 = res;
//        }
//
//        return res;
//    }
//};

class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        vector<int> dp1(nums.size() + 1, 0);//¥≥»Î
        vector<int> dp2(nums.size() + 1, 0);//≤ª¥≥»Î
        for (int i = 1; i <= nums.size(); ++i)
        {
            dp1[i] = dp2[i - 1] + nums[i - 1];
            dp2[i] = max(dp1[i - 1], dp2[i - 1]);
        }

        return max(dp1[nums.size()], dp2[nums.size()]);
    }
};