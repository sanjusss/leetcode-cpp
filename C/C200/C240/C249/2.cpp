/*
 * @Author: sanjusss
 * @Date: 2021-07-11 10:24:26
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-07-11 10:47:40
 * @FilePath: \C\C200\C240\C249\2.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<bool> front(26);
        vector<vector<bool>> mid(26, vector<bool>(26));
        vector<vector<vector<bool>>> back(26, vector<vector<bool>>(26, vector<bool>(26)));
        int ans = 0;
        for (char c : s) {
            int k = c - 'a';
            if (front[k]) {
                for (int j = 0; j < 26; ++j) {
                    if (mid[k][j] && !back[k][j][k]) {
                        ++ans;
                        back[k][j][k] = true;
                    }
                }
            }

            for (int i = 0; i < 26; ++i) {
                if (front[i]) {
                    mid[i][k] = true;
                }
            }

            front[k] = true;
        }

        return ans;
    }
};