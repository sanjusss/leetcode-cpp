/*
 * @Author: sanjusss
 * @Date: 2022-02-14 12:53:24
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-14 13:00:42
 * @FilePath: \0\500\540\540.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int left = 0;
        int right = nums.size() / 2;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid * 2] != nums[mid * 2 + 1]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return nums[left * 2];
    }
};

TEST(&Solution::singleNonDuplicate)