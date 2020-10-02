#pragma once
#include "leetcode.h"

class Solution 
{
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        for (int i = intervals.size() - 1; i > 0; --i)
        {
            if (intervals[i][0] < intervals[i - 1][1])
            {
                return false;
            }
        }

        return true;
    }
};