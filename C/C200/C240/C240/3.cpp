/*
 * @Author: sanjusss
 * @Date: 2021-05-09 10:45:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-09 11:14:59
 * @FilePath: \C\C200\C240\C240\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        static const int mod = 1e9 + 7;
        int64_t ans = 0;
        int n = nums.size();
        stack<int> s;
        vector<int64_t> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                int j = s.top();
                s.pop();
                ans = max(ans, (sums[i] - sums[s.empty() ? 0 : s.top() + 1]) * (int64_t)nums[j]);
            }

            sums[i + 1] = sums[i] + nums[i];
            s.push(i);
        }

        while (!s.empty()) {
            int j = s.top();
            s.pop();
            ans = max(ans, (sums[n] - sums[s.empty() ? 0 : s.top() + 1]) * (int64_t)nums[j]);
        }

        return ans % mod;
    }
};

TEST(&Solution::maxSumMinProduct)