/*
 * @Author: sanjusss
 * @Date: 2022-02-10 11:17:15
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-10 11:24:46
 * @FilePath: \0\200\240\245.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = INT_MAX;
        int p1 = INT_MIN / 2;
        int p2 = INT_MIN / 2;
        int n = wordsDict.size();
        for (int i = 0; i < n; ++i) {
            bool mp1 = wordsDict[i] == word1;
            bool mp2 = wordsDict[i] == word2;
            if (mp1) {
                ans = min(ans, i - p2);
            }

            if (mp2) {
                ans = min(ans, i - p1);
            }

            if (mp1) {
                p1 = i;
            }

            if (mp2) {
                p2 = i;
            }
        }

        return ans;
    }
};