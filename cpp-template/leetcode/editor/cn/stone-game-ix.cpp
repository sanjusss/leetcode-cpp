/*
 * @lc app=leetcode.cn id=2029 lang=cpp
 * @lcpr version=30404
 *
 * [2029] 石子游戏 IX
 */

#include <bits/stdc++.h>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        int cnt[3] = {};
        for (int i : stones) {
            cnt[i % 3] += 1;
        }

        if (cnt[1] > 0) {
            int rounds = 1 + min(cnt[1] - 1, cnt[2]) * 2 + cnt[0];
            if (cnt[1] - 1 > cnt[2]) {
                rounds += 1;
            }

            if (rounds < n && rounds % 2 == 1) {
                return true;
            }
        }

        if (cnt[2] > 0) {
            int rounds = 1 + min(cnt[2] - 1, cnt[1]) * 2 + cnt[0];
            if (cnt[2] - 1 > cnt[1]) {
                rounds += 1;
            }

            if (rounds < n && rounds % 2 == 1) {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

int main() {
    Solution solution;
    // your test code here
}



/*
// @lcpr case=start
// [2,1]\n
// @lcpr case=end

// @lcpr case=start
// [2]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,2,4,3]\n
// @lcpr case=end

 */

