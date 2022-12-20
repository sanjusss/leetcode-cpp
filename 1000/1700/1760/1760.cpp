/*
 * @Author: sanjusss
 * @Date: 2022-12-20 08:29:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-20 08:41:01
 * @FilePath: \1000\1700\1760\1760.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        while (left < right) {
            int op = 0;
            int mid = (right + left) / 2;
            for (int i : nums) {
                op += (i + mid - 1) / mid - 1;
            }

            if (op > maxOperations) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return left;
    }
};