/*
 * @Author: sanjusss
 * @Date: 2020-11-07 11:41:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-07 11:52:58
 * @FilePath: \0\300\320\327.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        vector<int64_t> sums(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = nums[i] + sums[i];
        }

        int ans = 0;
        int64_t val = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                val = sums[j + 1] - sums[i];
                if (lower <= val && upper >= val) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};