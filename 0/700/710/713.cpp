/*
 * @Author: sanjusss
 * @Date: 2022-05-05 08:38:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-05 08:40:13
 * @FilePath: \0\700\710\713.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int cur = 1;
        int ans = 0;
        while (right < n) {
            cur *= nums[right++];
            while (cur >= k && left < right) {
                cur /= nums[left++];
            }
            
            ans += right - left;
        }

        return ans;
    }
};