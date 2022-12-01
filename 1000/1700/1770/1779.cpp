/*
 * @Author: sanjusss
 * @Date: 2022-12-01 08:18:39
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-01 08:23:07
 * @FilePath: \1000\1700\1770\1779.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int ans = -1;
        int dis = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (points[i][0] != x && points[i][1] != y) {
                continue;
            }

            int d = abs(x - points[i][0]) + abs(y - points[i][1]);
            if (d < dis) {
                dis = d;
                ans = i;
            }
        }

        return ans;
    }
};