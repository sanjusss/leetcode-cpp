/*
 * @Author: sanjusss
 * @Date: 2022-02-17 09:01:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-17 09:31:13
 * @FilePath: \0\600\680\688.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     double knightProbability(int n, int k, int row, int column) {
//         static const auto key = [] (int step, int x, int y) {
//             return step * 10000 + (x + 10) * 100 + y + 10;
//         };

//         unordered_map<int, double> dp;
//         function<double(int, int, int)> dfs = [&dp, &dfs, n] (int step, int x, int y) -> double {
//             int id = key(step, x, y);
//             if (dp.count(id)) {
//                 return dp[id];
//             }

//             if (x < 0 || x >= n || y < 0 || y >= n) {
//                 return 0;
//             }
//             else if (step == 0) {
//                 return 1;
//             }

//             double ans = 0;
//             static const vector<pair<int, int>> dirs = {
//                 { -2, -1 },
//                 { -2, 1 },
//                 { -1, -2 },
//                 { -1, 2 },
//                 { 1, -2 },
//                 { 1, 2 },
//                 { 2, -1 },
//                 { 2, 1 }
//             };
//             for (auto [dx, dy] : dirs) {
//                 int nx = x + dx;
//                 int ny = y + dy;
//                 ans += dfs(step - 1, nx, ny) * 0.125;
//             }

//             dp[id] = ans;
//             return ans;
//         };
//         return dfs(k, row, column);
//     }
// };

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        if (row < 0 || row >= n || column < 0 || column >= n) {
            return 0;
        }

        static const vector<pair<int, int>> dirs = { { -2, -1 }, { -2, 1 }, { -1, -2 }, { -1, 2 },
                                                     { 1, -2 },  { 1, 2 },  { 2, -1 },  { 2, 1 } };
        vector<vector<double>> cur(n, vector<double>(n, 1));
        auto prev = cur;
        for (; k > 0; --k) {
            swap(cur, prev);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cur[i][j] = 0;
                    for (auto [dx, dy] : dirs) {
                        int x = i + dx;
                        int y = j + dy;
                        if (x < 0 || x >= n || y < 0 || y >= n) {
                            continue;
                        }

                        cur[i][j] += prev[x][y] * 0.125;
                    }
                }
            }
        }

        return cur[row][column];
    }
};