/*
 * @Author: sanjusss
 * @Date: 2021-05-29 22:03:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-30 10:25:44
 * @FilePath: \D\D000\D53\3.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     vector<int> getBiggestThree(vector<vector<int>>& grid) {
//         set<int> ans;
//         int m = grid.size();
//         int n = grid[0].size();
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 int eMax = min({ j, n - 1 - j, i, m - 1 - i });
//                 for (int e = 0; e <= eMax; ++e) {
//                     int sum = 0;
//                     if (e == 0) {
//                         sum = grid[i][j];
//                     }
//                     else {
//                         for (int k = 0; k < e; ++k) {
//                             sum += grid[i - e + k][j + k];
//                             sum += grid[i + k][j + e - k];
//                             sum += grid[i + e - k][j - k];
//                             sum += grid[i - k][j - e + k];
//                         }
//                     }

//                     ans.insert(sum);
//                     if (ans.size() > 3) {
//                         ans.erase(ans.begin());
//                     }
//                 }
//             }
//         }

//         return vector<int>(ans.rbegin(), ans.rend());
//     }
// };

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        set<int> ans;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> sums1(m + 1, vector<int>(n + 2));// 对应 / 方向
        vector<vector<int>> sums2(m + 1, vector<int>(n + 2));// 对应 \ 方向
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sums1[i + 1][j + 1] = sums1[i][j + 2] + grid[i][j];
                sums2[i + 1][j + 1] = sums2[i][j] + grid[i][j];
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // (i, j)为中心点，枚举所有菱形
                int eMax = min({ j, n - 1 - j, i, m - 1 - i });
                for (int e = 0; e <= eMax; ++e) {
                    int sum = 0;
                    if (e == 0) {
                        sum = grid[i][j];
                    }
                    else {
                        sum += sums1[i + e + 1][j + 1] - sums1[i + 1][j + e + 1]; 
                        sum += sums2[i + e + 1][j + 1] - sums2[i + 1][j - e + 1];
                        sum += sums1[i + 1][j - e + 1] - sums1[i - e + 1][j + 1];
                        sum += sums2[i + 1][j + e + 1] - sums2[i - e + 1][j + 1];
                        sum -= grid[i + e][j];
                        sum += grid[i - e][j];
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