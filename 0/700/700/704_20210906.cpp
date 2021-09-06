/*
 * @Author: sanjusss
 * @Date: 2021-09-06 08:18:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-06 08:21:04
 * @FilePath: \0\700\700\704_20210906.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;
    }
};

TEST(&Solution::search)