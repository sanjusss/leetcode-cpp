/*
 * @Author: sanjusss
 * @Date: 2022-06-15 08:34:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-15 10:00:28
 * @FilePath: \0\700\710\719.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums.back() - nums.front();
        while (left < right) {
            int mid = (left + right) / 2; // 最大距离
            int cnt = 0; // 小于等于最大距离的数量
            for (int i = 1; i < n; ++i) {
                cnt += nums.begin() + i - lower_bound(nums.begin(), nums.begin() + i, nums[i] - mid);
            }

            if (cnt < k) {
                left = mid  + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};

TEST(&Solution::smallestDistancePair)