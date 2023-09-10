/*
 * @Author: sanjusss
 * @Date: 2023-07-30 10:31:19
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-10 11:18:04
 * @FilePath: \C\C300\C360\C362\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int endMask = 1 << 9;
        int all = endMask - 1;
        vector<int> dp(endMask, INT_MAX / 2);
        vector<tuple<int, int, int>> es; 
        int beginMask = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] > 0) {
                    beginMask |= 1 << (i * 3 + j);
                }
                else {
                    es.emplace_back(i, j, 1 << (i * 3 + j));
                }
            }
        }

        dp[beginMask] = 0;
        int cnt = 9 - es.size();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = grid[i][j] - 1; k > 0; --k) {
                    for (auto [x, y, pos] : es) {
                        for (int mask = all; mask >= beginMask; --mask) {
                            if ((mask & pos) || dp[mask] >= INT_MAX / 2 || __builtin_popcount(mask) != cnt) {
                                continue;
                            }

                            dp[mask | pos] = min(dp[mask | pos], dp[mask] + abs(i - x) + abs(j - y));
                        }
                    }

                    ++cnt;
                }
            }
        }

        return dp[all];
    }
};

TEST(&Solution::minimumMoves)