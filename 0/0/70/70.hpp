#pragma once
#include "leetcode.h"

//µü´ú
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }

        int prev2 = 1;
        int prev1 = 2;
        int current;
        for (int i = 3; i <= n; ++i)
        {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};

//µÝ¹é+»º´æ
//class Solution 
//{
//    static map<int, int> nums;
//public:
//    int climbStairs(int n) 
//    {
//        if (nums.find(n) == nums.end())
//        {
//            nums[n] = climbStairs(n - 1) + climbStairs(n - 2);
//        }
//
//        return nums[n];
//    }
//};
//
//map<int, int> Solution::nums = map<int, int>({ make_pair(1, 1), make_pair(2, 2) });