/*
 * @Author: sanjusss
 * @Date: 2022-01-09 10:25:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-09 10:43:36
 * @FilePath: \C\C200\C270\C275\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int ans = INT_MAX;
        int cur = 0;
        for (int i = 0; i < 2 * n; ++i) {
            cur += nums[i % n];
            if (i < ones - 1) {
                continue;
            }

            ans = min(ans, ones - cur);
            cur -= nums[(i - ones + 1) % n];
        }

        return ans;
    }
};