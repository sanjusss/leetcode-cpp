/*
 * @Author: sanjusss
 * @Date: 2022-08-29 08:09:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-29 08:09:57
 * @FilePath: \1000\1400\1470\1470.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }

        return ans;
    }
};