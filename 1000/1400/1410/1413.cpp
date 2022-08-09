/*
 * @Author: sanjusss
 * @Date: 2022-08-09 08:18:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-09 08:19:34
 * @FilePath: \1000\1400\1410\1413.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 1;
        int sum = 0;
        for (int i : nums) {
            sum += i;
            ans = max(ans, 1 - sum);
        }

        return ans;
    }
};