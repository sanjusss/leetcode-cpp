/*
 * @Author: sanjusss
 * @Date: 2022-11-07 09:53:48
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-07 09:58:08
 * @FilePath: \0\500\530\531.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        int n = picture[0].size();
        vector<int> row(m);
        vector<int> col(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B') {
                    ++row[i];
                    ++col[j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};