/*
 * @Author: sanjusss
 * @Date: 2023-01-15 10:23:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-15 10:31:17
 * @FilePath: \C\C300\C320\C328\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        for (int i : nums) {
            sum1 += i;
            while (i > 0) {
                sum2 += i % 10;
                i /= 10;
            }
        }

        return abs(sum1 - sum2);
    }
};