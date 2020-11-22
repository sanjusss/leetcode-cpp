/*
 * @Author: sanjusss
 * @Date: 2020-11-22 10:59:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-22 11:17:47
 * @FilePath: \C\C200\C210\C216\4.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort (tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int ans = 0;
        int cur = 0;
        for (auto& task : tasks) {
            if (cur < task[1]) {
                ans += task[1] - cur;
                cur = task[1];
            }

            cur -= task[0];
        }

        return ans;
    }
};