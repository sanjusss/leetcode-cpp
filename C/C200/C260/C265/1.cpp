/*
 * @Author: sanjusss
 * @Date: 2021-10-31 10:29:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-10-31 10:32:51
 * @FilePath: \C\C200\C260\C265\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 10 == nums[i]) {
                return i;
            }
        }

        return -1;
    }
};