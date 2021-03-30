#include "leetcode.h"

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int i = m - 1;
//         int j = 0;
//         while (i >= 0 && j < n) {
//             if (matrix[i][j] == target) {
//                 return true;
//             }
//             else if (matrix[i][j] > target) {
//                 --i;
//             }
//             else {
//                 ++j;
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](int a, const vector<int>& b) {
            return a < b[0];
        });
        if (row == matrix.begin()) {
            return false;
        }

        --row;
        return binary_search(row->begin(), row->end(), target);
    }
};

TEST(&Solution::searchMatrix)