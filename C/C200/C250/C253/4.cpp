/*
 * @Author: sanjusss
 * @Date: 2021-08-08 10:29:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-08 10:48:41
 * @FilePath: \C\C200\C250\C253\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        ans.reserve(obstacles.size());
        vector<int> base;
        for (int i : obstacles) {
            auto p = upper_bound(base.begin(), base.end(), i);
            ans.push_back(p - base.begin() + 1);
            if (p == base.end()) {
                base.push_back(i);
            }
            else {
                *p = i;
            }
        }

        return ans;
    }
};