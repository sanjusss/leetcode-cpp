#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n <= 0) {
            return ans;
        }

        vector<string> board(n, string(n, '.'));
        unordered_map<int, bool> tl;//i+j
        unordered_map<int, bool> tr;//i-j
        vector<bool> cols(n);
        dfs(ans, board, tl, tr, cols, n, 0);
        return ans;
    }

private:
    void dfs(vector<vector<string>>& ans, 
        vector<string>& board, 
        unordered_map<int, bool>& tl,
        unordered_map<int, bool>& tr,
        vector<bool>& cols,
        int n,
        int i) {
        for (int j = 0; j < n; ++j) {
            if (cols[j] || tl[i + j] || tr[i - j]) {
                continue;
            }

            board[i][j] = 'Q';
            if (n == i + 1) {
                ans.push_back(board);
            }
            else {
                cols[j] = true;
                tl[i + j] = true;
                tr[i - j] = true;
                dfs(ans, board, tl, tr, cols, n, i + 1);

                cols[j] = false;
                tl[i + j] = false;
                tr[i - j] = false;
            }

            board[i][j] = '.';
        }
    }
};