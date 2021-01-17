/*
 * @Author: sanjusss
 * @Date: 2021-01-17 10:33:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-01-17 10:42:23
 * @FilePath: \C\C200\C220\C224\2.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> abCnt;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++abCnt[nums[i] * nums[j]];
            }
        }

        int ans = 0;
        for (auto& [_, i] : abCnt) {
            if (i < 2) {
                continue;
            }

            ans += i * (i - 1) * 4;
        }

        return ans;
    }
};