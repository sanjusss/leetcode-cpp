/*
 * @Author: sanjusss
 * @Date: 2021-06-27 10:28:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-27 10:35:13
 * @FilePath: \C\C200\C240\C247\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 1] * nums[n - 2]) - (nums[0] * nums[1]);
    }
};