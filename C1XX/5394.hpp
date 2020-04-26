#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
//    {
//        vector<int> ans;
//        int lastSize = -1;
//        for (int i = 0; lastSize != ans.size(); ++i)
//        {
//            lastSize = ans.size();
//
//            int x;
//            for (int y = 0; y <= i; ++y)
//            {
//                x = i - y;
//                if (nums.size() <= x || nums[x].size() <= y)
//                {
//                    continue;
//                }
//
//                ans.push_back(nums[x][y]);
//            }
//        } 
//        return ans;
//    }
//};

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums)
    {
        map<int, vector<int>> nodes;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums[i].size(); ++j)
            {
                nodes[i + j].push_back(nums[i][j]);
            }
        }

        vector<int> ans;
        for (auto& p : nodes)
        {
            for (auto i = p.second.rbegin(); i != p.second.rend(); ++i)
            {
                ans.push_back(*i);
            }
        }

        return ans;
    }
};