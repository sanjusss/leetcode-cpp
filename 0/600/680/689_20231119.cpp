#include "leetcode.h"

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n - k + 1);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += nums[i];
            if (i < k - 1) {
                continue;
            }
            else if (i >= k) {
                cur -= nums[i - k];
            }

            sums[i - k + 1] = cur;
        }
        
        vector<vector<vector<int>>> dp(3, vector<vector<int>>(n - k + 1));
        for (int i = 0; i < 3; ++i) {
            cur = INT_MIN;
            for (int j = k * i; j <= n - k; ++j) {
                int s = sums[j];
                for (int d = 0; d < i; ++d) {
                    s += sums[dp[i - 1][j - k][d]];
                }

                if (s > cur) {
                    cur = s;
                    for (int d = 0; d < i; ++d) {
                        dp[i][j].push_back(dp[i - 1][j - k][d]);
                    }

                    dp[i][j].push_back(j);
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[2][n - k];
    }
};