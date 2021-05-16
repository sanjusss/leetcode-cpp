/*
 * @Author: sanjusss
 * @Date: 2021-05-16 10:27:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-16 10:37:36
 * @FilePath: \C\C200\C240\C241\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int mask = (1 << n) - 1;
        for (int i = mask; i != 0; i = mask & (i - 1)) {
            int v = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    v ^= nums[j];
                }
            }

            ans += v;
        }

        return ans;
    }
};