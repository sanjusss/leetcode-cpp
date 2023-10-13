/*
 * @Author: sanjusss
 * @Date: 2023-10-12 10:42:36
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-10-12 10:49:15
 * @FilePath: \2000\2500\2560\2562.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int left = 0;
        int right = (int)nums.size() - 1;
        while (left < right) {
            int a = nums[left++];
            int b = nums[right--];
            int mul = 1;
            while (mul <= b) {
                mul *= 10;
            }

            ans += a * mul + b;
        }

        if (left == right) {
            ans += nums[left];
        }

        return ans;
    }
};