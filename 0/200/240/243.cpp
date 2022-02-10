/*
 * @Author: sanjusss
 * @Date: 2022-02-10 10:51:22
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-02-10 10:53:40
 * @FilePath: \0\200\240\243.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans = INT_MAX;
        int p1 = -1;
        int p2 = -1;
        for (int i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                p1 = i;
                if (p2 >= 0) {
                    ans = min(ans, i - p2);
                }
            }
            else if (wordsDict[i] == word2) {
                p2 = i;
                if (p1 >= 0) {
                    ans = min(ans, i - p1);
                }
            }
        }

        return ans;
    }
};