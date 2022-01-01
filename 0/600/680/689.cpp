/*
 * @Author: sanjusss
 * @Date: 2022-01-01 10:41:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-01 10:53:08
 * @FilePath: \0\600\680\689.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> ans;
        int sum1 = 0;
        int maxSum1 = 0;
        int maxSum1i = 0;
        int sum2 = 0;
        int maxSum12 = 0;
        int maxSum12i1 = 0;
        int maxSum12i2 = 0;
        int sum3 = 0;
        int maxSumAll = 0;
        for (int i = 2 * k; i < nums.size(); ++i) {
            sum1 += nums[i - 2 * k];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i < 3 * k - 1) {
                continue;
            }

            if (sum1 > maxSum1) {
                maxSum1 = sum1;
                maxSum1i = i - 3 * k + 1;
            }

            if (maxSum1 + sum2 > maxSum12) {
                maxSum12 = maxSum1 + sum2;
                maxSum12i1 = maxSum1i;
                maxSum12i2 = i - 2 * k + 1;
            }

            if (maxSum12 + sum3 > maxSumAll) {
                maxSumAll = maxSum12 + sum3;
                ans = { maxSum12i1, maxSum12i2, i - k + 1 };
            }

            sum1 -= nums[i - 3 * k + 1];
            sum2 -= nums[i - 2 * k + 1];
            sum3 -= nums[i - k + 1];
        }

        return ans;
    }
};

TEST(&Solution::maxSumOfThreeSubarrays)