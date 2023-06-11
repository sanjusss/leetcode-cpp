/*
 * @Author: sanjusss
 * @Date: 2023-06-04 10:29:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-11 10:51:34
 * @FilePath: \C\C300\C340\C349\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int64_t n = nums.size();
        vector<int64_t> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] += (int64_t)x * i;
            int cur = INT_MAX;
            for (int j = 0; j < n; ++j) {
                cur = min(cur, nums[(i + j) % n]);
                dp[j] += cur;
            }
        }

        return *min_element(dp.begin(), dp.end());
    }
};