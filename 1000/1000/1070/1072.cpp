/*
 * @Author: sanjusss
 * @Date: 2023-05-15 09:02:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-05-15 09:35:37
 * @FilePath: \1000\1000\1070\1072.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<bool>> used(m, vector<bool>(2));
//         int ans = 0;
//         for (int k = 0; k < m; ++k) {
//             for (int t = 0; t < 2; ++t) {
//                 if (used[k][t]) {
//                     continue;
//                 }

//                 int row = 0;
//                 for (int i = 0; i < m; ++i) {
//                     int sum = 0;
//                     for (int j = 0; j < n && (sum == 0 || sum == j); ++j) {
//                         if (matrix[k][j] == t) {
//                             sum += matrix[i][j];
//                         }
//                         else {
//                             sum += 1 - matrix[i][j];
//                         }
//                     }

//                     if (sum == 0) {
//                         used[i][0] = true;
//                         ++row;
//                     }
//                     else if (sum == n) {
//                         used[i][1] = true;
//                         ++row;
//                     }
//                 }

//                 ans = max(ans, row);
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         unordered_map<string, int> cnt;
//         for (int i = 0; i < m; ++i) {
//             string op;
//             string ng;
//             for (int j = 0; j < n; ++j) {
//                 op.push_back('0' + matrix[i][j]);
//                 ng.push_back('1' - matrix[i][j]);
//             }

//             ++cnt[op];
//             ++cnt[ng];
//         }

//         int ans = 0;
//         for (auto& [_, c] : cnt) {
//             ans = max(ans, c);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        unordered_map<string, int> cnt;
        for (int i = 0; i < m; ++i) {
            string s;
            for (int j = 0; j < n; ++j) {
                s.push_back('0' + (matrix[i][0] == 0 ? 1 - matrix[i][j] : matrix[i][j]));
            }

            ans = max(++cnt[s], ans);
        }

        return ans;
    }
};