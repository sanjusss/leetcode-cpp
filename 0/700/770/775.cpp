/*
 * @Author: sanjusss
 * @Date: 2022-11-16 08:35:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-16 08:40:27
 * @FilePath: \0\700\770\775.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int min1 = n - 1;
        int min2 = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > nums[i + 1]) {
                if (min1 != i + 1 || (min2 != -1 && nums[i] > nums[min2])) {
                    return false;
                }
            }
            else {
                if (nums[i] > nums[min1]) {
                    return false;
                }
            }

            if (nums[i] < nums[min1]) {
                min2 = min1;
                min1 = i;
            }
            else if (min2 == -1 || nums[i] < min2) {
                min2 = i;
            }
        }

        return true;
    }
};