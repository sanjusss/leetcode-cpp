#include "leetcode.h"

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return;
        }

        int m = matrix[0].size();
        if (m == 0) {
            return;
        }

        vector<bool> rows(n);
        vector<bool> cols(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (rows[i]) {
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }

        for (int j = 0; j < m; ++j) {
            if (!cols[j]) {
                continue;
            }

            for (int i = 0; i < n; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
};

TEST_N(&Solution::setZeroes, 1)