/*
 * @Author: sanjusss
 * @Date: 2022-10-07 08:08:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-07 08:09:52
 * @FilePath: \1000\1800\1800\1800.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int prev = 0;
        int sum = 0;
        int ans = 0;
        for (int i : nums) {
            if (i > prev) {
                sum += i;
            }
            else {
                sum = i;
            }

            prev = i;
            ans = max(ans, sum);
        }

        return ans;
    }
};