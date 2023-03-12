/*
 * @Author: sanjusss
 * @Date: 2023-03-05 10:28:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-12 12:06:46
 * @FilePath: \C\C300\C330\C336\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) {
                if (a[2] == b[2]) {
                    return a[0] > b[0];
                }
                else {
                    return a[2] > b[2];
                }
            }
            else {
                return a[1] < b[1];
            }
        });
        vector<bool> pts(2001);
        int ans = 0;
        for (auto& task : tasks) {
            int start = task[0];
            int end = task[1];
            int dur = task[2];
            for (int i = start; i <= end; ++i) {
                if (pts[i]) {
                    --dur;
                }
            }

            for (int i = end; dur > 0; --i) {
                if (pts[i]) {
                    continue;
                }

                pts[i] = true;
                --dur;
                ++ans;
            }
        }

        return ans;
    }
};

TEST(&Solution::findMinimumTime)