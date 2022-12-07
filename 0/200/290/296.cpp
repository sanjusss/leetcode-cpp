/*
 * @Author: sanjusss
 * @Date: 2022-12-06 09:43:09
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-12-07 10:50:22
 * @FilePath: \0\200\290\296.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int minTotalDistance(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> lefts(m, vector<int>(n));   // 所有在点左边的点到当前点的距离
//         vector<vector<int>> rights(m, vector<int>(n));  // 所有在点右边的点到当前点的距离
//         vector<vector<int>> curs(m, vector<int>(n));    // 所有点和当前点同列到当前点的距离
//         vector<int> cnt(n + 1);                         // 到第i-1列时的点的数量
//         for (int j = 0; j < n; ++j) {
//             cnt[j + 1] = cnt[j];
//             for (int i = 0; i < m; ++i) {
//                 cnt[j + 1] += grid[i][j];
//             }
//         }

//         for (int j = 0; j < n; ++j) {
//             for (int i = 0; i < m; ++i) {
//                 for (int k = 0; k < m; ++k) {
//                     curs[i][j] += abs(i - k) * grid[k][j];
//                 }
//             }
//         }

//         for (int j = 1; j < n; ++j) {
//             for (int i = 0; i < m; ++i) {
//                 lefts[i][j] = lefts[i][j - 1] + curs[i][j - 1] + cnt[j];
//             }
//         }

//         for (int j = n - 2; j >= 0; --j) {
//             for (int i = 0; i < m; ++i) {
//                 rights[i][j] = rights[i][j + 1] + curs[i][j + 1] + cnt[n] - cnt[j + 1];
//             }
//         }

//         int ans = INT_MAX;
        // for (int j = 0; j < n; ++j) {
        //     for (int i = 0; i < m; ++i) {
        //         ans = min(ans, lefts[i][j] + curs[i][j] + rights[i][j]);
        //     }
        // }

//         return ans;
//     }
// };

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> lefts(m, vector<int>(n));   // 所有在点左边的点到当前点的距离
        vector<vector<int>> rights(m, vector<int>(n));  // 所有在点右边的点到当前点的距离
        vector<vector<int>> curs(m, vector<int>(n));    // 所有点和当前点同列到当前点的距离
        vector<int> cnt(n + 1);                         // 到第i-1列时的点的数量
        for (int j = 0; j < n; ++j) {
            cnt[j + 1] = cnt[j];
            for (int i = 0; i < m; ++i) {
                cnt[j + 1] += grid[i][j];
            }
        }

        for (int j = 0; j < n; ++j) {
            int sum = 0;
            int c = 0;
            for (int i = 0; i < m; ++i) {
                sum += c;
                curs[i][j] += sum;
                c += grid[i][j];
            }

            sum = 0;
            c = 0;
            for (int i = m - 1; i >= 0; --i) {
                sum += c;
                curs[i][j] += sum;
                c += grid[i][j];
            }
        }

        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                lefts[i][j] = lefts[i][j - 1] + curs[i][j - 1] + cnt[j];
            }
        }

        for (int j = n - 2; j >= 0; --j) {
            for (int i = 0; i < m; ++i) {
                rights[i][j] = rights[i][j + 1] + curs[i][j + 1] + cnt[n] - cnt[j + 1];
            }
        }

        int ans = INT_MAX;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                ans = min(ans, lefts[i][j] + curs[i][j] + rights[i][j]);
            }
        }

        return ans;
    }
};