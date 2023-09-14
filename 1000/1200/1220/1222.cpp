/*
 * @Author: sanjusss
 * @Date: 2023-09-14 13:19:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-09-14 13:28:06
 * @FilePath: \1000\1200\1220\1222.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> grids(8, vector<bool>(8));
        for (auto& q : queens) {
            grids[q[0]][q[1]] = true;
        }

        vector<vector<int>> ans;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) {
                    continue;
                }

                int x = king[0] + dx;
                int y = king[1] + dy;
                while (x >= 0 && x < 8 && y >= 0 && y < 8) {
                    if (grids[x][y]) {
                        ans.push_back(vector<int>({{ x, y }}));
                        break;
                    }
                    else {
                        x += dx;
                        y += dy;
                    }
                }
            }
        }

        return ans;
    }
};