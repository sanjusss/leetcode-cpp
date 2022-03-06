/*
 * @Author: sanjusss
 * @Date: 2022-03-06 10:28:53
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-06 10:52:08
 * @FilePath: \C\C200\C280\C283\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int64_t ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        int cur = 1;
        while (k > 0) {
            while (i < n && nums[i] <= cur) {
                if (nums[i++] == cur) {
                    ++cur;
                }
            }

            if (i < n) {
                int cnt = min(nums[i] - cur, k);
                k -= cnt;
                ans += (int64_t)(cur + cur + cnt - 1) * cnt / 2;
                cur += cnt;
            }
            else {
                ans += (int64_t)(cur + cur + k - 1) * k / 2;
                k = 0;
            }
        }

        return ans;
    }
};

TEST(&Solution::minimalKSum)