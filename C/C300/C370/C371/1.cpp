/*
 * @Author: sanjusss
 * @Date: 2023-11-05 10:26:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-11-12 10:35:47
 * @FilePath: \C\C300\C370\C371\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                    ans = max(ans, nums[i] ^ nums[j]);
                }
            }
        }

        return ans;
    }
};