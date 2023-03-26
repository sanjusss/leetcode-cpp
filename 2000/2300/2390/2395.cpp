/*
 * @Author: sanjusss
 * @Date: 2023-03-26 10:02:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-26 10:05:57
 * @FilePath: \2000\2300\2390\2395.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> vs;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (vs.insert(nums[i] + nums[i - 1]).second == false) {
                return true;
            }
        }

        return false;
    }
};