/*
 * @Author: sanjusss
 * @Date: 2022-10-07 08:23:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-07 08:31:53
 * @FilePath: \0\400\460\469.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        int64_t prev = 0;
        for (int i = 0; i < n; ++i) {
            auto& p0 = points[i];
            auto& p1 = points[(i + 1) % n];
            auto& p2 = points[(i + 2) % n];
            int64_t x1 = p1[0] - p0[0];
            int64_t x2 = p2[0] - p0[0];
            int64_t y1 = p1[1] - p0[1];
            int64_t y2 = p2[1] - p0[1];
            int64_t cur = x1 * y2 - y1 * x2;
            if (cur == 0) {
                continue;
            }
            else if (prev * cur < 0) {
                return false;
            }
            else {
                prev = cur;
            }
        }

        return true;
    }
};