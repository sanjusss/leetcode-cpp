/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-16 10:38:23
 * @FilePath: \C\C300\C350\C354\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int right = 0;
        for (int i = 0; i < n; ++i) {
            while (right < n && nums[right] <= nums[i] + k + k) {
                ++right;
            }

            ans = max(ans, right - i);
        }

        return ans;
    }
};