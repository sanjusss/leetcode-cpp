/*
 * @Author: sanjusss
 * @Date: 2021-08-27 14:05:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-27 14:17:10
 * @FilePath: \jianzhioffer\56.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum ^= i;
        }

        int bit = 1;
        while (!(bit & sum)) {
            bit <<= 1;
        }

        int a = 0;
        int b = 0;
        for (int i : nums) {
            if (i & bit) {
                a ^= i;
            }
            else {
                b ^= i;
            }
        }

        return { a, b };
    }
};