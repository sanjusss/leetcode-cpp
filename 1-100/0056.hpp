#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) 
//    {
//        vector<vector<int>> ans;
//        vector<int> removes;
//        for (auto& i : intervals)
//        {
//            removes.clear();
//            int left = i[0];
//            int right = i[1];
//            for (int j = ans.size() -1; j >= 0; --j)
//            {
//                if (ans[j][0] <= left && ans[j][1] >= right)
//                {
//                    left = ans[j][0];
//                    right = ans[j][1];
//                    removes.push_back(j);
//                }
//                else if (ans[j][0] >= left && ans[j][0] <= right && ans[j][1] >= right)
//                {
//                    right = ans[j][1];
//                    removes.push_back(j);
//                }
//                else if (ans[j][0] <= left && ans[j][1] >= left && ans[j][1] <= right)
//                {
//                    left = ans[j][0];
//                    removes.push_back(j);
//                }
//                else if (ans[j][0] >= left && ans[j][1] <= right)
//                {
//                    removes.push_back(j);
//                }
//            }
//
//            if (removes.empty() == false)
//            {
//                for (auto j : removes)
//                {
//                    ans.erase(next(ans.begin(), j));
//                }
//            }
//
//            ans.push_back({ left, right});
//        }
//
//        return ans;
//    }
//};

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b)
            {
                if (a[0] == b[0])
                {
                    return a[1] > b[1];
                }
                else
                {
                    return a[0] < b[0];
                }
            });

        vector<vector<int>> ans;
        for (auto& i : intervals)
        {
            if (ans.empty())
            {
                ans.push_back(i);
                continue;
            }

            auto& back = ans.back();
            if (back[0] == i[0] || back[1] >= i[1])
            {
                continue;
            }
            
            //back[0] < i[0]
            if (back[1] >= i[0] && back[1] <= i[1])
            {
                back[1] = i[1];
            }
            else
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};