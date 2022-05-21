/*
 * @Author: sanjusss
 * @Date: 2022-05-21 13:40:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-21 13:57:32
 * @FilePath: \0\900\960\961.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if (nums[0] == nums[1] || nums[0] == nums[2]) {
            return nums[0];
        }
        else if (nums[1] == nums[2]) {
            return nums[1];
        }

        int n = nums.size();
        int ans = nums[3];
        int cnt = 1;
        for (int i = 4; i < n; ++i) {
            if (nums[i] == ans) {
                ++cnt;
            }
            else if (cnt == 0) {
                ans = nums[i];
                cnt = 1;
            }
            else {
                --cnt;
            }
        }

        return ans;
    }
};