/*
 * @Author: sanjusss
 * @Date: 2022-10-22 09:20:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-22 09:31:48
 * @FilePath: \1000\1200\1230\1235.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> endi(n);
        iota(endi.begin(), endi.end(), 0);
        sort(endi.begin(), endi.end(), [&endTime](int a, int b) {
            return endTime[a] < endTime[b];
        });
        int ans = 0;
        map<int, int> dp;
        dp[0] = 0;
        for (int i : endi) {
            int b = startTime[i];
            int e = endTime[i];
            int p = profit[i];
            auto iter = prev(dp.upper_bound(b));
            ans = dp[e] = max(ans, iter->second + p);
        }

        return ans;
    }
};