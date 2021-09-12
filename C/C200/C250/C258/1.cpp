/*
 * @Author: sanjusss
 * @Date: 2021-09-12 10:29:58
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-09-12 10:32:04
 * @FilePath: \C\C200\C250\C258\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == ch) {
                reverse(word.begin(), word.begin() + i + 1);
                break;
            }
        }

        return word;
    }
};