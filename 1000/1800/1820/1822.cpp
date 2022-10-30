/*
 * @Author: sanjusss
 * @Date: 2022-10-27 08:41:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-27 08:42:02
 * @FilePath: \1000\1800\1820\1822.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for (int i : nums) {
            if (i == 0) {
                return 0;
            }
            else if (i < 0) {
                ans *= -1;
            }
        }

        return ans;
    }
};