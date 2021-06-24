/*
 * @Author: sanjusss
 * @Date: 2021-06-24 08:16:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-06-24 08:41:29
 * @FilePath: \0\100\140\149.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) {
            return n;
        }

        vector<tuple<int, int, int, int>> lines;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (auto& [count, a, b, c] : lines) {
                if (a * x1 + b * y1 + c == 0) {
                    ++count;
                }
            }

            for (int j = 0; j < i; ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                lines.emplace_back(2, y2 - y1, x1 - x2, x2 * y1 - x1 * y2);
            }
        }

        return get<0>(*max_element(lines.begin(), lines.end()));
    }
};

TEST(&Solution::maxPoints)