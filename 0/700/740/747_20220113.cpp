/*
 * @Author: sanjusss
 * @Date: 2022-01-13 08:48:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-13 08:51:23
 * @FilePath: \0\700\740\747_20220113.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = -1;
        int max2 = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (max1 == -1 || nums[i] > nums[max1]) {
                max2 = max1;
                max1 = i;
            }
            else if (max2 == -1 || nums[i] > nums[max2]) {
                max2 = i;
            }
        }

        if (max1 >= 0 && (max2 == -1 || nums[max1] >= nums[max2] * 2)) {
            return max1;
        }
        else {
            return -1;
        }
    }
};