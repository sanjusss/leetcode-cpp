/*
 * @Author: sanjusss
 * @Date: 2022-02-24 08:59:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-24 09:12:43
 * @FilePath: \1000\1700\1700\1706.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int& c = ans[i];
            c = i;
            for (int j = 0; j < m; ++j) {
                if (grid[j][c] == 1) {
                    if (c + 1 < n && grid[j][c + 1] == 1) {
                        ++c;
                    }
                    else {
                        c = -1;
                        break;
                    }
                }
                else {
                    if (c - 1 >= 0 && grid[j][c - 1] == -1) {
                        --c;
                    }
                    else {
                        c = -1;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};