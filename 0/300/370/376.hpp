/*
 * @Author: sanjusss
 * @Date: 2020-12-12 11:37:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-12 12:18:20
 * @FilePath: \0\300\370\376.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }

        int pos = 1;
        int neg = 1;
        int tpos;
        int tneg;
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            if (nums[i] > nums[i - 1]) {
                tpos = max(pos, neg + 1);
                tneg = neg;
            }
            else {
                tpos = pos;
                tneg = max(pos + 1, neg);
            }

            pos = tpos;
            neg = tneg;
        }

        return max(pos, neg);
    }
};