/*
 * @Author: sanjusss
 * @Date: 2021-08-20 09:04:52
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-08-20 11:10:29
 * @FilePath: \0\300\300\308.cpp
 */
#include "leetcode.h"

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) : m(matrix.size()), n(matrix[0].size()) {
        sums = vector<vector<int>>(m * 2, vector<int>(n * 2));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sums[i + m][j + n] = matrix[i][j];
            }
        }

        for (int i = m; i < 2 * m; ++i) {
            for (int j = n - 1; j > 0; --j) {
                sums[i][j] = sums[i][j * 2] + sums[i][j * 2 + 1];
            }
        }

        for (int j = 1; j < 2 * n; ++j) {
            for (int i = m - 1; i > 0; --i) {
                sums[i][j] = sums[i * 2][j] + sums[i * 2 + 1][j];
            }
        }
    }

    void update(int row, int col, int val) {
        row += m;
        col += n;
        int diff = val - sums[row][col];
        for (int j = col; j > 0; j /= 2) {
            sums[row][j] += diff;
            for (int i = row / 2; i > 0; i /= 2) {
                sums[i][j] += diff;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        row1 += m;
        row2 += m;
        while (row1 <= row2) {
            if (row1 % 2 == 1) {
                sum += rowSum(row1++, col1, col2);
            }

            if (row2 % 2 == 0) {
                sum += rowSum(row2--, col1, col2);
            }

            row1 /= 2;
            row2 /= 2;
        }

        return sum;
    }

private:
    int rowSum(int row, int left, int right) const {
        const auto& arr = sums[row];
        int sum = 0;
        left += n;
        right += n;
        while (left <= right) {
            if (left % 2 == 1) {
                sum += arr[left++];
            }

            if (right % 2 == 0) {
                sum += arr[right--];
            }

            left /= 2;
            right /= 2;
        }

        return sum;
    }

private:
    const int m;
    const int n;
    vector<vector<int>> sums;
};
