/*
 * @lc app=leetcode.cn id=1140 lang=cpp
 * @lcpr version=30404
 *
 * [1140] 石子游戏 II
 */

#include <bits/stdc++.h>
#include <deque>
#include <vector>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

//@lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sums(n + 1);
        for (int i = 0; i < n; ++i) {
            sums[i + 1] = sums[i] + piles[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 0; --i) {
            const int sub = sums[n] - sums[i]; // 剩余的总数
            // j 表示M
            for (int j = 1; j <= n; ++j) {
                // x 不能大于剩余堆数
                const int maxTake = min(j * 2, n - i);
                for (int x = 1; x <= maxTake; ++x) {
                    int m = min(max(j, x), n);
                    dp[i][j] = max(dp[i][j], sub - dp[i + x][m]);
                }
            }
        }

        return dp[0][1];
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [2,7,9,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,100]\n
// @lcpr case=end

 */

