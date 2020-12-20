/*
 * @Author: sanjusss
 * @Date: 2020-12-20 10:50:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-20 11:00:32
 * @FilePath: \C\C200\C220\C220\2.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> sums(n + 1);
        unordered_map<int, int> positions;
        int start = 0;
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = nums[i] + sums[i];
            if (positions.find(nums[i]) != positions.end()) {
                start = max(start, positions[nums[i]] + 1);
            }

            positions[nums[i]] = i;
            ans = max(ans, sums[i + 1] - sums[start]);
        }

        return ans;
    }
};