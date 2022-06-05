/*
 * @Author: sanjusss
 * @Date: 2022-06-05 10:27:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-06-05 10:36:10
 * @FilePath: \C\C200\C290\C296\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (auto i = nums.begin(); i != nums.end(); i = upper_bound(i, nums.end(), (*i) + k)) {
            ++ans;
        }

        return ans;
    }
};