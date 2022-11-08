/*
 * @Author: sanjusss
 * @Date: 2022-11-08 08:50:56
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-08 09:10:48
 * @FilePath: \0\500\530\533.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
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
        for (int j = 0; j < n; ++j) {
            if (col[j] != target) {
                continue;
            }

            bool success = true;
            int r0 = -1;
            for (int i = 0; i < m; ++i) {
                if (picture[i][j] != 'B') {
                    continue;
                }

                if (row[i] != target) {
                    success = false;
                    break;
                }

                if (r0 < 0) {
                    r0 = i;
                }
                else if (picture[i] != picture[r0]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                ans += target;
            }
        }

        return ans;
    }
};