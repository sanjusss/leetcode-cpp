#pragma once
#include "leetcode.h"

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= right) {
                right = intervals[i][1];
            }
            else {
                ++ans;
            }
        }

        return ans;
    }
};