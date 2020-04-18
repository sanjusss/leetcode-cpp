#pragma once
#include "leetcode.h"

class Solution 
{
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) 
    {
        int n = increase.size();
        vector<vector<int>> nums(3, vector<int>(n + 1));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                nums[j][i + 1] = nums[j][i] + increase[i][j];
            }
        }

        vector<int> ans;
        for (auto& r : requirements)
        {
            int t = 0;
            for (int j = 0; j < 3 && t >= 0; ++j)
            {
                auto pos = lower_bound(nums[j].begin(), nums[j].end(), r[j]);
                if (pos == nums[j].end())
                {
                    t = -1;
                }
                else
                {
                    t = max(t, (int)distance(nums[j].begin(), pos));
                }
            }

            ans.push_back(t);
        }

        return ans;
    }
};