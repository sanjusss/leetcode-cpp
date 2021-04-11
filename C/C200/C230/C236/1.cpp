/*
 * @Author: sanjusss
 * @Date: 2021-04-11 10:31:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-11 10:33:19
 * @FilePath: \C\C200\C230\C236\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int i : nums) {
            if (i == 0) {
                return 0;
            }
            else if (i < 0) {
                sign *= -1;
            }
        }

        return sign;
    }
};