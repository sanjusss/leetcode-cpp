/*
 * @Author: sanjusss
 * @Date: 2021-07-20 08:10:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-20 08:16:22
 * @FilePath: \1000\1800\1870\1877.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            ans = max(ans, nums[left++] + nums[right--]);
        }

        return ans;
    }
};

TEST(&Solution::minPairSum)