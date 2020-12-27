/*
 * @Author: sanjusss
 * @Date: 2020-12-27 10:50:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-12-27 11:29:14
 * @FilePath: \C\C200\C220\C221\3.hpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n);
        for (int j = 0; j < n; ++j) {
            int cur = j;
            for (int i = 0; i < m; ++i) {
                if (grid[i][cur] == 1) {
                    if (cur + 1 == n || grid[i][cur + 1] == -1) {
                        cur = -1;
                        break;
                    }
                    else {
                        ++cur;
                    }
                }
                else {
                    if (cur == 0 || grid[i][cur - 1] == 1) {
                        cur = -1;
                        break;
                    }
                    else {
                        --cur;
                    }
                }
            }

            ans[j] = cur;
        }

        return ans;
    }
};