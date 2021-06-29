/*
 * @Author: sanjusss
 * @Date: 2021-06-27 16:36:40
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-27 16:54:30
 * @FilePath: \0\900\900\909.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int m = n * n;
        vector<int> jump{ 0 };
        jump.reserve(m + 1);
        for (int i = n - 1; i >= 0; --i) {
            if ((n - 1 - i) & 1) {
                for (int j = n - 1; j >= 0; --j) {
                    jump.push_back(board[i][j]);
                }
            }
            else {
                for (int j = 0; j < n; ++j) {
                    jump.push_back(board[i][j]);
                }
            }
        }

        int step = 0;
        vector<bool> passed(m + 1);
        passed[1] = true;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            ++step;
            for (int c = q.size(); c > 0; --c) {
                int i = q.front();
                q.pop();
                for (int j = min(i + 6, m); j > i; --j) {
                    if (j == m) {
                        return step;
                    }
                    else if (jump[j] >= 0) {
                        if (jump[j] == m) {
                            return step;
                        }
                        else if (!passed[jump[j]]) {
                            passed[jump[j]] = true;
                            q.push(jump[j]);
                        }
                    }
                    else {
                        if (!passed[j]) {
                            passed[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return -1;
    }
};

TEST(&Solution::snakesAndLadders)