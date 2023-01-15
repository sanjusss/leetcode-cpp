/*
 * @Author: sanjusss
 * @Date: 2023-01-15 10:18:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-15 10:21:56
 * @FilePath: \2000\2200\2290\2293.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        while (n > 1) {
            for (int i = 0; i < n / 2; ++i) {
                if (i % 2 == 0) {
                    nums[i] = min(nums[2 * i], nums[2 * i + 1]);
                }
                else {
                    nums[i] = max(nums[2 * i], nums[2 * i + 1]);
                }
            }

            n /= 2;
        }

        return nums[0];
    }
};