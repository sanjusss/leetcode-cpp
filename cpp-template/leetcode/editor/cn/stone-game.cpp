/*
 * @lc app=leetcode.cn id=877 lang=cpp
 * @lcpr version=30404
 *
 * [877] 石子游戏
 */

#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

#include <bits/stdc++.h>
#include <vector>


using namespace std;

// @lc code=start
// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         int n = piles.size();
//         vector<int> dp(n);
//         for (int i = n - 1; i >= 0; --i) {
//             dp[i] = piles[i];
//             for (int j = i + 1; j < n; ++j) {
//                 dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
//             }
//         }

//         return dp[n - 1] >= 0;
//     }
// };
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}


/*
// @lcpr case=start
// [5,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,7,2,3]\n
// @lcpr case=end

 */
