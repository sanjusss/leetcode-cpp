#include "leetcode.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j : nums) {
                if (j <= i && INT_MAX - dp[i] > dp[i - j]) {
                    dp[i] += dp[i - j];
                }
            }
        }

        return dp[target];
    }
};

TEST(&Solution::combinationSum4)