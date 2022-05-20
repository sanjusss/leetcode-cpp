/*
 * @Author: sanjusss
 * @Date: 2022-05-20 11:31:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-20 11:34:14
 * @FilePath: \0\400\430\436.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> s2i;
        for (int i = 0; i < n; ++i) {
            s2i[intervals[i][0]] = i;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            auto p = s2i.lower_bound(intervals[i][1]);
            if (p == s2i.end()) {
                ans[i] = -1;
            }
            else {
                ans[i] = p->second;
            }
        }

        return ans;
    }
};