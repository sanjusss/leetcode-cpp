/*
 * @Author: sanjusss
 * @Date: 2022-09-04 11:24:57
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-09-04 11:33:02
 * @FilePath: \1000\1500\1580\1582.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numSpecial(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
//         int ans = 0;
//         vector<bool> rowHasOne(m);
//         vector<bool> colHasOne(n);
//         for (int i = 0; i < m; ++i) {
//             if (rowHasOne[i]) {
//                 continue;
//             }

//             for (int j = 0; j < n; ++j) {
//                 if (colHasOne[j] || mat[i][j] == 0) {
//                     continue;
//                 }

//                 rowHasOne[i] = true;
//                 colHasOne[j] = true;
//                 bool success = true;
//                 for (int k = 0; k < m; ++k) {
//                     if (k != i && mat[k][j] == 1) {
//                         success = false;
//                         break;
//                     }
//                 }

//                 if (!success) {
//                     continue;
//                 }

//                 for (int k = 0; k < n; ++k) {
//                     if (k != j && mat[i][k] == 1) {
//                         success = false;
//                         break;
//                     }
//                 }

//                 if (success) {
//                     ++ans;
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowCnt(m);
        vector<int> colCnt(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1) {
                    ++rowCnt[i];
                    ++colCnt[j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 1 && rowCnt[i] == 1 && colCnt[j] == 1) {
                    ++ans;
                }
            }
        }


        return ans;
    }
};