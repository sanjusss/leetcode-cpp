/*
 * @Author: sanjusss
 * @Date: 2023-06-04 10:29:51
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-06-04 11:10:07
 * @FilePath: \C\C300\C340\C348\3.cpp
 */
#include "leetcode.h"

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        int m = queries.size();
        for (int i = 0; i < m; ++i) {
            auto& q = queries[i];
            if (q[0] == 0) {
                rows[q[1]] = i;
            }
            else {
                cols[q[1]] = i;
            }
        }

        int64_t rowChangeSum = 0;
        int64_t colChangeSum = 0;
        int64_t ans = 0;
        for (int i = 0; i < m; ++i) {
            auto& q = queries[i];
            if (q[0] == 0) {
                if (rows[q[1]] != i) {
                    continue;
                }

                ans += (int64_t)n * (int64_t)q[2] - colChangeSum;
                rowChangeSum += q[2];
            }
            else {
                if (cols[q[1]] != i) {
                    continue;
                }

                ans += (int64_t)n * (int64_t)q[2] - rowChangeSum;
                colChangeSum += q[2];
            }
        }

        return ans;
    }
};