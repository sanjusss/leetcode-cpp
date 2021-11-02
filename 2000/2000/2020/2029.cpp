/*
 * @Author: sanjusss
 * @Date: 2021-11-02 08:44:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-11-02 10:38:21
 * @FilePath: \2000\2000\2020\2029.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     bool stoneGameIX(vector<int>& stones) {
//         int n = stones.size();
//         array<int, 3> cnt = { 0 };
//         for (int i : stones) {
//             ++cnt[i % 3];
//         }

//         auto canRemove = [&](int j, int k) -> bool { return (cnt[1] - j + (cnt[2] - k) * 2) % 3 != 0; };
//         vector<vector<vector<bool>>> dp(cnt[0] + 1, vector<vector<bool>>(cnt[1] + 1, vector<bool>(cnt[2] + 1)));
//         dp[0][0][0] = n % 2 != 0;
//         for (int i = 0; i <= cnt[0]; ++i) {
//             for (int j = 0; j <= cnt[1]; ++j) {
//                 for (int k = 0; k <= cnt[2]; ++k) {
//                     if (i > 0) {  // 移除0
//                         dp[i][j][k] = dp[i][j][k] || (!dp[i - 1][j][k] && canRemove(j, k));
//                     }

//                     if (j > 0) {  // 移除1
//                         dp[i][j][k] = dp[i][j][k] || (!dp[i][j - 1][k] && canRemove(j - 1, k));
//                     }

//                     if (k > 0) {  // 移除2
//                         dp[i][j][k] = dp[i][j][k] || (!dp[i][j][k - 1] && canRemove(j, k - 1));
//                     }
//                 }
//             }
//         }

//         return dp[cnt[0]][cnt[1]][cnt[2]];
//     }
// };

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        auto isSuccess = [](int a, int b, int c) -> bool {
            // 依次取a、b
            // 正好取完，判负
            if (a == b || a == b + 1) {
                return false;
            }

            // 如果alice取完后还有剩余，不能再取，则获胜。
            // 这里是bob先取，所以mod2后余0表示最后是alice走了最后一个有效步。
            if (a > b) {
                return (1 + c) % 2 == 0;
            }
            else {
                return c % 2 == 0;
            }
        };
        int n = stones.size();
        array<int, 3> cnt = { 0 };
        for (int i : stones) {
            ++cnt[i % 3];
        }

        if (cnt[1] > 0) { // 先选1
            if (isSuccess(cnt[1] - 1, cnt[2], cnt[0])) {
                return true;
            }
        }

        if (cnt[2] > 0) { // 先选2
            if (isSuccess(cnt[2] - 1, cnt[1], cnt[0])) {
                return true;
            }
        }
        
        return false;
    }
};

TEST(&Solution::stoneGameIX)