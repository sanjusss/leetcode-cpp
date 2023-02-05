#include "leetcode.h"

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<bool>>> passed(n, vector<vector<bool>>(n, vector<bool>(2)));
        passed[0][0][0] = true;
        queue<tuple<int, int, bool>> q;
        q.emplace(0, 0, true);
        for (int step = 0; !q.empty(); ++step) {
            for (int qi = q.size(); qi > 0; --qi) {
                auto [i, j, toRight] = q.front();
                q.pop();
                if (i == n - 1 && j == n - 2 && toRight) {
                    return step;
                }

                if (toRight) {
                    if (j + 2 < n && grid[i][j + 2] == 0 && !passed[i][j + 1][0]) {
                        passed[i][j + 1][0] = true;
                        q.emplace(i, j + 1, true);
                    }

                    if (i + 1 < n && grid[i + 1][j] == 0 && grid[i + 1][j + 1] == 0 && !passed[i + 1][j][0]) {
                        passed[i + 1][j][0] = true;
                        q.emplace(i + 1, j, true);
                    }

                    if (i + 1 < n && grid[i + 1][j] == 0 && grid[i + 1][j + 1] == 0 && !passed[i][j][1]) {
                        passed[i][j][1] = true;
                        q.emplace(i, j, false);
                    }
                }
                else {
                    if (j + 1 < n && grid[i][j + 1] == 0 && grid[i + 1][j + 1] == 0 && !passed[i][j + 1][1]) {
                        passed[i][j + 1][1] = true;
                        q.emplace(i, j + 1, false);
                    }

                    if (i + 2 < n && grid[i + 2][j] == 0 && !passed[i + 1][j][1]) {
                        passed[i + 1][j][1] = true;
                        q.emplace(i + 1, j, false);
                    }

                    if (j + 1 < n && grid[i][j + 1] == 0 && grid[i + 1][j + 1] == 0 && !passed[i][j][0]) {
                        passed[i][j][0] = true;
                        q.emplace(i, j, true);
                    }
                }
            }
        }

        return -1;
    }
};

TEST(&Solution::minimumMoves)