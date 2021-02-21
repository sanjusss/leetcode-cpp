/*
 * @Author: sanjusss
 * @Date: 2021-02-21 10:18:54
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-21 11:37:23
 * @FilePath: \C\C200\C220\C229\4.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        string word = word1 + word2;
        int n = len1 + len2;
        vector<vector<int>> all(n, vector<int>(n));
        vector<vector<int>> valid(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            all[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                all[i][j] = max(all[i + 1][j], all[i][j - 1]);
                if (word[i] == word[j]) {
                    all[i][j] = max(all[i][j], all[i + 1][j - 1] + 2);
                }

                if (word[i] == word[j] && i < len1 && j >= len1) {
                    valid[i][j] = all[i][j];
                }
                else {
                    valid[i][j] = max(valid[i + 1][j], valid[i][j - 1]);
                }
            }
        }

        return valid[0][n - 1];
    }
};

TEST(&Solution::longestPalindrome)