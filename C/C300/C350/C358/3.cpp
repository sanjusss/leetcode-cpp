/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-08-13 10:45:26
 * @FilePath: \C\C300\C350\C358\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        set<int> vs;
        int ans = INT_MAX;
        for (int j = x; j < n; ++j) {
            vs.insert(nums[j - x]);
            auto p = vs.lower_bound(nums[j]);
            if (p != vs.end()) {
                ans = min(ans, *p - nums[j]);
            }

            if (p != vs.begin()) {
                ans = min(ans, nums[j] - *prev(p));
            }
        }

        return ans;
    }
};