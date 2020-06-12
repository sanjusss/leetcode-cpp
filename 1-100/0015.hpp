#pragma once
#include "leetcode.h"

//class Solution
//{
//public:
//    vector<vector<int>> threeSum(vector<int>& nums)
//    {
//        vector<vector<int>> ans;
//        int size = nums.size();
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < size; ++i)
//        {
//            if (i > 0 && nums[i] == nums[i - 1])
//            {
//                continue;
//            }
//
//            int k = size - 1;
//            for (int j = i + 1; j < size; ++j)
//            {
//                if (j > i + 1 && nums[j] == nums[j - 1])
//                {
//                    continue;
//                }
//
//                while (j < k && nums[i] + nums[j] + nums[k] > 0)
//                {
//                    --k;
//                }
//
//                if (j == k)
//                {
//                    break;
//                }
//                else if (nums[i] + nums[j] + nums[k] == 0)
//                {
//                    ans.push_back({ nums[i], nums[j], nums[k] });
//                }
//            }
//        }
//
//        return ans;
//    }
//};

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            if (nums[i] > 0)
            {
                break;
            }

            int k = size - 1;
            for (int j = i + 1; j < size; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                while (j < k && nums[i] + nums[j] + nums[k] > 0)
                {
                    --k;
                }

                if (j == k)
                {
                    break;
                }
                else if (nums[i] + nums[j] + nums[k] == 0)
                {
                    ans.push_back({ nums[i], nums[j], nums[k] });
                }
            }
        }

        return ans;
    }
};