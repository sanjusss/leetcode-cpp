/*
 * @Author: sanjusss
 * @Date: 2023-01-07 15:17:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-07 15:25:02
 * @FilePath: \1000\1600\1650\1658.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        if (target < 0) {
            return -1;
        }

        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int right = 0;
        int cur = 0;
        while (left < n) {
            while (right < n && cur < target) {
                cur += nums[right++];
            }

            if (cur == target) {
                ans = min(ans, n - (right - left));
            }

            cur -= nums[left++];
        }

        return ans == INT_MAX ? -1 : ans;
    }
};