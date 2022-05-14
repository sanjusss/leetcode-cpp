/*
 * @Author: sanjusss
 * @Date: 2022-05-14 11:34:37
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-05-14 12:29:08
 * @FilePath: \0\600\690\691.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minStickers(vector<string>& stickers, string target) {
//         int n = target.size();
//         int all = (1 << n) - 1;
//         vector<int> dp(all + 1, 2 * n);
//         dp[0] = 0;
//         array<int, 26> owns;
//         for (auto& s : stickers) {
//             for (int mask = 1; mask <= all; ++mask) {
//                 for (int b = 0; b < n; ++b) {
//                     owns.fill(0);
//                     for (char i : s) {
//                         ++owns[i - 'a'];
//                     }
//                     int adds = 0;
//                     for (int i = b; i < n; ++i) {
//                         if (!(mask & (1 << i))) {
//                             continue;
//                         }

//                         if (--owns[target[i] - 'a'] < 0) {
//                             continue;
//                         }

//                         adds |= 1 << i;
//                     }

//                     if (adds > 0) {
//                         dp[mask] = min(dp[mask], dp[mask ^ adds] + 1);
//                     }
//                 }
//             }
//         }

//         return dp[all] <= n ? dp[all] : -1;
//     }
// };

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        function<int(int)> dfs = [&](int mask) -> int {
            if (dp[mask] >= 0) {
                return dp[mask];
            }

            dp[mask] = 2 * n;
            array<int, 26> cnt;
            for (auto& s : stickers) {
                cnt.fill(0);
                for (char i : s) {
                    ++cnt[i - 'a'];
                }

                int adds = 0;
                for (int i = 0; i < n; ++i) {
                    if (!(mask & (1 << i))) {
                        continue;
                    }

                    if (--cnt[target[i] - 'a'] < 0) {
                        continue;
                    }

                    adds |= 1 << i;
                }

                if (adds > 0) {
                    dp[mask] = min(dp[mask], dfs(mask ^ adds) + 1);
                }
            }

            return dp[mask];
        };

        int ans = dfs((1 << n) - 1);
        if (ans <= n) {
            return ans;
        }
        else {
            return -1;
        }
    }
};