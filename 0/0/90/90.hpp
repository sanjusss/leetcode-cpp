#pragma once
#include "leetcode.h"

//需要排序的方法
//class Solution 
//{
//public:
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
//    {
//        vector<vector<int>> ans;
//        ans.push_back({});
//        int pre = INT_MIN;
//        int sameLength = -1;
//        sort(nums.begin(), nums.end());
//        for (auto& i : nums)
//        {
//            if (pre == i)
//            {
//                ++sameLength;
//            }
//            else
//            {
//                pre = i;
//                sameLength = 0;
//            }
//
//            for (int j = ans.size() - 1; j >= 0; --j)
//            {
//                if (sameLength == 0 ||
//                    (ans[j].size() >= sameLength && ans[j][ans[j].size() - sameLength] == i))
//                {
//                    auto next = ans[j];
//                    next.push_back(i);
//                    ans.push_back(next);
//                }
//            }
//        }
//
//        return ans;
//    }
//};

//根据频率计算
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        unordered_map<int, int> freq;
        for (auto i : nums)
        {
            ++freq[i];
        }

        vector<vector<int>> ans;
        ans.push_back({});
        for (auto& p : freq)
        {
            for (int i = ans.size() - 1; i >= 0; --i)
            {
                auto next = ans[i];
                for (int j = 0; j < p.second; ++j)
                {
                    next.push_back(p.first);
                    ans.push_back(next);
                }
            }
        }

        return ans;
    }
};