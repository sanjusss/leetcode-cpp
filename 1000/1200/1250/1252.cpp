/*
 * @Author: sanjusss
 * @Date: 2022-07-12 09:22:27
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-07-12 09:46:57
 * @FilePath: \1000\1200\1250\1252.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<bool> rows(m);
        vector<bool> cols(n);
        for (auto& i : indices) {
            rows[i[0]] = !rows[i[0]];
            cols[i[1]] = !cols[i[1]];
        }

        int ans = 0;
        int colOdd = 0;
        for (bool odd : cols) {
            if (odd) {
                ++colOdd;
            }
        }

        for (bool odd : rows) {
            if (odd) {
                ans += n - colOdd;
            }
            else {
                ans += colOdd;
            }
        }

        return ans;
    }
};