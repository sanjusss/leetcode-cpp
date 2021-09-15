/*
 * @Author: sanjusss
 * @Date: 2021-09-15 08:50:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-15 09:02:47
 * @FilePath: \0\100\160\162_20210915.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= nums[mid + 1]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};
