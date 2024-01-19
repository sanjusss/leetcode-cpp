#include "leetcode.h"

class Solution {
public:
    int minimumTime(vector<int>& nums1, vector<int>& nums2, int x) {
        int n = nums1.size();
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; ++i) {
            nums.emplace_back(nums2[i], nums1[i]);
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + nums[i - 1].second + nums[i - 1].first * j);
            }
        }

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        for (int j = 0; j <= n; ++j) {
            int cur = sum1 + sum2 * j - dp[n][j];
            if (cur <= x) {
                return j;
            }
        }

        return -1;
    }
};