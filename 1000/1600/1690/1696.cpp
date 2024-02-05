/*
 * @Author: sanjusss
 * @Date: 2024-02-05 09:29:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2024-02-05 09:42:57
 * @FilePath: \1000\1600\1690\1696.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        dp[n - 1] = nums[n - 1];
        deque<int> q;
        q.push_back(n - 1);
        for (int i = n - 2; i >= 0; --i) {
            while (!q.empty() && q.front() > i + k) {
                q.pop_front();
            }

            dp[i] = nums[i] + dp[q.front()];
            while (!q.empty() && dp[q.back()] <= dp[i]) {
                q.pop_back();
            }

            q.push_back(i);
        }

        return dp[0];
    }
};