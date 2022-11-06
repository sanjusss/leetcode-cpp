/*
 * @Author: sanjusss
 * @Date: 2022-11-06 10:35:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-06 10:38:38
 * @FilePath: \C\C300\C310\C318\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        unordered_map<int, int> cnt;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ++cnt[nums[i]];
            sum += nums[i];
            if (i + 1 < k) {
                continue;
            }
            else if (i >= k) {
                sum -= nums[i - k];
                if (--cnt[nums[i - k]] == 0) {
                    cnt.erase(nums[i - k]);
                }
            }

            if (cnt.size() == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};