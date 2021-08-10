/*
 * @Author: sanjusss
 * @Date: 2021-08-10 17:41:05
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-10 17:46:08
 * @FilePath: \0\400\410\413.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return 0;
        }

        int prev = nums[1] - nums[0];
        int start = 1;
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            int cur = nums[i] - nums[i - 1];
            if (cur == prev) {
                ans += i - start;
            }
            else {
                prev = cur;
                start = i;
            }
        }

        return ans;
    }
};

TEST(&Solution::numberOfArithmeticSlices)