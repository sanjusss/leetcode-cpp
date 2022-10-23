/*
 * @Author: sanjusss
 * @Date: 2022-10-23 10:24:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-23 10:56:57
 * @FilePath: \C\C300\C310\C316\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        auto toTaget = [&] (int target) -> int64_t {
            int64_t cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += (int64_t)abs(nums[i] - target) * cost[i];
            }

            return cnt;
        };
        function<int64_t(int,int)> dfs = [&](int left, int right) -> int64_t {
            if (left >= right) {
                return toTaget(left);
            }

            int mid = (left + right) / 2;
            int64_t cprev = toTaget(mid - 1);
            int64_t c = toTaget(mid);
            int64_t cnext = toTaget(mid + 1);
            if (c < cprev && c < cnext) {
                return c;
            }
            
            int64_t ans = INT64_MAX;
            if (c >= cprev) {
                ans = min(ans, dfs(left, mid - 1));
            }
            
            if (c >= cnext) {
                ans = min(ans, dfs(mid + 1, right));
            }

            return ans;
        };
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        return dfs(left, right);
    }
};