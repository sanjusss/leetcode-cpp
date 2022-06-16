/*
 * @Author: sanjusss
 * @Date: 2022-06-16 10:31:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-16 10:44:26
 * @FilePath: \0\500\530\532.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int ans = 0;
        int n = nums.size();
        while (left < n) {
            while (right < n && nums[right] - nums[left] <= k) {
                ++right;
            }

            if (right - 1 > left && nums[right - 1] - nums[left] == k) {
                ++ans;
            }

            while (left + 1 < n && nums[left + 1] == nums[left]) {
                ++left;
            }

            ++left;
        }

        return ans;
    }
};