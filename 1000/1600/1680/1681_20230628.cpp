#include "leetcode.h"

class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int len = n / k;
        int endMask = 1 << n;
        vector<pair<int, int>> incomps;
        for (int mask = 0; mask < endMask; ++mask) {
            if (__builtin_popcount(mask) != len) {
                continue;
            }

            bool valid = true;
            int maxValue = INT_MIN;
            int minValue = INT_MAX;
            for (int i = 0; i < n && valid; ++i) {
                if (!((1 << i) & mask)) {
                    continue;
                }

                maxValue = max(maxValue, nums[i]);
                minValue = min(minValue, nums[i]);
                for (int j = i + 1; j < n && valid; ++j) {
                    if (!((1 << j) & mask)) {
                        continue;
                    }

                    if (nums[i] == nums[j]) {
                        valid = false;
                    }
                }
            }

            if (valid) {
                incomps.emplace_back(mask, maxValue - minValue);
            }
        }

        vector<int> dp(endMask, INT_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < endMask; ++mask) {
            if (dp[mask] == INT_MAX) {
                continue;
            }

            for (auto [sub, sum] : incomps) {
                if (mask & sub) {
                    continue;
                }

                dp[mask | sub] = min(dp[mask | sub], dp[mask] + sum);
            }
        }

        if (dp.back() == INT_MAX) {
            return -1;
        }
        else {
            return dp.back();
        }
    }
};

TEST(&Solution::minimumIncompatibility)