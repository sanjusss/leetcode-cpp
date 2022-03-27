/*
 * @Author: sanjusss
 * @Date: 2022-03-24 14:56:18
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-03-24 14:59:44
 * @FilePath: \0\600\660\661.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0;
                int cnt = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int x = i + dx;
                        int y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            sum += img[x][y];
                            ++cnt;
                        }
                    }
                }

                ans[i][j] = sum / cnt;
            }
        }

        return ans;
    }
};