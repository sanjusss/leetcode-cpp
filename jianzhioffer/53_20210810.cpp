/*
 * @Author: sanjusss
 * @Date: 2021-08-10 17:55:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-10 17:58:01
 * @FilePath: \jianzhioffer\53_20210810.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        int begin = left;
        left = 0;
        right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left - begin;
    }
};

TEST(&Solution::search)