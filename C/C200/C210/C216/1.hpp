/*
 * @Author: sanjusss
 * @Date: 2020-11-22 10:30:46
 * @LastEditors: sanjusss
 * @LastEditTime: 2020-11-22 10:36:23
 * @FilePath: \C\C200\C210\C216\1.hpp
 */
#pragma once
#include "leetcode.h"

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int arrI = 0;
        int i = 0;
        int arrJ = 0;
        int j = 0;
        while (arrI < word1.size() && arrJ < word2.size()) {
            if (word1[arrI][i] != word2[arrJ][j]) {
                return false;
            }

            ++i;
            if (i == word1[arrI].size()) {
                i = 0;
                ++arrI;
            }

            ++j;
            if (j == word2[arrJ].size()) {
                j = 0;
                ++arrJ;
            }
        }

        return arrI == word1.size() && arrJ == word2.size();
    }
};