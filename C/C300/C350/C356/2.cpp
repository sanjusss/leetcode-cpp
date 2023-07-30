/*
 * @Author: sanjusss
 * @Date: 2023-06-25 10:25:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-07-30 10:43:20
 * @FilePath: \C\C300\C350\C356\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int target = unordered_set<int>(nums.begin(), nums.end()).size();
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> cnt;
        int unique = 0;
        int right = 0;
        for (int left = 0; left < n; ++left) {
            while (right < n && unique != target) {
                if (cnt[nums[right++]]++ == 0) {
                    ++unique;
                }
            }

            if (unique == target) {
                ans += n - right + 1;
            }

            if (--cnt[nums[left]] == 0) {
                --unique;
            }
        }

        return ans;
    }
};

TEST(&Solution::countCompleteSubarrays)