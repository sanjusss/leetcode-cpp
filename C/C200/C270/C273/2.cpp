/*
 * @Author: sanjusss
 * @Date: 2021-12-26 10:24:59
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-12-26 10:42:50
 * @FilePath: \C\C200\C270\C273\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int j = i;
            int x = startPos[0];
            int y = startPos[1];
            while (j < m) {
                switch (s[j]) {
                    case 'L':
                        --y;
                        break;

                    case 'R':
                        ++y;
                        break;

                    case 'U':
                        --x;
                        break;

                    case 'D':
                        ++x;
                        break;

                    default:
                        break;
                }

                if (x < 0 || x >= n || y < 0 || y >= n) {
                    break;
                }

                ++j;
            }

            ans[i] = j - i;
        }

        return ans;
    }
};