/*
 * @Author: sanjusss
 * @Date: 2023-12-22 09:20:31
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-12-22 09:38:15
 * @FilePath: \1000\1600\1670\1671.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> pres;
        vector<int> lefts(n);
        for (int i = 0; i < n; ++i) {
            auto p = lower_bound(pres.begin(), pres.end(), nums[i]);
            lefts[i] += p - pres.begin();
            if (p == pres.end()) {
                pres.push_back(nums[i]);
            }
            else {
                *p = nums[i];
            }
        }

        pres.clear();
        int ans = n;
        for (int i = n - 1; i >= 0; --i) {
            auto p = lower_bound(pres.begin(), pres.end(), nums[i]);
            int right = p - pres.begin();
            if (i > 0 && i < n - 1 && lefts[i] > 0 && right > 0) {
                ans = min(ans, n - 1 - lefts[i] - right);
            }

            if (p == pres.end()) {
                pres.push_back(nums[i]);
            }
            else {
                *p = nums[i];
            }
        }

        return ans;
    }
};