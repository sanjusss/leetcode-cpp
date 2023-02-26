/*
 * @Author: sanjusss
 * @Date: 2023-02-26 10:29:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-02-26 10:33:08
 * @FilePath: \C\C300\C330\C334\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int left = sums[i];
            int right = sums[n] - sums[i + 1];
            ans[i] = abs(left - right);
        }

        return ans;
    }
};