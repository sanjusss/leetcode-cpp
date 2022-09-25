/*
 * @Author: sanjusss
 * @Date: 2022-09-25 10:28:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-25 10:38:20
 * @FilePath: \C\C300\C310\C312\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int target = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            while (i < n && nums[i] == target) {
                ++i;
                ++cnt;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};