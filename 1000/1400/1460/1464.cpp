/*
 * @Author: sanjusss
 * @Date: 2022-08-26 08:37:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-26 08:39:33
 * @FilePath: \1000\1400\1460\1464.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int minVal = nums[0] - 1;
        int maxVal = nums[0] - 1;
        for (int i = 1; i < n; ++i) {
            int val = nums[i] - 1;
            ans = max({ ans, minVal * val, val * maxVal });
            minVal = min(minVal, val);
            maxVal = max(maxVal, val);
        }

        return ans;
    }
};