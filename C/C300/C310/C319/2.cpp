/*
 * @Author: sanjusss
 * @Date: 2022-11-13 10:26:02
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-13 10:36:13
 * @FilePath: \C\C300\C310\C319\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int g = 1;
            for (int j = i; j < n; ++j) {
                g = lcm(g, nums[j]);
                if (g == k) {
                    ++ans;
                }
                else if (k % g != 0) {
                    break;
                }
            }
        }

        return ans;
    }
};