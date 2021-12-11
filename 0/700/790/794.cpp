/*
 * @Author: sanjusss
 * @Date: 2021-12-11 11:21:20
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-11 11:36:40
 * @FilePath: \0\700\790\794.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xcnt = 0;
        int ocnt = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X') {
                    ++xcnt;
                }
                else if (board[i][j] == 'O') {
                    ++ocnt;
                }
            }
        }

        if (xcnt - ocnt != 0 && xcnt - ocnt != 1) {
            return false;
        }

        bool xwin = false;
        bool owin = false;
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == ' ') {
                continue;
            }

            bool& win = board[i][0] == 'X' ? xwin : owin;
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                win = true;
            }
        }

        for (int j = 0; j < 3; ++j) {
            if (board[0][j] == ' ') {
                continue;
            }

            bool& win = board[0][j] == 'X' ? xwin : owin;
            if (board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
                win = true;
            }
        }

        if (board[1][1] != ' ') {
            bool& win = board[1][1] == 'X' ? xwin : owin;
            if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
                (board[1][1] == board[0][2] && board[1][1] == board[2][0])) {
                win = true;
            }
        }

        if (xwin && owin) {
            return false;
        }
        else if (xwin) {
            return xcnt - ocnt == 1;
        }
        else if (owin) {
            return xcnt == ocnt;
        }
        else {
            return true;
        }
    }
};