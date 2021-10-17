/*
 * @Author: sanjusss
 * @Date: 2021-10-17 10:29:17
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-17 10:46:38
 * @FilePath: \C\C200\C260\C263\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int value = 0;
        int ans = 0;
        int n = nums.size();
        for (int mask = (1 << n) - 1; mask > 0; --mask) {
            int cur = 0;
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    continue;
                }

                cur |= nums[i];
            }

            if (cur > value) {
                value = cur;
                ans = 1;
            }
            else if (cur == value) {
                ++ans;
            }
        }

        return ans;
    }
};