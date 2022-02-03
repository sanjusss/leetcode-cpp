/*
 * @Author: sanjusss
 * @Date: 2022-01-30 10:28:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-01-30 10:39:39
 * @FilePath: \C\C200\C270\C278\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int zero = 0;
        int one = accumulate(nums.begin(), nums.end(), 0);
        int score = one;
        int n = nums.size();
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                ++zero;
            }
            else {
                --one;
            }

            if (zero + one == score) {
                ans.push_back(i + 1);
            }
            else if (zero + one > score) {
                score = zero + one;
                ans.clear();
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};