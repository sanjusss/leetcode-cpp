/*
 * @Author: sanjusss
 * @Date: 2021-05-29 22:03:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-29 23:16:10
 * @FilePath: \D\D000\D57\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> ans;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int eMax = min({ j, n - 1 - j, i, m - 1 - i });
                for (int e = 0; e <= eMax; ++e) {
                    int sum = 0;
                    if (e == 0) {
                        sum = grid[i][j];
                    }
                    else {
                        for (int k = 0; k < e; ++k) {
                            sum += grid[i - e + k][j + k];
                            sum += grid[i + k][j + e - k];
                            sum += grid[i + e - k][j - k];
                            sum += grid[i - k][j - e + k];
                        }
                    }

                    ans.insert(sum);
                    if (ans.size() > 3) {
                        ans.erase(ans.begin());
                    }
                }
            }
        }

        return vector<int>(ans.rbegin(), ans.rend());
    }
};

TEST(&Solution::getBiggestThree)