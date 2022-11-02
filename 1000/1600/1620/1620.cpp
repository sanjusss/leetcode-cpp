/*
 * @Author: sanjusss
 * @Date: 2022-11-02 08:43:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-02 08:53:02
 * @FilePath: \1000\1600\1620\1620.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxV = 0;
        int r2 = radius * radius;
        vector<int> ans(2);
        for (int x = 0; x <= 50; ++x) {
            for (int y = 0; y <= 50; ++y) {
                int v = 0;
                for (auto& t : towers) {
                    int xi = t[0];
                    int yi = t[1];
                    int qi = t[2];
                    int d2 = (x - xi) * (x - xi) + (y - yi) * (y - yi);
                    if (d2 > r2) {
                        continue;
                    }

                    v += qi / (1 + sqrt((double)d2));
                }

                if (v > maxV) {
                    maxV = v;
                    ans[0] = x;
                    ans[1] = y;
                }
            }
        }

        return ans;
    }
};

TEST(&Solution::bestCoordinate)