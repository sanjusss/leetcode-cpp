/*
 * @Author: sanjusss
 * @Date: 2021-06-28 09:31:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-28 09:37:00
 * @FilePath: \D\D000\D55\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;
        bool hasRemove = false;
        for (int i : nums) {
            if (i <= prev1) {
                if (hasRemove) {
                    return false;
                }

                hasRemove = true;
                if (i > prev2) {
                    prev1 = i;
                }
            }
            else {
                prev2 = prev1;
                prev1 = i;
            }
        }

        return true;
    }
};

TEST(&Solution::canBeIncreasing)