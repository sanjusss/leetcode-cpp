/*
 * @Author: sanjusss
 * @Date: 2023-03-05 10:28:34
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-12 10:49:04
 * @FilePath: \C\C300\C330\C336\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0;
        for (int i : nums) {
            sum ^= i;
            ans += cnt[sum]++;
        }

        return ans;
    }
};

TEST(&Solution::beautifulSubarrays)