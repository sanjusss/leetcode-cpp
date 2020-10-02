#pragma once
#include "leetcode.h"

////µÝ¹é·½·¨
//class Solution 
//{
//public:
//    int findTargetSumWays(vector<int>& nums, int S) 
//    {
//        return bfs(nums, S, nums.size() - 1);
//    }
//
//private:
//    int bfs(vector<int>& nums, int64_t S, int i)
//    {
//        if (i == -1)
//        {
//            return S == 0 ? 1 : 0;
//        }
//
//        return bfs(nums, S - (int64_t)nums[i], i - 1) + bfs(nums, S + (int64_t)nums[i], i - 1);
//    }
//};