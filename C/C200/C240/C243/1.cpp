/*
 * @Author: sanjusss
 * @Date: 2021-05-30 10:29:13
 * @LastEditors: sanjusss
 * @LastEditTime: 2021-05-30 10:32:52
 * @FilePath: \C\C200\C240\C243\1.cpp
 */
#include "leetcode.h"

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return toInt(firstWord) + toInt(secondWord) == toInt(targetWord);
    }

private:
    int toInt(string& s) {
        int r = 0;
        for (char i : s) {
            r = r * 10 + i - 'a';
        }

        return r;
    }
};