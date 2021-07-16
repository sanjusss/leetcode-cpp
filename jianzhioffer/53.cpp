/*
 * @Author: sanjusss
 * @Date: 2021-07-16 08:11:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-16 08:15:06
 * @FilePath: \jianzhioffer\53.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n;
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
        right = n;
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