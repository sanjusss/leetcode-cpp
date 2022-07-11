/*
 * @Author: sanjusss
 * @Date: 2022-07-11 08:01:47
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-11 08:10:27
 * @FilePath: \0\300\340\348.cpp
 */
#include "leetcode.h"

class TicTacToe {
public:
    TicTacToe(int n) : m_n(n), m_rowCnt(2, vector<int>(n)), m_colCnt(2, vector<int>(n)), m_equalCnt(2), m_sumCnt(2) {
    }

    int move(int row, int col, int player) {
        --player;

        if (++m_rowCnt[player][row] == m_n) {
            return player + 1;
        }

        if (++m_colCnt[player][col] == m_n) {
            return player + 1;
        }

        if (row == col && ++m_equalCnt[player] == m_n) {
            return player + 1;
        }

        if (row + col == m_n - 1 && ++m_sumCnt[player] == m_n) {
            return player + 1;
        }

        return 0;
    }

private:
    int m_n;
    vector<vector<int>> m_rowCnt;
    vector<vector<int>> m_colCnt;
    vector<int> m_equalCnt;
    vector<int> m_sumCnt;
};
