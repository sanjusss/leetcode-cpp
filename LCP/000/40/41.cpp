/*
 * @Author: sanjusss
 * @Date: 2023-06-21 09:15:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-21 10:05:17
 * @FilePath: \LCP\000\40\41.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int flipChess(vector<string>& chessboard) {
        static const vector<pair<int, int>> dirs = {
            { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 },
        };

        int m = chessboard.size();
        int n = chessboard[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (chessboard[i][j] != '.') {
                    continue;
                }

                list<pair<int, int>> q;
                q.emplace_back(i, j);
                chessboard[i][j] = 'X';
                for (auto p = q.begin(); p != q.end(); ++p) {
                    auto [x, y] = *p;
                    for (auto [dx, dy] : dirs) {
                        int step = 0;
                        int nx = x;
                        int ny = y;
                        while (true) {
                            nx += dx;
                            ny += dy;
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n || chessboard[nx][ny] == '.') {
                                step = 0;
                                break;
                            }

                            if (chessboard[nx][ny] == 'O') {
                                ++step;
                            }
                            else {
                                break;
                            }
                        }

                        nx = x;
                        ny = y;
                        while (--step >= 0) {
                            nx += dx;
                            ny += dy;
                            chessboard[nx][ny] = 'X';
                            q.emplace_back(nx, ny);
                        }
                    }
                }

                ans = max(ans, int(q.size()) - 1);
                chessboard[i][j] = '.';
                for (auto p = next(q.begin()); p != q.end(); ++p) {
                    chessboard[p->first][p->second] = 'O';
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::flipChess)