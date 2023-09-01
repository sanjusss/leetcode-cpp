/*
 * @Author: sanjusss
 * @Date: 2023-09-01 09:05:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-01 10:03:25
 * @FilePath: \0\0\50\57_20230901.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        for (; i < n && intervals[i][1] < newInterval[0]; ++i) {
            ans.push_back(intervals[i]);
        }

        for (; i < n && intervals[i][0] <= newInterval[1]; ++i) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }

        ans.push_back(newInterval);
        for (; i < n; ++i) {
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};