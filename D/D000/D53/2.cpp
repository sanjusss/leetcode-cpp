/*
 * @Author: sanjusss
 * @Date: 2021-05-29 22:03:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-29 22:35:37
 * @FilePath: \D\D000\D57\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            ans = max(ans, nums[left++] + nums[right--]);
        }

        return ans;
    }
};