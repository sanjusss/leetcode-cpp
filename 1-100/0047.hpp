#pragma once
#include "leetcode.h"

//class Solution 
//{
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums) 
//    {
//        vector<vector<int>> ans;
//        sort(nums.begin(), nums.end());
//        do
//        {
//            ans.push_back(nums);
//        } while (next_permutation(nums.begin(), nums.end()));
//        return ans;
//    }
//};

//ʹ��set����ȥ��
//class Solution
//{
//public:
//    vector<vector<int>> permuteUnique(vector<int>& nums)
//    {
//        vector<vector<int>> ans;
//        vector<int> next;
//        multiset<int> nextNums(nums.begin(), nums.end());
//        permuteUnique(nextNums, next, ans);
//        return ans;
//    }
//
//private:
//    void permuteUnique(multiset<int>& nums, vector<int>&cur, vector<vector<int>>& ans)
//    {
//        if (nums.empty())
//        {
//            ans.push_back(cur);
//            return;
//        }
//
//        int pre = INT_MIN;
//        for (auto i : nums)
//        {
//            if (i == pre)
//            {
//                continue;
//            }
//            else
//            {
//                pre = i;
//            }
//
//            auto next = cur;
//            next.push_back(i);
//            auto nextNums = nums;
//            nextNums.erase(nextNums.find(i));
//            permuteUnique(nextNums, next, ans);
//        }
//    }
//};

//��ʹ��set���еڶ���find�����ܻ����ʱ��
class Solution 
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> next;
        sort(nums.begin(), nums.end());
        permuteUnique(nums, next, ans);
        return ans;
    }

private:
    void permuteUnique(vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans)
    {
        if (nums.size() == cur.size())
        {
            vector<int> real;
            for (auto i : cur)
            {
                real.push_back(nums[i]);
            }

            ans.push_back(real);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (find(cur.begin(), cur.end(), i) == cur.end())
            {
                if (i > 0 && nums[i] == nums[i - 1] && find(cur.begin(), cur.end(), i - 1) == cur.end())//�������ʱ��ֻ��ǰһ�����������е�ʱ������������һ������
                {
                    continue;
                }

                auto next = cur;
                next.push_back(i);
                permuteUnique(nums, next, ans);
            }
        }
    }
};