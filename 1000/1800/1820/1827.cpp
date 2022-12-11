/*
 * @Author: sanjusss
 * @Date: 2022-12-11 09:48:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-11 09:50:23
 * @FilePath: \1000\1800\1820\1827.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                ans += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }

        return ans;
    }
};