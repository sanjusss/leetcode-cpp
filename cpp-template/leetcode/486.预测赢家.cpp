/*
 * @lc app=leetcode.cn id=486 lang=cpp
 * @lcpr version=30404
 *
 * [486] 预测赢家
 */

#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }

        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = (sums[j + 1] - sums[i]) - min(dp[i][j - 1], dp[i + 1][j]);
            }
        }

        return dp[0][n - 1] >= sums[n] - dp[0][n - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,5,233,7]\n
// @lcpr case=end

 */

