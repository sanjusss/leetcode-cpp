/*
 * @Author: sanjusss
 * @Date: 2022-03-09 10:36:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-09 11:07:40
 * @FilePath: \0\700\790\798.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(2 * n);
        int score = 0;
        for (int i = 0; i < n; ++i) {
            int diff = i - nums[i];
            if (diff >= 0) {
                ++score;
                ++cnt[diff];
            }
        }

        int ans = 0;
        int best = score;
        int zeroi = 0;
        for (int k = 1; k < n; ++k) {
            int i = k - 1;
            score -= cnt[zeroi];
            ++score;
            ++cnt[zeroi + n - nums[i]];
            ++zeroi;
            if (score > best) {
                score = best;
                ans = k;
            }
        }

        return ans;
    }
};