/*
 * @Author: sanjusss
 * @Date: 2022-01-23 10:28:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-23 10:34:49
 * @FilePath: \C\C200\C270\C277\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countElements(vector<int>& nums) {
        int big = *max_element(nums.begin(), nums.end());
        int small = *min_element(nums.begin(), nums.end());
        if (big == small) {
            return 0;
        }

        return nums.size() - count(nums.begin(), nums.end(), big) - count(nums.begin(), nums.end(), small);
    }
};