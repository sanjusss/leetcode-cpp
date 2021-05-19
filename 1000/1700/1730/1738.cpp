/*
 * @Author: sanjusss
 * @Date: 2021-05-19 08:25:30
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-19 08:45:24
 * @FilePath: \1000\1700\1730\1738.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int kthLargestValue(vector<vector<int>>& matrix, int k) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         priority_queue<int, vector<int>, greater<int>> q;
//         vector<int> xors(n);
//         for (int i = 0; i < m; ++i) {
//             int cur = 0;
//             for (int j = 0; j < n; ++j) {
//                 cur ^= matrix[i][j];
//                 xors[j] ^= cur;
//                 q.push(xors[j]);
//                 if (q.size() > k) {
//                     q.pop();
//                 }
//             }
//         }

//         return q.top();
//     }
// };

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> xors(n);
        vector<int> arr;
        arr.reserve(m * n);
        for (int i = 0; i < m; ++i) {
            int cur = 0;
            for (int j = 0; j < n; ++j) {
                cur ^= matrix[i][j];
                xors[j] ^= cur;
                arr.push_back(xors[j]);
            }
        }

        nth_element(arr.begin(), arr.begin() + k - 1, arr.end(), greater<int>());
        return arr[k - 1];
    }
};

TEST(&Solution::kthLargestValue)