#pragma once
#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
//         vector<vector<int>> ans;
//         for (int r = 0; r < R; ++r) {
//             for (int c = 0; c < C; ++c) {
//                 ans.push_back({ r, c });
//             }
//         }

//         sort(ans.begin(), ans.end(), [&](const vector<int>& a, const vector<int>& b){
//             return (abs(a[0] - r0) + abs(a[1] - c0)) < (abs(b[0] - r0) + abs(b[1] - c0));
//         });
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        static const vector<vector<int>> dirs = {
            { 1, 1 },
            { 1, -1 },
            { -1, -1 },
            { -1, 1 }
        };

        int maxDist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector<vector<int>> ans;
        ans.push_back({ r0, c0 });
        int r;
        int c;
        for (int d = 1; d <= maxDist; ++d) {
            r = r0 - d;
            c = c0;
            for (auto& dir : dirs) {
                for (int i = 0; i < d; ++i) {
                    if (r >= 0 && r < R && c >= 0 && c < C) {
                        ans.push_back({ r, c });
                    }

                    r += dir[0];
                    c += dir[1];
                }
            }
        }

        return ans;
    }
};