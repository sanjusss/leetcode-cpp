/*
 * @Author: sanjusss
 * @Date: 2021-07-17 08:23:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-17 08:25:23
 * @FilePath: \jianzhioffer\42.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int prev = 0;
        for (int i : nums) {
            prev = max(i, prev + i);
            ans = max(ans, prev);
        }

        return ans;
    }
};