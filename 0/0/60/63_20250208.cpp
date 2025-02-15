#include "leetcode.h"

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                    continue;
                } else if (i == 0 && j == 0) {
                    obstacleGrid[i][j] = 1;
                    continue;
                }

                obstacleGrid[i][j] = 0;
                if (i > 0) {
                    obstacleGrid[i][j] += obstacleGrid[i - 1][j];
                }

                if (j > 0) {
                    obstacleGrid[i][j] += obstacleGrid[i][j - 1];
                }
            }
        }

        return obstacleGrid[m - 1][n - 1];
    }
};