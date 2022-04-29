/*
 * @Author: sanjusss
 * @Date: 2022-04-28 08:34:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-28 08:38:01
 * @FilePath: \0\900\900\905.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] % 2 == 1) {
                while (left < right && nums[right] % 2 == 1) {
                    --right;
                }

                if (left < right) {
                    swap(nums[left], nums[right--]);
                }
                else {
                    break;
                }
            }

            ++left;
        }

        return nums;
    }
};