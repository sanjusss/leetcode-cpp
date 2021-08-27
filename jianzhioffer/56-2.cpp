/*
 * @Author: sanjusss
 * @Date: 2021-08-27 14:19:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-27 14:27:00
 * @FilePath: \jianzhioffer\56-2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int bit = 1 << i;
            int cnt = 0;
            for (int i : nums) {
                if (i & bit) {
                    ++cnt;
                }
            }

            if (cnt % 3 == 1) {
                ans |= bit;
            }
        }

        return ans;
    }
};