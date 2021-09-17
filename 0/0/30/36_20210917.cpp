/*
 * @Author: sanjusss
 * @Date: 2021-09-17 08:29:14
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-17 08:50:20
 * @FilePath: \0\0\30\36_20210917.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if (!isValidRow(board, i) || !isValidCol(board, i)) {
                return false;
            }
        }

        static const vector<pair<int, int>> seqs = {
            { 0, 0 },
            { 0, 3 },
            { 0, 6 },
            { 3, 0 },
            { 3, 3 },
            { 3, 6 },
            { 6, 0 },
            { 6, 3 },
            { 6, 6 },
        };
        for (auto [i, j] : seqs) {
            if (!isValidSeq(board, i, j)) {
                return false;
            }
        }

        return true;
    }

private:
    bool isValidRow(vector<vector<char>>& board, int row) {
        vector<bool> check(9);
        for (char i : board[row]) {
            if (i != '.') {
                if (check[i - '1']) {
                    return false;
                }
                else {
                    check[i - '1'] = true;
                }
            }
        }

        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int col) {
        vector<bool> check(9);
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] != '.') {
                if (check[board[i][col] - '1']) {
                    return false;
                }
                else {
                    check[board[i][col] - '1'] = true;
                }
            }
        }

        return true;
    }

    bool isValidSeq(vector<vector<char>>& board, int top, int left) {
        vector<bool> check(9);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int row = i + top;
                int col = j + left;
                if (board[row][col] != '.') {
                    if (check[board[row][col] - '1']) {
                        return false;
                    }
                    else {
                        check[board[row][col] - '1'] = true;
                    }
                }
            }
        }

        return true;
    }
};

TEST(&Solution::isValidSudoku)