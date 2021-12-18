/*
 * @Author: sanjusss
 * @Date: 2021-12-18 10:12:10
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-18 10:34:31
 * @FilePath: \0\400\410\419.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                if ((i > 0 && board[i - 1][j] == 'X') || (j > 0 && board[i][j - 1] == 'X')) {
                    continue;
                }

                ++ans;
            }
        }

        return ans;
    }
};