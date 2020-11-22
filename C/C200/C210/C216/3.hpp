/*
 * @Author: sanjusss
 * @Date: 2020-11-22 10:44:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-22 10:58:38
 * @FilePath: \C\C200\C210\C216\3.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return 1;
        }

        vector<int> sums(n);
        sums[0] = nums[0];
        sums[1] = nums[1];
        for (int i = 2; i < n; ++i) {
            sums[i] = sums[i - 2] + nums[i];
        }

        vector<int> rsums(n);
        rsums[n - 1] = nums[n - 1];
        rsums[n - 2] = nums[n - 2];
        for (int i = n - 3; i >= 0; --i) {
            rsums[i] = rsums[i + 2] + nums[i];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int a = 0;
            if (i - 2 >= 0) {
                a += sums[i - 2];
            }

            if (i + 1 < n) {
                a += rsums[i + 1];
            }

            int b = 0;
            if (i - 1 >= 0) {
                b += sums[i - 1];
            }

            if (i + 2 < n) {
                b += rsums[i + 2];
            }

            if (a == b) {
                ++ans;
            }
        }

        return ans;
    }
};