#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    int splitArray(vector<int>& nums, int m) {
//        int n = nums.size();
//        vector<vector<int64_t>> dp(m + 1, vector<int64_t>(n + 1, INT64_MAX));
//        vector<int64_t> sum(n + 1);
//        for (int j = 1; j <= n; ++j) {
//            sum[j] = sum[j - 1] + nums[j - 1];
//        }
//
//        dp[0][0] = 0;
//        for (int i = 1; i <= m; ++i) {
//            for (int j = 1; j <= n; ++j) {
//                for (int k = i - 1; k < j; ++k) {
//                    dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sum[j] - sum[k]));
//                }
//            }
//        }
//
//        return dp[m][n];
//    }
//};

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0;
        int right = INT_MAX;
        int mid = 0;

        while (left < right) {
            mid = (right - left) / 2 + left;
            if (check(nums, m, mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool check(vector<int>& nums, int m, int target) {
        int64_t sum = 0;
        int count = 0;
        for (int i : nums) {
            sum += i;
            if (sum > target) {
                ++count;
                sum = i;
            }

            if (count > m || i > target) {
                return false;
            }
        }

        if (sum > 0) {
            ++count;
        }

        return count <= m;
    }
};