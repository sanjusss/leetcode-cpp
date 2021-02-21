/*
 * @Author: sanjusss
 * @Date: 2021-02-21 10:18:42
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-02-21 10:36:17
 * @FilePath: \C\C200\C220\C229\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i = 0;
        int j = 0;
        while (i < word1.size() && j < word2.size()) {
            ans.push_back(word1[i++]);
            ans.push_back(word2[j++]);
        }

        while (i < word1.size()) {
            ans.push_back(word1[i++]);
        }

        while (j < word2.size()) {
            ans.push_back(word2[j++]);
        }

        return ans;
    }
};