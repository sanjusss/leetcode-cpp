/*
 * @Author: sanjusss
 * @Date: 2021-05-29 08:26:03
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-29 11:54:50
 * @FilePath: \1000\1000\1070\1074.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int ans = 0;
//         for (int i = 0; i < m; ++i) {
//             int row = 0;
//             for (int j = 0; j < n; ++j) {
//                 row += matrix[i][j];
//                 matrix[i][j] = row;
//                 if (i > 0) {
//                     matrix[i][j] += matrix[i - 1][j];
//                 }

//                 for (int k = 0; k <= i; ++k) {
//                     for (int l = 0; l <= j; ++l) {
//                         int val = matrix[i][j];
//                         if (k > 0 && l > 0) {
//                             val += matrix[k - 1][l - 1];
//                         }

//                         if (k > 0) {
//                             val -= matrix[k - 1][j];
//                         }

//                         if (l > 0) {
//                             val -= matrix[i][l - 1];
//                         }

//                         if (val == target) {
//                             ++ans;
//                         }
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        if (m <= n) {
            vector<int> sums(n);
            for (int i = 0; i < m; ++i) {
                fill(sums.begin(), sums.end(), 0);
                for (int j = i; j < m; ++j) {
                    for (int k = 0; k < n; ++k) {
                        sums[k] += matrix[j][k];
                    }

                    ans += count(sums, target);
                }
            }
        }
        else {
            vector<int> sums(m);
            for (int i = 0; i < n; ++i) {
                fill(sums.begin(), sums.end(), 0);
                for (int j = i; j < n; ++j) {
                    for (int k = 0; k < m; ++k) {
                        sums[k] += matrix[k][j];
                    }

                    ans += count(sums, target);
                }
            }
        }

        return ans;
    }

private:
    int count(vector<int>& nums, int target) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int sum = 0;
        int res = 0;
        for (int i : nums) {
            sum += i;
            auto p = cnt.find(sum - target);
            if (p != cnt.end()) {
                res += p->second;
            }

            ++cnt[sum];
        }

        return res;
    }
};

TEST(&Solution::numSubmatrixSumTarget)