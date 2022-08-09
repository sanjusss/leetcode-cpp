/*
 * @Author: sanjusss
 * @Date: 2022-08-09 08:22:07
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-09 08:29:05
 * @FilePath: \0\400\420\422.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            int m = words[i].size();
            if (m > n) {
                return false;
            }

            for (int j = 0; j < m; ++j) {
                if (words[j].size() <= i || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }

        return true;
    }
};