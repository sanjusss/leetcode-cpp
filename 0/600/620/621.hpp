#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    int leastInterval(vector<char>& tasks, int n) 
//    {
//        if (n <= 0)
//        {
//            return tasks.size();
//        }
//
//        int nums[26] = { 0 };
//        int nexts[26] = { 0 };
//        for (auto i : tasks)
//        {
//            ++nums[i - 'A'];
//        }
//
//        int ans = 0;
//        while (true)
//        {
//            int target = -1;
//            for (int i = 0; i < 26; ++i)
//            {
//                if (nums[i] == 0)
//                {
//                    continue;
//                }
//
//                if (target == -1)
//                {
//                    target = i;
//                }
//                else if (nexts[target] > ans + 1)
//                {
//                    if (nexts[i] < nexts[target])
//                    {
//                        target = i;
//                    }
//                }
//                else if (nexts[i] <= ans + 1)
//                {
//                    if (nums[i] > nums[target])
//                    {
//                        target = i;
//                    }
//                }
//            }
//
//            if (target == -1)
//            {
//                break;
//            }
//            else
//            {
//                --nums[target];
//            }
//
//            if (ans >= nexts[target])
//            {
//                nexts[target] = ans + 1;
//            }
//
//            ans = nexts[target];
//            nexts[target] += n + 1;
//        }
//
//        return ans;
//    }
//};

//class Solution
//{
//public:
//    int leastInterval(vector<char>& tasks, int n)
//    {
//        vector<int> nums(26);
//        for (auto i : tasks)
//        {
//            ++nums[i - 'A'];
//        }
//
//        sort(nums.begin(), nums.end());
//        int max_val = nums[25] - 1;
//        int idle_slots = max_val * n;
//        for (int i = 24; i >= 0 && nums[i] > 0; i--) 
//        {
//            idle_slots -= min(nums[i], max_val);
//        }
//
//        return idle_slots > 0 ? idle_slots + tasks.size() : tasks.size();
//    }
//};

//不排序的方法
class Solution
{
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        vector<int> nums(26);
        for (auto i : tasks)
        {
            ++nums[i - 'A'];
        }

        auto maxi = *max_element(nums.begin(), nums.end());
        int ans = (maxi - 1) * (n + 1);//ans为存在冷却的流程。如果不存在冷却，那么时间应该为任务数。
        for (auto i : nums)
        {
            if (i == maxi)
            {
                ++ans;
            }
        }

        return max(ans, (int)tasks.size());
    }
};