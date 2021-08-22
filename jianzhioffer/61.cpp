/*
 * @Author: sanjusss
 * @Date: 2021-08-22 10:00:00
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-22 10:06:25
 * @FilePath: \jianzhioffer\61.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero = 0;
        int prev = -1;
        for (int i : nums) {
            if (i == 0) {
                ++zero;
            }
            else if (prev < 0) {
                prev = i;
            }
            else if (prev == i) {
                return false;
            }
            else {
                while (prev + 1 != i && zero >= 0) {
                    --zero;
                    ++prev;
                }

                if (zero < 0) {
                    return false;
                }

                prev = i;
            }
        }

        return true;
    }
};