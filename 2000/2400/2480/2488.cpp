/*
 * @Author: sanjusss
 * @Date: 2023-03-16 08:46:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-16 09:19:25
 * @FilePath: \2000\2400\2480\2488.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int cur = 0;
        int ans = 0;
        bool left = true;
        for (int i : nums) {
            if (i > k) {
                ++cur;
            }
            else if (i < k) {
                --cur;
            }
            else {
                left = false;
            }

            if (left) {
                ++cnt[cur];
            }
            else {
                ans += cnt[cur];
                ans += cnt[cur - 1];
            }
        }

        return ans;
    }
};

TEST(&Solution::countSubarrays)