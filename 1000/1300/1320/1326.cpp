/*
 * @Author: sanjusss
 * @Date: 2023-02-21 09:02:43
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-21 13:57:07
 * @FilePath: \1000\1300\1320\1326.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> lens(n + 1);
        for (int i = 0; i <= n; ++i) {
            if (ranges[i] == 0) {
                continue;
            }

            int begin = max(0, i - ranges[i]);
            int end = min(n + 1, i + ranges[i] + 1);
            lens[begin] = max(lens[begin], end - begin);
        }

        int ans = 0;
        int cur = 0;
        int next = lens[0];
        for (int i = 0; i <= n; ++i) {
            if (cur > i) {
                next = max(next, lens[i] + i);
                continue;
            }

            cur = next;
            next = max(next, lens[i] + i);
            ++ans;
            if (cur <= i) {
                return -1;
            }
        }

        return ans;
    }
};

TEST(&Solution::minTaps)