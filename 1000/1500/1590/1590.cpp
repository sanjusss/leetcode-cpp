/*
 * @Author: sanjusss
 * @Date: 2023-03-10 08:59:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-03-10 09:28:46
 * @FilePath: \1000\1500\1590\1590.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
            sum %= p;
        }

        if (sum == 0) {
            return 0;
        }

        int n = nums.size();
        int ans = n;
        unordered_map<int, int> pre;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            pre[cur] = i;
            cur += nums[i];
            cur %= p;
            int t = (cur - sum + p) % p;
            if (pre.count(t)) {
                ans = min(ans, i - pre[t] + 1);
            }
        }

        return ans == n ? -1 : ans;
    }
};