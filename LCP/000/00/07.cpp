/*
 * @Author: sanjusss
 * @Date: 2021-07-01 07:38:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-01 07:47:36
 * @FilePath: \LCP\000\00\07.cpp
 */
#include "leetcode.h"

// class Solution {
// public:
//     int numWays(int n, vector<vector<int>>& relation, int k) {
//         vector<vector<int>> conns(n);
//         for (auto& r : relation) {
//             conns[r[0]].push_back(r[1]);
//         }

//         vector<int> cur(n);
//         vector<int> prev(n);
//         cur[0] = 1;
//         for (int i = 0; i < k; ++i) {
//             swap(cur, prev);
//             fill(cur.begin(), cur.end(), 0);
//             for (int j = 0; j < n; ++j) {
//                 for (int next : conns[j]) {
//                     cur[next] += prev[j];
//                 }
//             }
//         }

//         return cur[n - 1];
//     }
// };

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<int> cur(n);
        vector<int> prev(n);
        cur[0] = 1;
        for (int i = 0; i < k; ++i) {
            swap(cur, prev);
            fill(cur.begin(), cur.end(), 0);
            for (auto& r : relation) {
                cur[r[1]] += prev[r[0]];
            }
        }

        return cur[n - 1];
    }
};

TEST(&Solution::numWays)