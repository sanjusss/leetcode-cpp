/*
 * @Author: sanjusss
 * @Date: 2022-10-27 08:54:01
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-27 09:11:32
 * @FilePath: \0\900\990\939.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minAreaRect(vector<vector<int>>& points) {
//         unordered_map<int, unordered_set<int>> x2y;
//         unordered_map<int, unordered_set<int>> y2x;
//         int ans = INT_MAX;
//         for (auto& p : points) {
//             int x = p[0];
//             int y = p[1];
//             for (int y2 : x2y[x]) {
//                 for (int x2 : y2x[y]) {
//                     if (x2y[x2].count(y2)) {
//                         ans = min(ans, abs(x2 - x) * abs(y2 - y));
//                     }
//                 }
//             }

//             x2y[x].insert(y);
//             y2x[y].insert(x);
//         }

//         return ans == INT_MAX ? 0 : ans;
//     }
// };

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int64_t> all;
        for (auto& p : points) {
            all.insert((int64_t)p[0] << 32 | p[1]);
        }

        int n = points.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 || y1 == y2) {
                    continue;
                }

                if (all.count((int64_t)x1 << 32 | y2) && all.count((int64_t)x2 << 32 | y1)) {
                    ans = min(ans, abs(x2 - x1) * abs(y2 - y1));
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};