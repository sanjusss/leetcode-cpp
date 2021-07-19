/*
 * @Author: sanjusss
 * @Date: 2021-07-19 08:24:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-19 09:13:19
 * @FilePath: \1000\1800\1830\1838.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int64_t remain = k;
        int ans = 1;
        int left = 0;
        int right = 1;
        while (right < n) {
            if (nums[right] != nums[right - 1]) {
                remain -= (int64_t)(right - left) * (int64_t)(nums[right] - nums[right - 1]);
                while (remain < 0) {
                    remain += nums[right] - nums[left++];
                }
            }

            ans = max(ans, right - left + 1);
            ++right;
        }

        return ans;
    }
};

TEST(&Solution::maxFrequency)