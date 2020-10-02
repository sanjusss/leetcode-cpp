#pragma once
#include "leetcode.h"

////O(nlogn)
//class Solution 
//{
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
//    {
//        if (nums.empty() || nums.size() < k)
//        {
//            return { };
//        }
//
//        vector<int> ans(nums.size() - k + 1);
//        multiset<int> cur(nums.begin(), next(nums.begin(), k));
//        ans[0] = *cur.rbegin();
//        for (int i = k; i < nums.size(); ++i)
//        {
//            cur.erase(cur.find(nums[i - k]));
//            cur.insert(nums[i]);
//            ans[i - k + 1] = *cur.rbegin();
//        }
//
//        return ans;
//    }
//};

//O(n)
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (nums.empty() || nums.size() < k)
        {
            return { };
        }

        vector<int> ans(nums.size() - k + 1);
        deque<int> cur;//这是一个索引队列，对应的值从大到小排列。
        for (int i = 0; i < nums.size(); ++i)
        {
            if (cur.empty() == false && cur.front() <= i - k)
            {
                cur.pop_front();
            }

            while (cur.empty() == false && nums[cur.back()] < nums[i])
            {
                cur.pop_back();
            }

            cur.push_back(i);
            if (i >= k - 1)
            {
                ans[i - k + 1] = nums[cur.front()];
            }
        }

        return ans;
    }
};