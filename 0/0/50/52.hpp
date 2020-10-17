/*
 * @Author: sanjusss
 * @Date: 2020-10-17 09:52:11
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-10-17 10:20:27
 * @FilePath: \0\0\50\52.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    int totalNQueens(int n) {
        if (n <= 0) {
            return 0;
        }

        vector<bool> cols(n);
        vector<bool> sums(n + n);
        vector<bool> diffs(n + n);
        return dfs(n, cols, sums, diffs, 0);
    }

private:
    int dfs(int n, vector<bool>& cols, vector<bool>& sums, vector<bool>& diffs, int row) {
        if (n == row) {
            return 1;
        }

        int res = 0;
        for (int col = 0; col < n; ++col) {
            int sum = row + col;
            int diff = row - col + n;
            if (cols[col] || sums[sum] || diffs[diff]) {
                continue;
            }

            cols[col] = true;
            sums[sum] = true;
            diffs[diff] = true;
            res += dfs(n, cols, sums, diffs, row + 1);
            diffs[diff] = false;
            sums[sum] = false;
            cols[col] = false;
        }

        return res;
    }
};