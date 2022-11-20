/*
 * @Author: sanjusss
 * @Date: 2022-11-20 15:46:35
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-20 15:53:08
 * @FilePath: \0\700\790\799.cpp
 */
#include "leetcode.h"

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur(query_row + 1);
        vector<double> prev(query_row + 1);
        cur[0] = poured;
        for (int i = 1; i <= query_row; ++i) {
            swap(cur, prev);
            for (int j = 0; j <= i; ++j) {
                cur[j] = 0;
                if (j < i) {
                    cur[j] += max<double>((prev[j] - 1) / 2, 0);
                }

                if (j > 0) {
                    cur[j] += max<double>((prev[j - 1] - 1) / 2, 0);
                }
            }
        }

        return min<double>(cur[query_glass], 1);
    }
};