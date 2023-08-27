/*
 * @Author: sanjusss
 * @Date: 2023-08-27 19:22:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-27 19:26:41
 * @FilePath: \0\0\50\54_20230827.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        for (auto& i : intervals) {
            if (ans.empty() == false && ans.back()[1] >= i[0]) {
                ans.back()[1] = max(ans.back()[1], i[1]);
            }
            else {
                ans.push_back(i);
            }
        }

        return ans;
    }
};