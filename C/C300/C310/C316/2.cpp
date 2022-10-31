/*
 * @Author: sanjusss
 * @Date: 2022-10-23 10:24:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-23 10:40:55
 * @FilePath: \C\C300\C310\C316\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] % k != 0) {
                continue;
            }

            int g = nums[i];
            if (g == k) {
                ++ans;
            }

            for (int j = i + 1; j < n && nums[j] % k == 0; ++j) {
                g = gcd(g, nums[j]);
                if (g == k) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};