/*
 * @Author: sanjusss
 * @Date: 2021-06-27 10:28:50
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-27 11:08:03
 * @FilePath: \C\C200\C240\C247\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int f = min(m, n) / 2 - 1; f >= 0; --f) {
            int i = f;
            int j = f;
            int cm = m - 2 * f;
            int cn = n - 2 * f;
            int ck = k % (2 * cm + 2 * cn - 4);
            while (i < f + cm - 1) {
                auto [ni, nj] = nextPos(i, j, f, cm, cn, ck);
                ans[ni][nj] = grid[i][j];
                ++i;
            }

            while (j < f + cn - 1) {
                auto [ni, nj] = nextPos(i, j, f, cm, cn, ck);
                ans[ni][nj] = grid[i][j];
                ++j;
            }
            
            while (i > f) {
                auto [ni, nj] = nextPos(i, j, f, cm, cn, ck);
                ans[ni][nj] = grid[i][j];
                --i;
            }

            while (j > f) {
                auto [ni, nj] = nextPos(i, j, f, cm, cn, ck);
                ans[ni][nj] = grid[i][j];
                --j;
            }
        }

        return ans;
    }

private:
    static pair<int, int> nextPos(int i, int j, int f, int cm, int cn, int ck) {
        if (ck == 0) {
            return { i, j };
        }
        else if (j == f) {//左
            if (f + cm - 1 - i < ck) {
                return nextPos(f + cm - 1, f + 1, f, cm, cn, ck - (f + cm - i));
            }
            else {
                return { i + ck, j };
            }
        }
        else if (j == f + cn - 1) {//右
            if (i - f < ck) {
                return nextPos(f, f + cn - 2, f, cm, cn, ck - (i - f + 1));
            }
            else {
                return { i - ck, j };
            }
        }
        else if (i == f) { // 上
            if (j - f < ck) {
                return nextPos(f + 1, f, f, cm, cn, ck - (j - f + 1));
            }
            else {
                return { i, j - ck };
            }
        }
        else {// 下
            if (f + cn - 1 - j < ck) {
                return nextPos(i - 1, f + cn - 1, f, cm, cn, ck - (f + cn - j));
            }
            else {
                return { i, j + ck };
            }
        }
    }
};