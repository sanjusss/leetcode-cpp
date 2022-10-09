/*
 * @Author: sanjusss
 * @Date: 2022-10-09 10:30:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-09 10:35:25
 * @FilePath: \C\C300\C310\C314\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans = INT_MAX;
        int time = 0;
        int start = 0;
        for (auto& log : logs) {
            int use = log[1] - start;
            if (use > time || (use == time && log[0] < ans)) {
                ans = log[0];
                time = use;
            }

            start = log[1];
        }

        return ans;
    }
};