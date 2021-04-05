/*
 * @Author: sanjusss
 * @Date: 2021-04-05 15:00:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-04-05 15:09:49
 * @FilePath: \LCP\20210405\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        static const int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int ans = 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + right - left) % mod;
                ++left;
            }
            else {
                --right;
            }
        }

        return ans;
    }
};

TEST(&Solution::purchasePlans)