#include "leetcode.h"

// class Solution {
// public:
//     bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         unordered_map<int, int> vs;
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (vs.find(i - j) == vs.end()) {
//                     vs[i - j] = matrix[i][j];
//                 }
//                 else if (vs[i - j] != matrix[i][j]) {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
// };

// class Solution {
// public:
//     bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         for (int i = -n + 1; i < m; ++i) {
//             int v = 0;
//             bool init = false;
//             int xMin = max(i, 0);
//             int xMax = min(i + n - 1, m - 1);
//             for (int x = xMin; x <= xMax; ++x) {
//                 if (init) {
//                     if (v != matrix[x][x - i]) {
//                         return false;
//                     }
//                 }
//                 else {
//                     init = true;
//                     v = matrix[x][x - i];
//                 }
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};

TEST(&Solution::isToeplitzMatrix)