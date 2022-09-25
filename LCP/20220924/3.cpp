/*
 * @Author: sanjusss
 * @Date: 2022-09-24 15:37:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-24 16:56:47
 * @FilePath: \LCP\20220924\3.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> ballGame(int num, vector<string>& plate) {
//         static const vector<pair<int, int>> dirs = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
//         int m = plate.size();
//         int n = plate[0].size();

//         vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(4)));
//         queue<tuple<int, int, int>> q;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (plate[i][j] != 'O') {
//                     continue;
//                 }

//                 for (int d = 0; d < 4; ++d) {
//                     dp[i][j][d] = true;
//                     q.emplace(i, j, d);
//                 }
//             }
//         }

//         for (int step = 1; step <= num && !q.empty(); ++step) {
//             for (int qi = q.size(); qi > 0; --qi) {
//                 auto [i, j, d] = q.front();
//                 q.pop();

//                 auto [di, dj] = dirs[d];
//                 i += di;
//                 j += dj;
//                 if (i < 0 || i >= m || j < 0 || j >= n) {
//                     continue;
//                 }

//                 if (plate[i][j] == 'E') {
//                     d = (d + 1) % 4;
//                 }
//                 else if (plate[i][j] == 'W') {
//                     d = (d + 4 - 1) % 4;
//                 }

//                 if (dp[i][j][d]) {
//                     continue;
//                 }

//                 dp[i][j][d] = true;
//                 q.emplace(i, j, d);
//             }
//         }

//         vector<vector<int>> ans;
//         for (int i = 1; i < m - 1; ++i) {
//             if (dp[i][0][3] && plate[i][0] == '.') {
//                 ans.push_back({ i, 0 });
//             }

//             if (dp[i][n - 1][1] && plate[i][n - 1] == '.') {
//                 ans.push_back({ i, n - 1 });
//             }
//         }

//         for (int j = 1; j < n - 1; ++j) {
//             if (dp[0][j][2] && plate[0][j] == '.') {
//                 ans.push_back({ 0, j });
//             }

//             if (dp[m - 1][j][0] && plate[m - 1][j] == '.') {
//                 ans.push_back({ m - 1, j });
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        static const vector<pair<int, int>> dirs = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
        int m = plate.size();
        int n = plate[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(4, INT_MAX)));
        auto pass = [&](int i, int j, int d) -> bool {
            if (plate[i][j] != '.') {
                return false;
            }

            stack<tuple<int, int, int>> s;
            int res = -1;
            for (int step = 0; step <= num; ++step) {
                if (dp[i][j][d] != INT_MAX) {
                    res = dp[i][j][d];
                    break;
                }
                else if (plate[i][j] == 'O') {
                    dp[i][j][d] = 0;
                    res = 0;
                    break;
                }
                else if (step == num) {
                    return false;
                }

                s.emplace(i, j, d);
                if (plate[i][j] == 'E') {
                    d = (d + 4 - 1) % 4;
                }
                else if (plate[i][j] == 'W') {
                    d = (d + 1) % 4;
                }

                i += dirs[d].first;
                j += dirs[d].second;
                if (i < 0 || i >= m || j < 0 || j >= n) {
                    break;
                }
            }

            while (!s.empty()) {
                auto [si, sj, sd] = s.top();
                s.pop();
                if (res != -1) {
                    ++res;
                }

                dp[si][sj][sd] = res;
            }

            return res != -1 && res <= num;
        };

        vector<vector<int>> ans;
        for (int i = 1; i < m - 1; ++i) {
            if (pass(i, 0, 1)) {
                ans.push_back({ i, 0 });
            }

            if (pass(i, n - 1, 3)) {
                ans.push_back({ i, n - 1 });
            }
        }

        for (int j = 1; j < n - 1; ++j) {
            if (pass(0, j, 0)) {
                ans.push_back({ 0, j });
            }

            if (pass(m - 1, j, 2)) {
                ans.push_back({ m - 1, j });
            }
        }

        return ans;
    }
};

TEST_EQUIVALENT(&Solution::ballGame)