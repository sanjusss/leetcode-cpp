/*
 * @lc app=leetcode.cn id=1406 lang=cpp
 * @lcpr version=30404
 *
 * [1406] 石子游戏 III
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        int cur = 0;
        int pre1 = 0;
        int pre2 = 0;
        int pre3 = 0;
        for (int i = n - 1; i >= 0; --i) {
            pre3 = pre2;
            pre2 = pre1;
            pre1 = cur;
            cur = stoneValue[i] - pre1;
            if (i + 1 < n) {
                cur = max(stoneValue[i] + stoneValue[i + 1] - pre2, cur);
                if (i + 2 < n) {
                    cur = max(stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - pre3, cur);
                }
            }
        }

        if (cur > 0) {
            return "Alice"s;
        } else if (cur < 0) {
            return "Bob"s;
        } else {
            return "Tie"s;
        }
    }
};
// @lc code=end


/*
// @lcpr case=start
// [1,2,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,-9]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,6]\n
// @lcpr case=end

 */
