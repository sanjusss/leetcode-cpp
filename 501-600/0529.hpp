#pragma once
#include "leetcode.h"

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();

        int x = click[0];
        int y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        }
        else {
            unordered_set<int> used;
            queue<int> q;
            int cur = (x << 16) + y;
            used.insert(cur);
            q.push(cur);
            static const vector<pair<int, int>> dirs = {
                { 1, 0 },
                { -1, 0 },
                { 0, -1 },
                { 0, 1 },
                { 1, -1 },
                { 1, 1 },
                { -1, -1 },
                { -1, 1 },
            };
            int count;
            int i;
            int j;
            int temp;
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                x = cur >> 16;
                y = cur - (x << 16);
                count = 0;
                for (auto& p : dirs) {
                    i = x + p.first;
                    j = y + p.second;
                    if (i < 0 || i >= m || j < 0 || j >= n) {
                        continue;
                    }

                    if (board[i][j] == 'M') {
                        ++count;
                    }
                }

                if (count == 0) {
                    board[x][y] = 'B';
                    for (auto& p : dirs) {
                        i = x + p.first;
                        j = y + p.second;
                        if (i < 0 || i >= m || j < 0 || j >= n) {
                            continue;
                        }

                        if (board[i][j] == 'E') {
                            temp = (i << 16) + j;
                            if (used.find(temp) == used.end()) {
                                used.insert(temp);
                                q.push(temp);
                            }
                        }
                    }
                }
                else {
                    board[x][y] = '0' + count;
                }
            }
        }

        return board;
    }
};