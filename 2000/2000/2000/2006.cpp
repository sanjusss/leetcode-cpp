/*
 * @Author: sanjusss
 * @Date: 2022-02-09 15:25:33
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-09 15:32:49
 * @FilePath: \2000\2000\2000\2006.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i : nums) {
            if (cnt.count(i + k)) {
                ans += cnt[i + k];
            }

            if (cnt.count(i - k)) {
                ans += cnt[i - k];
            }

            ++cnt[i];
        }

        return ans;
    }
};