/*
 * @Author: sanjusss
 * @Date: 2022-11-01 08:51:16
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-11-01 08:54:14
 * @FilePath: \1000\1600\1660\1662.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int wi = 0;
        int wj = 0;
        int i = 0;
        int j = 0;
        while (wi < word1.size() && wj < word2.size()) {
            if (word1[wi][i] != word2[wj][j]) {
                return false;
            }

            if (++i == word1[wi].size()) {
                ++wi;
                i = 0;
            }

            if (++j == word2[wj].size()) {
                ++wj;
                j = 0;
            }
        }

        return wi == word1.size() && wj == word2.size();
    }
};