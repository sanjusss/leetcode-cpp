/*
 * @Author: sanjusss
 * @Date: 2021-12-12 10:25:55
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-12 10:44:37
 * @FilePath: \C\C200\C270\C271\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            int maxe = nums[i];
            int mine = nums[i];
            for (int j = i + 1; j < n; ++j) {
                maxe = max(nums[j], maxe);
                mine = min(nums[j], mine);
                ans += maxe - mine;
            }
        }

        return ans;
    }
};