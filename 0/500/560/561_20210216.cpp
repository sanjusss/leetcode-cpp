/*
 * @Author: sanjusss
 * @Date: 2021-02-16 10:16:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-16 10:18:41
 * @FilePath: \0\500\560\561_20210216.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            ans += nums[i];
        }

        return ans;
    }
};

TEST(&Solution::arrayPairSum)