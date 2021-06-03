/*
 * @Author: sanjusss
 * @Date: 2021-06-03 08:22:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-03 09:11:18
 * @FilePath: \0\500\520\525.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> sums;
        sums[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                --sum;
            } 
            else {
                ++sum;
            }

            if (sums.find(sum) == sums.end()) {
                sums[sum] = i;
            }
            else {
                ans = max(ans, i - sums[sum]);
            }
        }

        return ans;
    }
};

TEST(&Solution::findMaxLength)