/*
 * @Author: sanjusss
 * @Date: 2021-07-04 10:28:45
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-04 10:40:32
 * @FilePath: \C\C200\C240\C248\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; ++i) {
            time[i] = (dist[i] + speed[i] - 1) / speed[i];
        }

        sort(time.begin(), time.end());
        int ans = 0;
        while (ans < n && ans < time[ans]) {
            ++ans;
        }

        return ans;
    }
};