/*
 * @Author: sanjusss
 * @Date: 2022-04-22 09:07:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-04-22 09:11:25
 * @FilePath: \0\300\390\396.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cur += i * nums[i];
            sum += nums[i];
        }

        int ans = cur;
        for (int i = n - 1; i > 0; --i) {
            cur -= nums[i] * (n - 1);
            cur += sum - nums[i];
            ans = max(ans, cur);
        }

        return ans;
    }
};