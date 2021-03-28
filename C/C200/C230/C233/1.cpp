/*
 * @Author: sanjusss
 * @Date: 2021-03-21 10:32:41
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-21 10:37:39
 * @FilePath: \C\C200\C230\C234\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        int prev = INT_MAX;
        int cur = 0;
        for (int i : nums) {
            if (i > prev) {
                cur += i;
            }
            else {
                cur = i;
            }

            prev = i;
            ans = max(ans, cur);
        }

        return ans;
    }
};