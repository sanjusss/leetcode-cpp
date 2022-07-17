/*
 * @Author: sanjusss
 * @Date: 2022-07-17 10:28:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-17 10:52:52
 * @FilePath: \C\C300\C300\C302\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int t = numsDivide.front();
        for (int i : numsDivide) {
            t = gcd(t, i);
        }

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (t % nums[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};