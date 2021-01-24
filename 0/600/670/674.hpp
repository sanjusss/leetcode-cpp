/*
 * @Author: sanjusss
 * @Date: 2021-01-24 12:02:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-24 12:04:55
 * @FilePath: \0\600\670\674.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;
        int prev = INT_MIN;
        int length = 0;
        for (int i : nums) {
            if (i > prev) {
                ans = max(ans, ++length);
            }
            else {
                length = 1;
            }

            prev = i;
        }

        return ans;
    }
};