/*
 * @Author: sanjusss
 * @Date: 2022-10-30 10:30:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-30 10:32:25
 * @FilePath: \C\C300\C310\C317\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt = 0;
        int sum = 0;
        for (int i : nums) {
            if (i % 6 == 0) {
                sum += i;
                ++cnt;
            }
        }

        if (cnt == 0) {
            return 0;
        }
        else {
            return sum / cnt;
        }
    }
};