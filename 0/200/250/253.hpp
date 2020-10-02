#pragma once
#include "leetcode.h"

class Solution 
{
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        vector<int> groups;
        for (auto i : intervals)
        {
            bool success = false;
            for (auto& j : groups)
            {
                if (i[0] >= j)
                {
                    j = i[1];
                    success = true;
                    break;
                }
            }

            if (success == false)
            {
                groups.push_back(i[1]);
            }

            sort(groups.begin(), groups.end());
        }

        return groups.size();
    }
};