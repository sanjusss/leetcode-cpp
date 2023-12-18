/*
 * @Author: sanjusss
 * @Date: 2023-12-18 13:54:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-18 14:03:31
 * @FilePath: \0\100\160\162_20231218.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            bool gr = mid == n - 1 || nums[mid] > nums[mid + 1];
            bool gl = mid == 0 || nums[mid] > nums[mid - 1];
            if (gr && gl) {
                return mid;
            }
            else if (gl) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};