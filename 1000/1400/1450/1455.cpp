/*
 * @Author: sanjusss
 * @Date: 2022-08-22 09:24:23
 * @LastEditors: sanjusss
 * @LastEditTime: 2022-08-22 09:28:24
 * @FilePath: \1000\1400\1450\1455.cpp
 */
#include "leetcode.h"

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordCnt = 1;
        int searchI = 0;
        for (char i : sentence) {
            if (i == ' ') {
                ++wordCnt;
                searchI = 0;
                continue;
            }
            else if (searchI < 0) {
                continue;
            }

            if (searchWord[searchI] != i) {
                searchI = -1;
                continue;
            }

            if (++searchI == searchWord.size()) {
                return wordCnt;
            }
        }

        return -1;
    }
};