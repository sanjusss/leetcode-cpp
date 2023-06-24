/*
 * @Author: sanjusss
 * @Date: 2023-06-24 09:31:28
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-24 21:25:36
 * @FilePath: \1000\1600\1650\1659.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
//         static const vector<pair<int, int>> dirs = {
//             { 1, 0 },
//             { -1, 0 },
//             { 0, 1 },
//             { 0, -1 },
//         };
//         int ans = 0;
//         int total = m * n;
//         function<void(int, int)> dfsExtr = [&] (int intr, int extr) {
//             int sum = 0;
//             for (int index = 0; index < total; ++index) {
//                 if (!((1 << index) & intr)) {
//                     continue;
//                 }

//                 int i = index / n;
//                 int j = index % n;
//                 sum += 120;
//                 for (auto [dx, dy] : dirs) {
//                     int x = i + dx;
//                     int y = j + dy;
//                     if (x < 0 || x >= m || y < 0 || y >= n) {
//                         continue;
//                     }

//                     int mask = 1 << (x * n + y);
//                     if ((intr & mask) || (extr & mask)) {
//                         sum -= 30;
//                     }
//                 }
//             }

//             for (int index = 0; index < total; ++index) {
//                 if (!((1 << index) & extr)) {
//                     continue;
//                 }

//                 int i = index / n;
//                 int j = index % n;
//                 sum += 40;
//                 for (auto [dx, dy] : dirs) {
//                     int x = i + dx;
//                     int y = j + dy;
//                     if (x < 0 || x >= m || y < 0 || y >= n) {
//                         continue;
//                     }

//                     int mask = 1 << (x * n + y);
//                     if ((intr & mask) || (extr & mask)) {
//                         sum += 20;
//                     }
//                 }
//             }

//             ans = max(ans, sum);
//             if (__builtin_popcount(extr) == extrovertsCount) {
//                 return;
//             }

//             for (int index = 0; index < total; ++index) {
//                 if (((1 << index) & extr) || ((1 << index) & intr)) {
//                     continue;
//                 }

//                 extr |= 1 << index;
//                 dfsExtr(intr, extr);
//                 extr ^= 1 << index;
//             }
//         };
//         function<void(int)> dfsIntr = [&] (int intr) {
//             for (int index = 0; index < total; ++index) {
//                 if ((1 << index) & intr) {
//                     continue;
//                 }

//                 intr |= 1 << index;
//                 dfsExtr(intr, 0);
//                 if (__builtin_popcount(intr) < introvertsCount) {
//                     dfsIntr(intr);
//                 }

//                 intr ^= 1 << index;
//             }
//         };
//         dfsIntr(0);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
//         static const vector<vector<int>> sc_diff = {
//             { 0, 0, 0 },
//             { 0, -60, -10 },
//             { 0, -10, 40 },
//         };
//         int allMask = pow(3, n);
//         vector<int> inCount(allMask);
//         vector<int> exCount(allMask);
//         vector<int> rowSum(allMask);

//         for (int mask = 0; mask < allMask; ++mask) {
//             int cur = mask;
//             while (cur > 0) {
//                 switch (cur % 3) {
//                     case 1:
//                         ++inCount[mask];
//                         rowSum[mask] += 120;
//                         break;

//                     case 2:
//                         ++exCount[mask];
//                         rowSum[mask] += 40;
//                         break;

//                     default:
//                         break;
//                 }

//                 cur /= 3;
//             }
//         }

//         vector<vector<int>> rowDiff(allMask, vector<int>(allMask));
//         for (int pre = 0; pre < allMask; ++pre) {
//             for (int cur = 0; cur < allMask; ++cur) {
//                 int mp = pre;
//                 int mc = cur;
//                 for (int k = 0; k < n; ++k) {
//                     int tp = mp % 3;
//                     int tc = mc % 3;
//                     rowDiff[pre][cur] += sc_diff[tp][tc];
//                     mp /= 3;
//                     mc /= 3;
//                     rowDiff[pre][cur] += sc_diff[mc % 3][tc];
//                 }
//             }
//         }

//         vector<vector<vector<vector<int>>>> dp(
//             m, vector<vector<vector<int>>>(allMask,
//                                            vector<vector<int>>(introvertsCount + 1, vector<int>(extrovertsCount + 1,
//                                            -1))));
//         function<int(int, int, int, int)> dfs = [&](int row, int pre, int inRes, int exRes) -> int {
//             if (row == m || (inRes == 0 && exRes == 0)) {
//                 return 0;
//             }

//             int& ans = dp[row][pre][inRes][exRes];
//             if (ans >= 0) {
//                 return ans;
//             }

//             ans = 0;
//             for (int cur = 0; cur < allMask; ++cur) {
//                 if (inCount[cur] > inRes || exCount[cur] > exRes) {
//                     continue;
//                 }

//                 int sum =
//                     rowSum[cur] + rowDiff[pre][cur] + dfs(row + 1, cur, inRes - inCount[cur], exRes - exCount[cur]);
//                 ans = max(ans, sum);
//             }

//             return ans;
//         };

//         return dfs(0, 0, introvertsCount, extrovertsCount);
//     }
// };

class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        static const vector<vector<int>> sc_diff = {
            { 0, 0, 0 },
            { 0, -60, -10 },
            { 0, -10, 40 },
        };
        static const vector<int> sc_score = { 0, 120, 40 };
        int allMask = pow(3, n - 1);
        int total = m * n;
        vector<vector<vector<vector<int>>>> dp(
            total, vector<vector<vector<int>>>(
                       allMask * 3, vector<vector<int>>(introvertsCount + 1, vector<int>(extrovertsCount + 1, -1))));
        function<int(int, int, int, int)> dfs = [&](int pos, int pre, int inRes, int exRes) -> int {
            if (pos == total || (inRes == 0 && exRes == 0)) {
                return 0;
            }

            int& ans = dp[pos][pre][inRes][exRes];
            if (ans >= 0) {
                return ans;
            }

            ans = 0;
            int up = pre / allMask;
            for (int i = 0; i < 3; ++i) {
                if (i == 1 && inRes == 0) {
                    continue;
                }
                else if (i == 2 && exRes == 0) {
                    continue;
                }

                int sum = sc_score[i] + sc_diff[up][i];
                if (pos % n != 0) {
                    sum += sc_diff[pre % 3][i];
                }

                int cur = (pre % allMask) * 3 + i;
                sum += dfs(pos + 1, cur, i == 1 ? inRes - 1 : inRes, i == 2 ? exRes - 1 : exRes);
                ans = max(ans, sum);
            }

            return ans;
        };

        return dfs(0, 0, introvertsCount, extrovertsCount);
    }
};