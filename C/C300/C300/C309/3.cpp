/*
 * @Author: sanjusss
 * @Date: 2022-08-21 10:29:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-04 10:55:18
 * @FilePath: \C\C300\C300\C309\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        int mask = nums[0];
        int n = nums.size();
        int start = 0;
        for (int i = 1; i < n; ++i) {
            while (mask & nums[i]) {
                mask = mask ^ nums[start++];
            }

            mask = mask | nums[i];
            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};