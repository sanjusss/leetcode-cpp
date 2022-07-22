/*
 * @Author: sanjusss
 * @Date: 2022-07-22 08:33:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-22 08:59:00
 * @FilePath: \0\700\750\757.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            else {
                return a[0] < b[0];
            }
        });

        int n = intervals.size();
        int last = intervals[0][1];
        vector<int> bs;
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] > last) {
                bs.push_back(last);
                last = intervals[i][1];
            }
            else if (intervals[i][1] < last) {
                last = intervals[i][1];
            }
        }

        bs.push_back(last);
        int ans = bs.size();
        last = -1;
        for (auto& in : intervals) {
            int left = in[0];
            int right = in[1];
            auto pl = lower_bound(bs.begin(), bs.end(), left);
            auto pr = upper_bound(bs.begin(), bs.end(), right);
            if (pr - pl >= 2) {
                continue;
            }

            int cur = right == *pl ? right - 1 : right;
            if (last == -1) {
                last = cur;
            }
            else if (left > last) {
                ++ans;
                last = cur;
            }
            else if (cur < last) {
                last = cur;
            }
        }

        if (last >= 0) {
            ++ans;
        }

        return ans;
    }
};