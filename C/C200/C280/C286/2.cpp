/*
 * @Author: sanjusss
 * @Date: 2022-03-27 10:27:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-27 10:56:04
 * @FilePath: \C\C200\C280\C286\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && nums[i] == nums[j]) {
                ++j;
                ++ans;
            }

            i = j + 1;
        }

        if ((n - ans) % 2 == 1) {
            ++ans;
        } 

        return ans;
    }
};

TEST(&Solution::minDeletion)