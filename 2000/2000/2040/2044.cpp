/*
 * @Author: sanjusss
 * @Date: 2022-03-15 06:34:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-15 06:39:07
 * @FilePath: \2000\2000\2040\2044.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxVal = 0;
        int ans = 0;
        int n = nums.size();
        for (int mask = (1 << n) - 1; mask > 0; --mask) {
            int val = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    val |= nums[i];
                }
            }

            if (val > maxVal) {
                maxVal = val;
                ans = 1;
            }
            else if (val == maxVal) {
                ++ans;
            }
        }

        return ans;
    }
};