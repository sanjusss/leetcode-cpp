/*
 * @Author: sanjusss
 * @Date: 2022-08-21 10:29:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-21 11:09:01
 * @FilePath: \C\C300\C300\C307\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long maxSum = 0;
        for (int& i : nums) {
            if (i > 0) {
                maxSum += i;
            }
            else {
                i = -i;
            }
        }

        sort(nums.begin(), nums.end());
        int n = nums.size();
        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> q;
        q.emplace(nums.front(), 0);
        int64_t ans = maxSum;
        for (int i = 2; i <= k; ++i) {
            auto [sum, cur] = q.top();
            q.pop();
            ans = maxSum - sum;
            if (cur + 1 == n) {
                continue;
            }

            q.emplace(sum - nums[cur] + nums[cur + 1], cur + 1);
            q.emplace(sum + nums[cur + 1], cur + 1);
        }

        return ans;
    }
};