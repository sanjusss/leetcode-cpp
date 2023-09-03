/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-03 10:57:40
 * @FilePath: \C\C300\C360\C361\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        unordered_map<int, int> cnts;
        int sum = 0;
        for (int i : nums) {
            ++cnts[sum % modulo];
            sum += ((i % modulo == k) ? 1 : 0);
            ans += cnts[(sum + modulo - k) % modulo];
        }

        return ans;
    }
};

TEST(&Solution::countInterestingSubarrays)