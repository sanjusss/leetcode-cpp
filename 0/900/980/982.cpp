/*
 * @Author: sanjusss
 * @Date: 2023-03-05 11:45:38
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-05 12:02:16
 * @FilePath: \0\900\980\982.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int endMask = 1 << 16;
        int all = endMask - 1;
        vector<int> cnt(endMask);
        int n = nums.size();
        cnt[0] = n;
        for (int i = 0; i < n; ++i) {
            int mask = all ^ nums[i];
            for (int sub = mask; sub > 0; sub = mask & (sub - 1)) {
                ++cnt[sub];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += cnt[nums[i] & nums[j]];
            }
        }

        return ans;
    }
};