/*
 * @Author: sanjusss
 * @Date: 2023-01-15 10:23:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-01-15 10:43:22
 * @FilePath: \C\C300\C320\C328\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        long long good = 0;
        int left = 0;
        int right = 0;
        long long ans = 0;
        int n = nums.size();
        while (left < n) {
            while (good < k && right < n) {
                good += cnt[nums[right++]]++;
            }

            if (good >= k) {
                ans += n - right + 1;
            }

            good -= --cnt[nums[left++]];
        }

        return ans;
    }
};