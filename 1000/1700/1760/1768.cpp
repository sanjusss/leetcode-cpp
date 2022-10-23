/*
 * @Author: sanjusss
 * @Date: 2022-10-23 09:32:32
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-10-23 09:33:53
 * @FilePath: \1000\1700\1760\1768.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = 0;
        for (int i = 0; i < word1.size() || i < word2.size(); ++i) {
            if (i < word1.size()) {
                ans.push_back(word1[i]);
            }

            if (i < word2.size()) {
                ans.push_back(word2[i]);
            }
        }

        return ans;
    }
};