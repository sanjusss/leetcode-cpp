#include "leetcode.h"

// class Solution {
// public:
//     vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
//         for (auto& row : A) {
//             reverse(row.begin(), row.end());
//             for (int& i : row) {
//                 if (i == 1) {
//                     i = 0;
//                 }
//                 else {
//                     i = 1;
//                 }
//             }
//         }

//         return A;
//     }
// };

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (auto& row : A) {
            int n = row.size();
            int left = 0;
            int right = n - 1;
            while (left < right) {
                if (row[left] == row[right]) {
                    if (row[left] == 1) {
                        row[left] = 0;
                        row[right] = 0;
                    }
                    else  {
                        row[left] = 1;
                        row[right] = 1;
                    }
                }

                ++left;
                --right;
            }

            if (left == right) {
                row[left] = row[left] == 1 ? 0 : 1;
            }
        }

        return A;
    }
};

TEST(&Solution::flipAndInvertImage)