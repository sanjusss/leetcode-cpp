#pragma once
#include "leetcode.h"

//超时
//class Solution
//{
//public:
//    int maxEqualFreq(vector<int>& nums)
//    {
//        unordered_map<int, int> numsCount;
//        int ans = 0;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            ++numsCount[nums[i]];
//            if (isLess1(numsCount))
//            {
//                ans = i + 1;
//            }
//        }
//
//        return ans;
//    }
//
//private:
//    bool isLess1(const unordered_map<int, int>& numsCount)
//    {
//        unordered_map<int, int> values;//key：数字重复的次数，value：达到该次数的不同数字数量。
//        for (auto& p : numsCount)
//        {
//            ++values[p.second];
//        }
//
//        if (values.size() > 2)
//        {
//            return false;
//        }
//
//        if (values.size() == 1)
//        {
//            return values.begin()->first == 1 || values.begin()->second == 1;
//        }
//
//        auto a = values.begin();
//        auto b = next(values.begin());
//        if (a->second > b->second)
//        {
//            swap(a, b);
//        }
//
//        if (a->second != 1)
//        {
//            return false;
//        }
//
//        return a->first == 1 || a->first - b->first == 1;
//    }
//};

//不知道为什么本地通过，在线不能过
//class Solution
//{
//public:
//    int maxEqualFreq(vector<int>& nums)
//    {
//        unordered_map<int, int> numsCount;
//        unordered_map<int, int> values;//key：数字重复的次数，value：达到该次数的不同数字数量。
//        int ans = 0;
//        int old;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            old = numsCount[nums[i]]++;
//            ++values[old + 1];
//            if (old > 0)
//            {
//                --values[old];
//                if (values[old] <= 0)
//                {
//                    values.erase(old);
//                }
//            }
//
//            if (isLess1(values))
//            {
//                ans = i + 1;
//            }
//        }
//
//        return ans;
//    }
//
//private:
//    bool isLess1(const unordered_map<int, int>& values)
//    {
//        if (values.size() > 2)
//        {
//            return false;
//        }
//
//        if (values.size() == 1)
//        {
//            return values.begin()->first == 1 || values.begin()->second == 1;
//        }
//
//        auto a = values.begin();
//        auto b = next(a, 1);
//        if (a->second > b->second)
//        {
//            swap(a, b);
//        }
//
//        if (a->second != 1)
//        {
//            return false;
//        }
//
//        return a->first == 1 || a->first - b->first == 1;
//    }
//};

class Solution 
{
public:
    int maxEqualFreq(vector<int>& nums) 
    {
        vector<int> numsCount(100001, 0);
        vector<int> freq(100001, 0);
        int ans = 0;
        int maxCount = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int n = nums[i];
            ++numsCount[n];
            ++freq[numsCount[n]];
            maxCount = max(numsCount[n], maxCount);
            if ((freq[maxCount] == 1 && freq[maxCount - 1] * (maxCount - 1) == i) ||//只有1个数字比其他数字多出现一次，或只有1个数字
                freq[maxCount] * maxCount == i)//有一个数字只出现一次
            {
                ans = i + 1;
            }
        }

        if (maxCount == 1)//所有数字只出现一次
        {
            return nums.size();
        }
        else
        {
            return ans;
        }
    }
};