/*
 * @Author: sanjusss
 * @Date: 2021-08-13 11:01:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-13 11:05:31
 * @FilePath: \jianzhioffer\63.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int hold = INT_MAX;
        for (int i : prices) {
            if (hold > i) {
                hold = i;
            }
            else {
                ans = max(ans, i - hold);
            }

        }

        return ans;
    }
};