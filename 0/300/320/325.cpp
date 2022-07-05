/*
 * @Author: sanjusss
 * @Date: 2022-07-05 08:13:25
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-05 08:17:36
 * @FilePath: \0\300\320\325.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int64_t, int> pos;
        pos[0] = -1;
        int64_t cur = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cur += nums[i];
            if (pos.count(cur - k)) {
                ans = max(ans, i - pos[cur - k]);
            }

            if (!pos.count(cur)) {
                pos[cur] = i;
            }
        }

        return ans;
    }
};