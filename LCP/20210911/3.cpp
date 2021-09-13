/*
 * @Author: sanjusss
 * @Date: 2021-09-11 15:34:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-11 16:04:25
 * @FilePath: \LCP\20210911\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int flipChess(vector<string>& chessboard) {
        static const vector<pair<int, int>> dirs = {
            { 0, 1 },
            { 0, -1 },
            { 1, 0 },
            { -1, 0 },
            { 1, 1 },
            { 1, -1 },
            { -1, 1 },
            { -1, -1 }
        };
        int change = 0;
        int m = chessboard.size();
        int n = chessboard[0].size();

        //尝试通过(i, j)改变白子。
        function<void(int, int)> dfs = [&](int i, int j) {
            vector<pair<int, int>> q;
            for (auto [dx, dy] : dirs) {
                bool success = false;
                int ei = i + dx;
                int ej = j + dy;
                while (ei >= 0 && ei < m && ej >= 0 && ej < n) {
                    if (chessboard[ei][ej] == 'X') {
                        success = true;
                        break;
                    }
                    else if (chessboard[ei][ej] == '.') {
                        break;
                    }
                    else {
                        ei += dx;
                        ej += dy;
                    }
                }

                if (!success) {
                    continue;
                }
                
                int ni = i + dx;
                int nj = j + dy;
                while (ni != ei || nj != ej) {
                    q.emplace_back(ni, nj);
                    ni += dx;
                    nj += dy;
                }
            }

            change += q.size();
            for (auto [ni, nj] : q) {
                chessboard[ni][nj] = 'X';
            }

            for (auto [ni, nj] : q) {
                dfs(ni, nj);
            }
        };

        int ans = 0;
        vector<string> backup = chessboard;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (chessboard[i][j] != '.') {
                    continue;
                }

                change = 0;
                chessboard[i][j] = 'X';
                dfs(i, j);
                chessboard[i][j] = '.';
                ans = max(ans, change);
                chessboard = backup;
            }
        }

        return ans;
    }
};

TEST(&Solution::flipChess)