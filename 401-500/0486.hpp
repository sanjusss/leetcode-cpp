#pragma once
#include "leetcode.h"

//class Solution {
//public:
//    bool PredictTheWinner(vector<int>& nums) {
//        int n = nums.size();
//        vector<vector<int>> dp(n, vector<int>(n));
//        for (int i = 0; i < n; ++i) {
//            dp[i][i] = nums[i];
//        }
//
//        for (int k = 1; k < n; ++k) {
//            for (int i = n - k - 1; i >= 0; --i) {
//                int j = i + k;
//                if (k >= 2) {
//                    dp[i][j] = max(nums[i] + min(dp[i + 1][j - 1], dp[i + 2][j]),
//                        nums[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
//                }
//                else {
//                    dp[i][j] = max(nums[i], nums[j]);
//                }
//            }
//        }
//
//        int sum = 0;
//        for (int i : nums) {
//            sum += i;
//        }
//
//        return dp[0][n - 1] >= sum - dp[0][n - 1];
//    }
//};

//class Solution {
//public:
//    bool PredictTheWinner(vector<int>& nums) {
//        int n = nums.size();
//        vector<vector<int>> dp(n, vector<int>(n));
//        for (int i = 0; i < n; ++i) {
//            dp[i][i] = nums[i];
//        }
//
//        for (int k = 1; k < n; ++k) {
//            for (int i = n - k - 1; i >= 0; --i) {
//                int j = i + k;
//                dp[i][j] = max(nums[i] - dp[i + 1][j],
//                        nums[j] - dp[i][j - 1]);
//            }
//        }
//
//        return dp[0][n - 1] >= 0;
//    }
//};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = nums[i];
        }

        for (int k = 1; k < n; ++k) {
            for (int i = n - k - 1; i >= 0; --i) {
                int j = i + k;
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }

        return dp[n - 1] >= 0;
    }
};