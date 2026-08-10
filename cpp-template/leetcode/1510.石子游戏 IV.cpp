/*
 * @lc app=leetcode.cn id=1510 lang=cpp
 * @lcpr version=30404
 *
 * [1510] 石子游戏 IV
 */

#include <bits/stdc++.h>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool winnerSquareGame(int n) {
        static const int maxN = 1e5;
        static const vector<int> takes = []() {
            vector<int> ts;
            for (int i = 1; i * i <= maxN; ++i) {
                ts.push_back(i * i);
            }

            return ts;
        }();

        static const vector<bool> results = []() {
            vector<bool> rs(1 + maxN);
            for (int i = 1; i <= maxN; ++i) {
                for (int j : takes) {
                    if (i - j < 0) {
                        break;
                    } else if (rs[i - j] == false) {
                        rs[i] = true;
                        break;
                    }
                }
            }

            return rs;
        }();

        return results[n];
    }
};
// @lc code=end


/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
