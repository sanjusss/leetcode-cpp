#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<vector<int>> permute(vector<int>& nums) 
//    {
//        vector<vector<int>> ans;
//        sort(nums.begin(), nums.end());
//        do
//        {
//            ans.push_back(nums);
//        } while (next_permutation(nums.begin(), nums.end()));
//
//        return ans;
//    }
//};

class Solution 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> next;
        permute(nums, next, ans);
        return ans;
    }
    
private:
    void permute(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans)
    {
        if (cur.size() == nums.size())
        {
            ans.push_back(cur);
            return;
        }

        for (auto i : nums)
        {
            if (find(cur.begin(), cur.end(), i) == cur.end())
            {
                vector<int> next = cur;
                next.push_back(i);
                permute(nums, next, ans);
            }
        }
    }
};