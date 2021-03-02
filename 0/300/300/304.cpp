/*
 * @Author: sanjusss
 * @Date: 2021-03-02 08:44:06
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-03-02 08:53:53
 * @FilePath: \0\300\300\304.cpp
 */
#include "leetcode.h"

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m == 0 ? 0 : matrix[0].size();
        m_sums = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                m_sums[i + 1][j + 1] = m_sums[i + 1][j] + matrix[i][j];
            }

            for (int j = 0; j < n; ++j) {
                m_sums[i + 1][j + 1] += m_sums[i][j + 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return m_sums[row1][col1] + m_sums[row2 + 1][col2 + 1] - m_sums[row1][col2 + 1] - m_sums[row2 + 1][col1];
    }

private:
    vector<vector<int>> m_sums;
};