/*
 * @Author: sanjusss
 * @Date: 2023-04-30 10:27:44
 * @LastEditors: sanjusss
 * @LastEditTime: 2023-04-30 10:50:15
 * @FilePath: \C\C300\C340\C343\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> pos(arr.size() + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[mat[i][j]].first = i;
                pos[mat[i][j]].second = j;
            }
        }

        vector<int> rows(m);
        vector<int> cols(n);
        for (int i = 0; i < arr.size(); ++i) {
            auto [x, y] = pos[arr[i]];
            if (++rows[x] == n || ++cols[y] == m) {
                return i;
            }
        }

        return -1;
    }
};