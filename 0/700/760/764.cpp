/*
 * @Author: sanjusss
 * @Date: 2022-11-09 08:35:08
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-09 09:32:56
 * @FilePath: \0\700\760\764.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        for (auto& m : mines) {
            grid[m[0]][m[1]] = 0;
        }

        vector<vector<vector<int>>> cnts(n, vector<vector<int>>(n, vector<int>(4)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cnts[i][j][0] = grid[i][j] == 1 ? ((j > 0 ? cnts[i][j - 1][0] : 0) + 1) : 0;
                cnts[i][n - 1 - j][1] = grid[i][n - 1 - j] == 1 ? ((n - j < n ? cnts[i][n - j][1] : 0) + 1) : 0;
                cnts[i][j][2] = grid[i][j] == 1 ? ((i > 0 ? cnts[i - 1][j][2] : 0) + 1) : 0;
                cnts[n - 1 - i][j][3] = grid[n - 1 - i][j] == 1 ? ((n - i < n ? cnts[n - i][j][3] : 0) + 1) : 0;
            }
        }

        int ans = 0;
        for (auto& r : cnts) {
            for (auto& c : r) {
                ans = max(ans, *min_element(c.begin(), c.end()));
            }
        }

        return ans;
    }
};

TEST(&Solution::orderOfLargestPlusSign)