/*
 * @Author: sanjusss
 * @Date: 2021-08-19 09:03:12
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-19 09:18:11
 * @FilePath: \jianzhioffer\12.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        static const vector<pair<int, int>> dirs = {
            { 1, 0 },
            { -1, 0 },
            { 0, 1 },
            { 0, -1 },
        };
        int m = board.size();
        int n = board[0].size();
        function<bool(int, int, int)> dfs = [&](int i, int j, int wordi) -> bool {
            if (board[i][j] != word[wordi]) {
                return false;
            }

            board[i][j] = 0;
            if (++wordi == word.size()) {
                return true;
            }

            for (auto [dx, dy] : dirs) {
                int x = i + dx;
                int y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                if (dfs(x, y, wordi)) {
                    return true;
                }
            }

            board[i][j] = word[wordi - 1];
            return false;
        };

        if (word.empty()) {
            return true;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};