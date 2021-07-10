/*
 * @Author: sanjusss
 * @Date: 2021-07-04 10:28:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-04 10:31:57
 * @FilePath: \C\C200\C240\C248\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};